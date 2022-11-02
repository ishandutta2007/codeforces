/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
int a[V];
LL s[V],one;
int n,x,Q;
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		one=0;
		for(int i=n-1;i>=0;i--)
		one+=(LL)(n-1-i)*a[i];
		s[0]=0;
		for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i-1];
		scanf("%d",&Q);
		for(int j=0;j<Q;j++)
		{
			if(j)printf(" ");
			scanf("%d",&x);
			if(x==1){printf("%I64d",one);continue;}
			int last=n;
			LL ret=0;
			LL gs=1;
			for(int dp=0;;dp++,gs*=x)
			{
				if(last>=gs)
				{
					ret+=(s[last]-s[last-gs])*dp;
					last-=gs;
				}
				else
				{
					ret+=(s[last])*dp;
					break;
				}
			}
			printf("%I64d",ret);
		}puts("");
	}
}