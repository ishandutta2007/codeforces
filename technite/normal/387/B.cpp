#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,count=0;
	cin>>n>>m;
	int A[n],B[m];
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<m;i++) cin>>B[i];
	for(int i=0;i<n;i++)
	{
		int t=0;
		for(int j=0;j<m;j++)
		{
			if(B[j]>=A[i])
			{
				B[j]=0;
				t=1;
				break;
			}
		}
		if(t==0) count++;
	}	
	cout<<count;
}