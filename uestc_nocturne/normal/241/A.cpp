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
const int V=1200;
int n,K,d[V],c[V];
int main()
{
	while(~scanf("%d%d",&n,&K))
	{
		for(int i=0;i<n;i++)scanf("%d",&d[i]);
		for(int i=0;i<n;i++)scanf("%d",&c[i]);
		int ret=0,ma=c[0],now=0;
		for(int i=0;i<n;i++)
		{
		    now+=c[i];
			if(now<d[i])
			{
				int nd=(d[i]-now)/ma;
				now+=nd*ma;
				if(now<d[i])now+=ma,nd++;
				ret+=nd*K;
			}
			now-=d[i];
			ret+=d[i];
			ma=max(ma,c[i+1]);
		}
		printf("%d\n",ret);
	}
}