//l1 
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
#define N 400001
#define lc no<<1
#define rc no<<1|1
#define getmid int mid=(L[no]+R[no])>>1
#include<cmath>
#define eps 0.000000001
int L[N],R[N],n,q;
double p[N];
int x,y,u,ty;
struct fire_dancer{
	double fire,dance;
}xx[N];
double despacito,Timsei;
void pushup(int no)
{
	xx[no].fire=xx[lc].fire*xx[rc].fire+eps;
	xx[no].dance=xx[lc].dance+xx[lc].fire*xx[rc].dance+eps;
}
void build(int no,int l,int r)
{
	L[no]=l;R[no]=r;getmid;
	if(l==r)
	{
		double xxx,yyy;
		scanf("%lf %lf",&xxx,&yyy);
		p[mid]=xxx/yyy+eps;
		xx[no].fire=(1-p[mid])/p[mid]+eps;
		xx[no].dance=xx[no].fire+eps;
		return;
	}
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(no);
}
void change(int no,int num)
{
//	cout<<L[no]<<" "<<R[no]<<endl;
	if(L[no]==R[no])
	{
		double xxx,yyy;
		scanf("%lf %lf",&xxx,&yyy);
		double pp=xxx/yyy+eps;
		xx[no].fire=(1-pp)/pp+eps;
		xx[no].dance=xx[no].fire+eps;
		return;
	}
	getmid;
	if(num>mid) change(rc,num);
	else change(lc,num);
	pushup(no);
}
void query(int no,int l,int r)
{
	if(L[no]==l&&R[no]==r)
	{
		Timsei+=xx[no].dance*despacito+eps;
		despacito*=xx[no].fire+eps;
		return;
	}
	getmid;
	if(l>mid) query(rc,l,r);
	else if(r<=mid) query(lc,l,r);
	else
	{
		query(lc,l,mid);query(rc,mid+1,r);return ;
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	build(1,1,n);
	while(q--)
	{
		scanf("%d",&ty);
		if(ty==1)
		{
			scanf("%d",&u);
			change(1,u);
		}
		else
		{
			scanf("%d %d",&x,&y);
			despacito=1;Timsei=0;
			query(1,x,y);
			double ans=0;
			if(Timsei>=1e8);else ans=1.0/(1+Timsei);	
			printf("%.10lf\n",(ans));
		}
	}
}