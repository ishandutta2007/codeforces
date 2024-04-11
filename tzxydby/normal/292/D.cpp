#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
using namespace std;
const int N=505,M=10005;
int n,m,k,x,y,sum;
int a[M],b[M],f[N];
int find(int x)
{
	if(x==f[x])
		return x;
	return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i],&b[i]);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++)
			f[i]=i;
		sum=n;
		for(int i=1;i<x;i++)
		{
			if(find(a[i])!=find(b[i]))
			{
				f[f[a[i]]]=f[b[i]];
				sum--;
			}
		}
		for(int i=y+1;i<=m;i++)
		{
			if(find(a[i])!=find(b[i]))
			{
				f[f[a[i]]]=f[b[i]];
				sum--;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}