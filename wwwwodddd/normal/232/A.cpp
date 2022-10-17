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
int n,s;
int z[105],zc;
int y[105],yc;
int w[1005][1005];
int a[1005];
int b[1005];
int main()
{
	for(int i=0;i<100;i++)
		a[i]=i*(i-1)*(i-2)/6;
	for(int i=0;i<100;i++)
		b[i]=i*(i-1)/2;
	scanf("%d",&n);
	int d=upper_bound(a,a+100,n)-a-1;
	n-=a[d];
	z[zc++]=d;
	while(n)
	{
		int e=upper_bound(b,b+100,n)-b-1;
		n-=b[e];
		y[yc++]=e;
	}
	for(int i=0;i<zc;i++)
	{
		for(int j=0;j<z[i];j++)
			for(int k=0;k<z[i];k++)
				w[s+j][s+k]=j!=k;
	s+=z[i];
	}
	for(int i=0;i<yc;i++)
	{
		for(int j=0;j<y[i];j++)
			w[s][j]=w[j][s]=1;
		s++;
	}
	printf("%d\n",s);
	fr(i,s)
	{
		fr(j,s)	
			printf("%d",w[i][j]);
		puts("");
	}
	return 0;
}