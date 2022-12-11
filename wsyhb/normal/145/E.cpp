#include<bits/stdc++.h>
using namespace std;
int n,m;
const int max_n=1e6+5;
char s[max_n];
namespace SegTree
{
	struct Node
	{
		int cnt0,cnt1,mx,mn;
		bool lazy;
	}node[max_n<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	#define cnt0(p) node[p].cnt0
	#define cnt1(p) node[p].cnt1
	#define mx(p) node[p].mx
	#define mn(p) node[p].mn
	#define lazy(p) node[p].lazy
	inline void push_up(int p)
	{
		cnt0(p)=cnt0(ls(p))+cnt0(rs(p));
		cnt1(p)=cnt1(ls(p))+cnt1(rs(p));
		mx(p)=max(mx(ls(p)),cnt0(ls(p))-cnt1(ls(p))+mx(rs(p)));
		mn(p)=min(mn(ls(p)),cnt0(ls(p))-cnt1(ls(p))+mn(rs(p)));
	}
	void build(int p,int l,int r)
	{
		if(l==r)
		{
			cnt0(p)=s[l]=='4';
			cnt1(p)=s[l]=='7';
			mx(p)=cnt0(p)-cnt1(p);
			mn(p)=cnt0(p)-cnt1(p);
			return;
		}
		int mid=(l+r)>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		push_up(p);
	}
	inline void update(int p)
	{
		swap(cnt0(p),cnt1(p));
		mx(p)=-mx(p),mn(p)=-mn(p);
		swap(mx(p),mn(p));
		lazy(p)=!lazy(p);
	}
	inline void push_down(int p)
	{
		update(ls(p));
		update(rs(p));
		lazy(p)=false;
	}
	void modify(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			update(p);
			return;
		}
		if(lazy(p))
			push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			modify(ls(p),l,mid,a,b);
		if(b>mid)
			modify(rs(p),mid+1,r,a,b);
		push_up(p);			
	}
	int res;
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res+=cnt0(p)-cnt1(p);
			return;
		}
		if(lazy(p))
			push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			query(ls(p),l,mid,a,b);
		if(b>mid)
			query(rs(p),mid+1,r,a,b);
	}
	int now;
	void query_max(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res=max(res,now+mx(p));
			now+=cnt0(p)-cnt1(p);
			return;
		}
		if(lazy(p))
			push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			query_max(ls(p),l,mid,a,b);
		if(b>mid)
			query_max(rs(p),mid+1,r,a,b);
	}
	void query_cnt0(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res+=cnt0(p);
			return;
		}
		if(lazy(p))
			push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			query_max(ls(p),l,mid,a,b);
		if(b>mid)
			query_max(rs(p),mid+1,r,a,b);
	}
	void query_cnt1(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res+=cnt1(p);
			return;
		}
		if(lazy(p))
			push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			query_max(ls(p),l,mid,a,b);
		if(b>mid)
			query_max(rs(p),mid+1,r,a,b);
	}
	inline int query(int l,int r)
	{
		res=0;
		if(l>1)
			query(1,1,n,1,l-1);
		now=res,res=0;
		query_max(1,1,n,l,r);
		int Res=res;
		res=0;
		if(l>1)
			query_cnt0(1,1,n,1,l-1);
		res=-res;
		query_cnt1(1,1,n,1,r);
		return Res+res;
	}
}
int main()
{
	int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	SegTree::build(1,1,n);
	while(m--)
	{
		char op[10];
		scanf("%s",op);
		if(op[0]=='s')
		{
			int l,r;
			scanf("%d%d",&l,&r);
			SegTree::modify(1,1,n,l,r);
		}
		else
			printf("%d\n",SegTree::query(1,n));
	}
	return 0;
}