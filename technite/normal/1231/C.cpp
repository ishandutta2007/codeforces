#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int min(int x,int y){
	return x<y?x:y;
}
int main()
{
	int n;
	int m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=m-1;j++)
			cin>>a[i][j];
	}
	int sum=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(a[i][j]==0)
				a[i][j]=min(a[i][j+1],a[i+1][j])-1;
			if((j>0)&&(i>0)&&(a[i][j]<=a[i][j-1]||a[i][j]<=a[i-1][j]))
				{

					cout<<-1;
					return 0;
				}
			else
				sum+=a[i][j];
		}
	}
	cout<<sum;			
}