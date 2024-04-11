/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=1000100;
struct S
{
	int s0,s1;
	int ma;
};
S Add(S x,S y)
{
	S ret;
	ret.s0=x.s0+y.s0;
	ret.s1=x.s1+y.s1;
	ret.ma=max(x.ma,y.ma);
	ret.ma=max(ret.ma,x.s0+y.ma);
	ret.ma=max(ret.ma,x.ma+y.s1);
	return ret;
}
struct Node
{
	int l,r;
	S ori,rev;
	int lazy;
}p[4*V];
char ch[V];
void init(int nu,int l,int r)
{
	p[nu].l=l;
	p[nu].r=r;
	p[nu].lazy=0;
	if(l==r)
	{
		p[nu].ori.s0=p[nu].rev.s0=0;
		p[nu].ori.s1=p[nu].rev.s1=0;
		p[nu].ori.ma=p[nu].rev.ma=1;
		if(ch[l]=='4')p[nu].ori.s0++,p[nu].rev.s1++;
		else p[nu].ori.s1++,p[nu].rev.s0++;
		return;
	}
	int mid=(l+r)/2;
	init(nu*2,l,mid);
	init(nu*2+1,mid+1,r);
	p[nu].ori=Add(p[nu*2].ori,p[nu*2+1].ori);
	p[nu].rev=Add(p[nu*2].rev,p[nu*2+1].rev);
}
void update(int nu,int l,int r,int lz)
{
//	printf("%d %d %d %d %d\n",nu,p[nu].l,p[nu].r,p[nu].lazy,lz);
	if(p[nu].l==l&&p[nu].r==r)
	{
		swap(p[nu].ori,p[nu].rev);
		p[nu].lazy^=1;
	//	printf("%d %d %d\n",nu,p[nu].ori.ma,p[nu].rev.ma);
		return;
	}
	if(p[nu].lazy==1)
	{
		p[nu].lazy=0;
		p[nu*2].lazy^=1;swap(p[nu*2].ori,p[nu*2].rev);
		p[nu*2+1].lazy^=1;swap(p[nu*2+1].ori,p[nu*2+1].rev);
	}
	int mid=(p[nu].l+p[nu].r)/2;
	if(r<=mid)update(nu*2,l,r,lz^p[nu].lazy);
	else if(l>mid)update(nu*2+1,l,r,lz^p[nu].lazy);
	else
	{
		update(nu*2,l,mid,lz^p[nu].lazy);
		update(nu*2+1,mid+1,r,lz^p[nu].lazy);
	}
	p[nu].ori=Add(p[nu*2].ori,p[nu*2+1].ori);
	p[nu].rev=Add(p[nu*2].rev,p[nu*2+1].rev);
//	printf("%d %d %d\n",nu,p[nu].ori.ma,p[nu].rev.ma);
}
char tmp[120];
int n,Q,x,y;
int main()
{
	while(~scanf("%d%d",&n,&Q))
	{
		scanf("%s",ch);
		init(1,0,n-1);
		while(Q--)
		{
			scanf("%s",tmp);
			if(tmp[0]=='c')
			{
				printf("%d\n",p[1].ori.ma);
			}
			else
			{
				scanf("%d%d",&x,&y);
				update(1,x-1,y-1,1);
			}
		}
	}
}