#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define N 4020
using namespace std;
int n,x[N],y[N],a[N],g[N][N],f[N][N],s[N][N],t;
vector<int>w[N];
int Q(int x)
{
	return upper_bound(a,a+t,x)-a;
}
int F(int l,int r)
{
	if(~f[l][r])
		return f[l][r];
	if(l>r)
		return f[l][r]=0;
	f[l][r]=F(l+1,r);
	for(int i:w[l])
		if(y[i]<r&&F(l,y[i])+F(y[i],r)>f[l][r])
			f[l][r]=f[l][y[i]]+f[y[i]][r],s[l][r]=y[i];
	return f[l][r]+=!!g[l][r];
}
void P(int l,int r)
{
	if(l>r)
		return;
	if(s[l][r])
	{
		P(l,s[l][r]);
		P(s[l][r],r);
	}
	else
		P(l+1,r);
	if(g[l][r])
		printf("%d ",g[l][r]);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int d,r;
		scanf("%d%d",&d,&r);
		a[t++]=x[i]=d-r;                                  
		a[t++]=y[i]=d+r;
	}
	sort(a,a+t),t=unique(a,a+t)-a;
	for(int i=0;i<n;i++)
	{
		x[i]=Q(x[i]),y[i]=Q(y[i]);
		g[x[i]][y[i]]=i+1;
		w[x[i]].push_back(i);
	}
	memset(f,-1,sizeof(f));
	printf("%d\n",F(1,t));
	P(1,t);
}