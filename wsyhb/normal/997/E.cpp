#include<bits/stdc++.h>
using namespace std;
int n,q;
const int max_n=12e4+5;
int p[max_n];
namespace SegmentTree
{
	struct Node
	{
		int val,lazy,cnt,lazy_c;
		long long res;
	}node[max_n<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	#define val(p) node[p].val
	#define lazy(p) node[p].lazy
	#define cnt(p) node[p].cnt
	#define lazy_c(p) node[p].lazy_c
	#define res(p) node[p].res
	void build(int p,int l,int r)
	{
		val(p)=l,cnt(p)=1;
		if(l<r)
		{
			int mid=(l+r)>>1;
			build(ls(p),l,mid);
			build(rs(p),mid+1,r);
		}
	}
	inline void add(int p,int v)
	{
		val(p)+=v,lazy(p)+=v;
	}
	inline void add_c(int p,int v)
	{
		res(p)+=1ll*cnt(p)*v,lazy_c(p)+=v;
	}
	inline void push_down(int p)
	{
		int ls=ls(p),rs=rs(p);
		if(lazy(p))
		{
			add(ls,lazy(p));
			add(rs,lazy(p));
			lazy(p)=0;
		}
		if(lazy_c(p))
		{
			if(val(ls)==val(p))
				add_c(ls,lazy_c(p));
			if(val(rs)==val(p))
				add_c(rs,lazy_c(p));
			lazy_c(p)=0;
		}
	}
	inline void push_up(int p)
	{
		int ls=ls(p),rs=rs(p);
		val(p)=min(val(ls),val(rs));
		cnt(p)=(val(ls)==val(p)?cnt(ls):0)+(val(rs)==val(p)?cnt(rs):0);
		res(p)=res(ls)+res(rs);
	}
	void update(int p,int l,int r,int a,int b,int v)
	{
		if(a<=l&&r<=b)
		{
			add(p,v);
			return;
		}
		push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			update(ls(p),l,mid,a,b,v);
		if(b>mid)
			update(rs(p),mid+1,r,a,b,v);
		push_up(p);
	}
	inline void update(int a,int b,int v)
	{
		update(1,1,n,a,b,v);
	}
	long long res;
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res+=res(p);
			return;
		}
		push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			query(ls(p),l,mid,a,b);
		if(b>mid)
			query(rs(p),mid+1,r,a,b);
	}
	inline long long query(int a,int b)
	{
		res=0;
		query(1,1,n,a,b);
		return res;
	}
}
int st1[max_n],st2[max_n],tp1,tp2;
const int max_q=12e4+5;
struct Query
{
	int l,r,id;
}query[max_q];
#define l(x) query[x].l
#define r(x) query[x].r
#define id(x) query[x].id
inline bool cmp(const Query &a,const Query &b)
{
	return a.r<b.r;
}
long long ans[max_q];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",p+i);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",&l(i),&r(i));
		id(i)=i;
	}
	sort(query+1,query+q+1,cmp);
	SegmentTree::build(1,1,n);
	for(int i=1,j=1;i<=n&&j<=q;++i)
	{
		SegmentTree::add(1,-1);
		while(tp1&&p[i]<=p[st1[tp1]])
			SegmentTree::update(st1[tp1-1]+1,st1[tp1],p[st1[tp1]]),--tp1;
		while(tp2&&p[i]>=p[st2[tp2]])
			SegmentTree::update(st2[tp2-1]+1,st2[tp2],-p[st2[tp2]]),--tp2;
		SegmentTree::update(st1[tp1]+1,i,-p[i]);
		SegmentTree::update(st2[tp2]+1,i,p[i]);
		st1[++tp1]=st2[++tp2]=i;
		SegmentTree::add_c(1,1);
		while(j<=q&&query[j].r==i)
		{
			ans[query[j].id]=SegmentTree::query(query[j].l,query[j].r);
			++j;
		}
	}
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
	return 0;
}