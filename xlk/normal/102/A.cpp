#include<stdio.h>
#include<iostream>
using namespace std;
int v[120][120];
int a[120];
int n,m,x,y,z;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<m;i++)
		scanf("%d %d",&x,&y),v[x-1][y-1]=v[y-1][x-1]=1;
	z=1<<30;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if(v[i][j]&&v[j][k]&&v[k][i])
					z=min(z,a[i]+a[j]+a[k]);
	printf("%d",z>1<<29?-1:z);
	return 0;
}