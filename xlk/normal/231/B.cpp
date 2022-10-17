#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=110;
int n,d,l,a[maxn];
int work(int w,int d)
{
	for(int i=1;i<=n;i++)
		if(i%2==w)
		{
			a[i]+=min(d,l-1);
			d-=min(d,l-1);
		}
	return d;
}
int main()
{
	scanf("%d%d%d",&n,&d,&l);
	for(int i=1;i<=n;i++)
		a[i]=1;
	d=d-n%2;
	if(d>0)
		d=work(1,d);
	if(d<0)
		d=work(0,-d);
	if(d!=0)
		puts("-1");
	else
		for(int i=1;i<=n;++i)
			printf("%d ",a[i]);
	return 0;
}