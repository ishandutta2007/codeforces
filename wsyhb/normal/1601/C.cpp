#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
const int max_m=1e6+5;
int a[max_n],b[max_m],c[max_n+max_m];
namespace SegTree
{
	struct Node
	{
		int val,lazy,id;
	}node[max_n<<2];
	#define val(p) node[p].val
	#define id(p) node[p].id
	#define lazy(p) node[p].lazy
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	void build(int p,int l,int r)
	{
		val(p)=0;
		id(p)=l;
		lazy(p)=0;
		if(l<r)
		{
			int mid=(l+r)>>1;
			build(ls(p),l,mid);
			build(rs(p),mid+1,r);
		}
	}
	inline void push_down(int p)
	{
		val(ls(p))+=lazy(p);
		val(rs(p))+=lazy(p);
		lazy(ls(p))+=lazy(p);
		lazy(rs(p))+=lazy(p);
		lazy(p)=0;
	}
	inline void push_up(int p)
	{
		val(p)=min(val(ls(p)),val(rs(p)));
		if(val(ls(p))==val(p))
			id(p)=id(ls(p));
		else
			id(p)=id(rs(p));
	}
	void modify(int p,int l,int r,int a,int b,int v)
	{
		if(a<=l&&r<=b)
		{
			val(p)+=v;
			lazy(p)+=v;
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
	int res,res_id;
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			if(val(p)<res)
			{
				res=val(p);
				res_id=id(p);
			}
			return;
		}
		int mid=(l+r)>>1;
		if(a<=mid)
			query(ls(p),l,mid,a,b);
		if(b>mid)
			query(rs(p),mid+1,r,a,b);
	}
}
vector<int> pos[max_n+max_m];
int R;
namespace BIT
{
	int val[max_n+max_m];
	inline void init()
	{
		for(int i=1;i<=R;++i)
			val[i]=0;
	}
	inline void modify(int k,int v)
	{
		for(int i=k;i<=R;i+=i&(-i))
			val[i]+=v;
	}
	inline int query(int k)
	{
		int res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=val[i];
		return res;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			c[i]=a[i];
		}
		for(int i=1;i<=m;++i)
		{
			scanf("%d",b+i);
			c[n+i]=b[i];
		}
		sort(b+1,b+m+1);
		sort(c+1,c+(n+m)+1);
		R=unique(c+1,c+(n+m)+1)-c-1;
		for(int i=1;i<=n;++i)
			a[i]=lower_bound(c+1,c+R+1,a[i])-c;
		for(int i=1;i<=m;++i)
			b[i]=lower_bound(c+1,c+R+1,b[i])-c;
		for(int i=1;i<=R;++i)
			pos[i].clear();
		for(int i=1;i<=n;++i)
			pos[a[i]].push_back(i);
		SegTree::build(1,1,n+1);
		for(int i=1;i<b[1];++i)
			for(int j=0;j<int(pos[i].size());++j)
			{
				int x=pos[i][j];
				SegTree::modify(1,1,n+1,1,x,1);
			}
		for(int i=b[1];i<=R;++i)
			for(int j=0;j<int(pos[i].size());++j)
			{
				int x=pos[i][j];
				SegTree::modify(1,1,n+1,x+1,n+1,1);
			}
		int now=b[1];
		long long ans=0;
		for(int i=1;i<=m;++i)
		{
			while(now<b[i])
			{
				for(int j=0;j<int(pos[now].size());++j)
				{
					int x=pos[now][j];
					SegTree::modify(1,1,n+1,x+1,n+1,-1);
					SegTree::modify(1,1,n+1,1,x,1);
				}
				++now;
			}
			for(int j=0;j<int(pos[b[i]].size());++j)
			{
				int x=pos[b[i]][j];
				SegTree::modify(1,1,n+1,x+1,n+1,-1);
			}
			SegTree::res=1e9;
			SegTree::query(1,1,n+1,1,n+1);
			int k=i+1;
			while(k<=m&&b[k]==b[i])
				++k;
			ans+=1ll*(k-i)*SegTree::res;
			for(int j=0;j<int(pos[b[i]].size());++j)
			{
				int x=pos[b[i]][j];
				SegTree::modify(1,1,n+1,x+1,n+1,1);
			}
			i=k-1;
		}
		BIT::init();
		for(int i=n;i>=1;--i)
		{
			ans+=BIT::query(a[i]-1);
			BIT::modify(a[i],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}