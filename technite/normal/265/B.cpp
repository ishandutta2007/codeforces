#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int A[n];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		if(i==0)
		{
			sum+=A[i];
		}
		else
		{
			if(A[i]>=A[i-1])
			{
				sum+=1+A[i]-A[i-1];
			}
			else
			{
				sum+=A[i-1]-A[i]+1;
			}
		}
	}
	cout<<sum+n;

}