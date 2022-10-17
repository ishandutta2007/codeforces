#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int f[10020];
int d[10020];
int n,m,x;
int main()
{
	for(scanf("%d %d",&n,&m);n--;)
	{
		memset(d,0x3f,sizeof d);
		for(int i=0;i<m;i++)
			scanf("%1d",&x),!x?:d[i]=0;
		for(int i=0;i<2*m;i++)
			d[(i+1)%m]=min(d[(i+1)%m],d[i%m]+1);
		for(int i=2*m;i>0;i--)
			d[(i-1)%m]=min(d[(i-1)%m],d[i%m]+1);
		for(int i=0;i<m;i++)
			f[i]+=d[i];
		if(d[0]==0x3f3f3f3f)
			return puts("-1"),0;
	}
	printf("%d\n",*min_element(f,f+m));
	return 0;
}