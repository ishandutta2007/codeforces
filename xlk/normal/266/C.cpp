#include<stdio.h>
#include<iostream>
using namespace std;
int n,c[1020],r[1020],a[1020][1020],x,y,z;
int w[10020];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		c[--x]++,r[--y]++;
		a[x][y]=1;
	}
	for(int i=0;i<n;i++)
	{
		x=y=i;
		for(int j=i;j<n;j++)
			if(!c[j])
				x=j;
		for(int j=i;j<n;j++)
			if(r[j])
				y=j;
		for(int j=0;j<n;j++)
			swap(a[x][j],a[i][j]);
		for(int j=0;j<n;j++)
			swap(a[j][y],a[j][i]);
		swap(c[x],c[i]),swap(r[y],r[i]);
		for(int j=0;j<n;j++)
			if(a[j][i])
				c[j]--;
		if(x!=i)
			w[z++]=0,w[z++]=i,w[z++]=x;
		if(y!=i)
			w[z++]=1,w[z++]=i,w[z++]=y;
	}
	printf("%d\n",z/3);
	for(int i=0;i<z;i++)
	{
		if(i%3==0)
			puts("");
		printf("%d ",w[i]+1);
	}
}