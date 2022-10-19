#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<new>
#include<queue>
using namespace std;
#define N 500001
#define M 8
int L[N],R[N],val[N][M],lazy[N][M],n,m,k;
int l,r;
bool flag=0;
int xx[M];
int a[N][M];
void build(int no,int l,int r)
{
	L[no]=l;R[no]=r;
	if(l==r) 
	{
		for(int i=1;i<=m;i++)
		val[no][i]=a[l][i];
		return;
	}
	int mid=(l+r)>>1;
	build(no*2,l,mid);
	build(no*2+1,mid+1,r);
	for(int i=1;i<=m;i++)
	{
		val[no][i]=max(val[no*2][i],val[no*2+1][i]);
	}
	return;
}
int query(int ty,int no,int l,int r)
{
	if(L[no]==l&&R[no]==r) return val[no][ty];
	int mid=(L[no]+R[no])>>1;
	if(l>mid) return query(ty,no*2+1,l,r);
	if(r<=mid) return query(ty,no*2,l,r);
	return max(query(ty,no*2,l,mid),query(ty,no*2+1,mid+1,r));
}
int ans[M];
bool pan(int x)
{
	if(x==0) return 1;
	for(int b=1;b<=n-x+1;b++)
	{
		memset(xx,0,sizeof(xx));
		int sum=0;
		for(int i=1;i<=m;i++)
		{
			xx[i]=query(i,1,b,b+x-1);
			sum+=xx[i];
		}
		if(sum<=k) 
		{
			for(int i=1;i<=m;i++)
			ans[i]=xx[i];
			return 1;
		}	
	}
	return 0;
}
void print()
{
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
int main()
{
	cin>>n>>m>>k;
	l=0;r=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cin>>a[i][j];
	}
	build(1,1,n);
	while(l<=r)// 
	{
		int mid=(l+r)>>1;
		if(pan(mid))
		{
			l=mid+1;
		}
		else r=mid-1;
	}
	print();
}