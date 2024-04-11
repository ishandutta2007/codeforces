#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;cin>>m>>n;
	int a[m][n],b[m][n];
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)a[i][j]=1;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)cin>>b[i][j];
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		if(!b[i][j])
		{
			for(int k=0;k<m;k++)a[k][j]=0;
			for(int k=0;k<n;k++)a[i][k]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			bool count=0;
			for(int k=0;k<m;k++)count|=a[k][j];
			for(int k=0;k<n;k++)count|=a[i][k];
			if(b[i][j]==count);
			else {cout<<"NO"; return 0;
			}
		}
	}
	
	
	cout<<"YES"<<endl;
	for(int i=0;i<m;i++)
	{for(int j=0;j<n;j++)
	cout<<a[i][j]<<' ';
	cout<<endl;
	}
}