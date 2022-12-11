#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=100+5,mx1=400+5;
int a[mx],b[mx];
bool M[mx1];
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		M[a[i]]=true;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",b+i);
		M[b[i]]=true;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!M[a[i]+b[j]])
			{
				printf("%d %d\n",a[i],b[j]);
				return 0;
			}
	return 0;
}