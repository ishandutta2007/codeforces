#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int f[10020];
int a[10020];
int d[10020];
int n,m,kkk;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			d[j]=0xfffff;
		kkk=0;
		for(int j=0;j<m;j++)
		{
			scanf("%1d",a+j);
			if(a[j])
				d[j]=0,kkk=1;
		}
		if(!kkk)
		{
			puts("-1");
			return 0;
		}
		for(int i=0;i<m;i++)
			if(d[(i+1)%m]>d[i]+1)
				d[(i+1)%m]=d[i]+1;
		for(int i=0;i<m;i++)
			if(d[(i+1)%m]>d[i]+1)
				d[(i+1)%m]=d[i]+1;
		for(int i=m;i>0;i--)
			if(d[i-1]>d[i%m]+1)
				d[i-1]=d[i%m]+1;
		for(int i=m;i>0;i--)
			if(d[i-1]>d[i%m]+1)
				d[i-1]=d[i%m]+1;
		for(int j=0;j<m;j++)
			f[j]+=d[j];
	}
	printf("%d\n",*min_element(f,f+m));
	return 0;
}