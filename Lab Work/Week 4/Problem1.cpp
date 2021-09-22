#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
	if(low < high)
	{
		int part = partition(arr, low, high);
		quicksort(arr, low, part - 1);
		quicksort(arr, part + 1, high);
	}
}

int main()
{
	int T;
	cin >> T;
	int n, flag;

	while(T--)
	{
		cin >> n;
		int arr[n];
		flag = 0;

		for(int i = 0; i < n; i++)
			cin >> arr[i];

		quicksort(arr, 0, n-1);


		for(int j = 1; j < n; j++)
			if(arr[j] == arr[j-1]){
				flag = 1;
				break;
			}

		if(flag == 1)
			cout << "YES" << endl;

		cout << "NO" << endl;
	}
}
