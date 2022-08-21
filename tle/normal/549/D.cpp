#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,m,need=0;
char mmap[1000][1000];
int cur[1000][1000];
int bitt[1000][1000];
void add(int i,int j,int k)
{
	for(;j<=m+1;j+=j&-j) bitt[i][j]+=k;
}
int sum(int i,int j)
{
	int ans=0;
	for(;j>=1;j-=j&-j) ans+=bitt[i][j];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",&mmap[i][1]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cur[i][j]=mmap[n][m]!=mmap[i][j];
			add(i,j,cur[i][j]-cur[i][j-1]);
		}
	}
	for(int p=n+m;p>=1;p--)
	{
		for(int j=max(p-n,1);j<=m&&p-j>=1;j++)
		{
			int i=p-j,sm=sum(i,j);
			if(sm)
			{
				need++;
				for(int a=1;a<=i;a++)
				{
					add(a,1,-sm);
					add(a,j+1,sm);
				}
			}
		}
	}
	cout<<need+1;
}