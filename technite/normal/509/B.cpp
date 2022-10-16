#include<bits/stdc++.h>
using namespace std;
int getMin(int arr[], int n) 
{ 
    int res = arr[0]; 
    for (int i = 1; i < n; i++) 
        res = min(res, arr[i]); 
    return res; 
} 
  
int getMax(int arr[], int n) 
{ 
    int res = arr[0]; 
    for (int i = 1; i < n; i++) 
        res = max(res, arr[i]); 
    return res; 
} 
  
int main()
{
	int n,k;
	cin>>n>>k;
	int A[n];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	if(getMax(A,n)-getMin(A,n)>k)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<A[i];j++)
			{
				cout<<j%k+1<<" ";
			}
			cout<<endl;
		}
	}

}