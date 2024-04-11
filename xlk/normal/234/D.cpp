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
int n,m,k,d,x;
int a[120];
int mn[120];
int mx[120];
int c[3];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&m,&k);
	for(int i=0;i<k;i++)
		scanf("%d",&x),a[x]++;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%*s");
		c[0]=c[1]=c[2]=0;
		scanf("%d",&d);
		for(int j=0;j<d;j++)
		{
			scanf("%d",&x);
			if(!x)
				c[2]++;
			else
				c[a[x]]++;
		}
		mn[i]=c[1]+max(c[2]-(m-k-c[0]),0);
		mx[i]=c[1]+min(k-c[1],c[2]);
	}
	for(int i=0;i<n;i++)
	{
		int tmx=mx[i];
		int tmn=mn[i];
		mx[i]=0;
		mn[i]=0;
		int nn=*max_element(mn,mn+n);
		int xx=*max_element(mx,mx+n);
		if(tmn>=xx)
			puts("0");
		else if(tmx<nn)
			puts("1");
		else
			puts("2");
		mx[i]=tmx;
		mn[i]=tmn;
	}
	return 0;
}