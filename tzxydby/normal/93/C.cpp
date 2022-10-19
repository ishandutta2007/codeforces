#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n,l,a[N],b[N],c[N],v[N];
void dfs(int x)
{
	if(v[x-1]==n)
	{
		printf("%d\n",x-1);
		for(int i=1;i<x;i++)
		{
			if(a[i]+1) printf("lea e%cx, [e%cx + %d*e%cx]\n",'a'+i,'a'+a[i],b[i],'a'+c[i]);
			else printf("lea e%cx, [%d*e%cx]\n",'a'+i,b[i],'a'+c[i]);
		}
		exit(0);
	}
	if(x==l)
		return;
	for(int i=-1;i<x;i++)
	{
		for(int j=1;j<=8;j<<=1)
		{
			for(int k=0;k<x;k++)
			{
				if(i+1) v[x]=v[i]+j*v[k];
				else v[x]=j*v[k];
				if(v[x]>n||v[x]<=v[x-1])
					continue;
				a[x]=i,b[x]=j,c[x]=k;
				dfs(x+1);
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	v[0]=1;
	while(1)
	{
		l++;
		dfs(1);
	}
	return 0;
}