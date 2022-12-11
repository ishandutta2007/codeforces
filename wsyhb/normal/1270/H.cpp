#include<bits/stdc++.h>
using namespace std;
const int R=1e6;
namespace SegTree
{
	const int max_R=1e6+5;
	struct Node
	{
		int mn,cnt,lazy;
	}node[max_R<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	#define mn(p) node[p].mn
	#define cnt(p) node[p].cnt
	#define lazy(p) node[p].lazy
	inline void push_down(int p)
	{
		int v=lazy(p);
		if(v)
		{
			mn(ls(p))+=v,lazy(ls(p))+=v;
			mn(rs(p))+=v,lazy(rs(p))+=v;
			lazy(p)=0;
		}
	}
	inline void push_up(int p)
	{
		mn(p)=min(mn(ls(p)),mn(rs(p)));
		cnt(p)=mn(ls(p))==mn(p)?cnt(ls(p)):0;
		cnt(p)+=mn(rs(p))==mn(p)?cnt(rs(p)):0;
	}
	void add(int p,int l,int r,int a,int b,int v)
	{
		if(a<=l&&r<=b)
		{
			mn(p)+=v,lazy(p)+=v;
			return;
		}
		push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			add(ls(p),l,mid,a,b,v);
		if(b>mid)
			add(rs(p),mid+1,r,a,b,v);
		push_up(p);
	}
	inline void add(int a,int b,int v)
	{
		assert(a!=b);
		if(a>b)
			swap(a,b);
		if(a+1<=R)
			add(1,1,R,a+1,b,v); // b may equal to R+1
	}
	void update(int p,int l,int r,int k,int v)
	{
		if(l==r)
		{
			cnt(p)+=v;
			return;
		}
		push_down(p);
		int mid=(l+r)>>1;
		if(k<=mid)
			update(ls(p),l,mid,k,v);
		else
			update(rs(p),mid+1,r,k,v);
		push_up(p);
	}
}
const int max_n=5e5+5;
int a[max_n];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	a[0]=R+1,a[n+1]=0;
	for(int i=0;i<=n;++i)
		SegTree::add(a[i],a[i+1],1);
	for(int i=1;i<=n;++i)
		SegTree::update(1,1,R,a[i],1);
	while(q--)
	{
		int pos,x;
		scanf("%d%d",&pos,&x);
		SegTree::add(a[pos-1],a[pos],-1);
		SegTree::add(a[pos],a[pos+1],-1);
		SegTree::update(1,1,R,a[pos],-1);
		a[pos]=x;
		SegTree::add(a[pos-1],a[pos],1);
		SegTree::add(a[pos],a[pos+1],1);
		SegTree::update(1,1,R,a[pos],1);
		assert(SegTree::mn(1)==1);
		printf("%d\n",SegTree::cnt(1));
	}
	return 0;
}