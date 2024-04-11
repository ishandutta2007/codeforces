#include<stdio.h>
#include<iostream>
using namespace std;
int work(int x,int y,int l,int r,int k)
{
	int m=1<<k;
	if(l>r||x>y)
		return 0;
	if(l<x||l==x&&r>y)
		return work(l,r,x,y,k);
	if(y>=r)
		return r-l+1;
	if(l>m)
		return work(x,y,l-m,r-m,k);
	if(y<m&&r<m)
		return work(x,y,l,r,k-1);
	return max(max(work(x,y,l,m-1,k),work(1,r-m,x,y,k)),y-l+1);
}
int main()
{
	int x,y,l,r;
	scanf("%d %d %d %d",&x,&y,&l,&r);
	printf("%d",work(x,y,l,r,30));
	return 0;
}