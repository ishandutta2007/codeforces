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
int a[60][60],b[60][60],c[60],p;
int x[2520],y[2520];
int n,zc;
int z[2520][4];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",c+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<c[i];j++)
		{
			scanf("%d",a[i]+j);
			b[i][j]=++p;
			x[p]=i,y[p]=j;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<c[i];j++)
		{
			while(a[i][j]!=b[i][j])
			{
				z[zc][0]=i;
				z[zc][1]=j;
				z[zc][2]=x[a[i][j]];
				z[zc][3]=y[a[i][j]];
				swap(a[i][j],a[x[a[i][j]]][y[a[i][j]]]);
				zc++;
			}
		}
	printf("%d\n",zc);
	for(int i=0;i<zc;i++)
		printf("%d %d %d %d\n",z[i][0]+1,z[i][1]+1,z[i][2]+1,z[i][3]+1);
	return 0;
}