#include<bits/stdc++.h>
using namespace std;
const int R=2e5;
const int max_R=2e5+5;
namespace SegTree
{
	struct Node
	{
		long long s2,sum;
		int cnt,lazy;
		inline void upd(int d)
		{
			s2+=2ll*d*sum+1ll*d*d*cnt;
			sum+=1ll*d*cnt;
			lazy+=d;
		}
	}node[max_R<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	#define s2(p) node[p].s2
	#define sum(p) node[p].sum
	#define cnt(p) node[p].cnt
	#define lazy(p) node[p].lazy
	inline void push_down(int p)
	{
		int v=lazy(p);
		lazy(p)=0;
		node[ls(p)].upd(v);
		node[rs(p)].upd(v);
	}
	inline void push_up(int p)
	{
		s2(p)=s2(ls(p))+s2(rs(p));
		sum(p)=sum(ls(p))+sum(rs(p));
		cnt(p)=cnt(ls(p))+cnt(rs(p));
	}
	void modify(int p,int l,int r,int a,int b,int v)
	{
		if(a<=l&&r<=b)
		{
			node[p].upd(v);
			return;
		}
		if(lazy(p))
			push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			modify(ls(p),l,mid,a,b,v);
		if(b>mid)
			modify(rs(p),mid+1,r,a,b,v);
		push_up(p);
	}
	void del(int p,int l,int r,int k)
	{
		if(l==r)
		{
			s2(p)=sum(p)=0;
			cnt(p)=0;
			return;
		}
		if(lazy(p))
			push_down(p);
		int mid=(l+r)>>1;
		if(k<=mid)
			del(ls(p),l,mid,k);
		else
			del(rs(p),mid+1,r,k);
		push_up(p);
	}
	void add(int p,int l,int r,int k,int v)
	{
		if(l==r)
		{
			s2(p)=1ll*v*v;
			sum(p)=v;
			cnt(p)=1;
			return;
		}
		if(lazy(p))
			push_down(p);
		int mid=(l+r)>>1;
		if(k<=mid)
			add(ls(p),l,mid,k,v);
		else
			add(rs(p),mid+1,r,k,v);
		push_up(p);
	}
	int res;
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res+=cnt(p);
			return;
		}
		int mid=(l+r)>>1;
		if(a<=mid)
			query(ls(p),l,mid,a,b);
		if(b>mid)
			query(rs(p),mid+1,r,a,b);
	}
	inline int query(int a,int b)
	{
		res=0;
		query(1,1,R,a,b);
		return res;
	}
}
using namespace SegTree;
int main()
{
	int q,d;
	scanf("%d%d",&q,&d);
	for(int i=1;i<=q;++i)
	{
		int a;
		scanf("%d",&a);
		int cnt=query(a,a);
		if(cnt)
		{
			del(1,1,R,a);
			modify(1,1,R,max(a-d,1),a,-1);
		}
		else
		{
			add(1,1,R,a,a<R?query(a+1,min(a+d,R)):0);
			if(a>1)
				modify(1,1,R,max(a-d,1),a-1,1);
		}
		long long ans=s2(1)-sum(1);
		assert(ans%2==0);
		ans>>=1;
		printf("%lld\n",ans);
	}
	return 0;
}