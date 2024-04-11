#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int A[n],B[n];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		if(i>=2)
		{
			A[i]==A[i-1]+A[i-2]?B[i]=1:B[i]=0;
		}
	}
		int max1=0;
		int count =0;
		for(int i=2;i<n;i++)
		{
			if(B[i]==1) count++;
			else {
				max1=max(max1,count);
				count=0;
			}
		}
		max1=max(max1,count);
		max1=min(n,max1+2);

		cout<<max1;		
	
}