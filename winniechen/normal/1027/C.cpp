#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
#define N 1000005
int num[N],n,T,a[N],t[5];multiset<int>s;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		double ans=1e10;s.clear();
		scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]),num[a[i]]++;
		for(int i=1;i<=n;i++)if(num[a[i]]>=2)num[a[i]]-=2,s.insert(a[i]);
		for(int i=1,x;i<=n;i++)
		{
			if(s.find(a[i])==s.end())continue;
			if(s.find(a[i])!=s.begin())
			{
				x=*(--s.find(a[i]));
				if(ans>(1.0*((x+a[i])*2)*((x+a[i])*2))/(1.0*x*a[i]))
				{
					ans=(1.0*((x+a[i])*2)*((x+a[i])*2))/(1.0*x*a[i]);
					t[1]=a[i],t[2]=a[i],t[3]=x,t[4]=x;
				}
			}
			if((++s.find(a[i]))!=s.end())
			{
				x=*(++s.find(a[i]));
				if(ans>(1.0*((x+a[i])*2)*((x+a[i])*2))/(1.0*x*a[i]))
				{
					ans=(1.0*((x+a[i])*2)*((x+a[i])*2))/(1.0*x*a[i]);
					t[1]=a[i],t[2]=a[i],t[3]=x,t[4]=x;
				}
			}
		}for(int i=1;i<=4;i++)printf("%d ",t[i]);puts("");
		for(int i=1;i<=n;i++)num[a[i]]=0;
	}
}