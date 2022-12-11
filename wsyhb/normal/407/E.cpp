#include<bits/stdc++.h>
using namespace std;
int n,k,d,m,res_l,res_len;
const int max_n=2e5+5;
int a[max_n],b[max_n],maxR[max_n];
namespace SegTree
{
	struct Node
	{
		int val,lazy;
	}node[max_n<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	#define val(p) node[p].val
	#define lazy(p) node[p].lazy
	inline void clear()
	{
		for(int i=1;i<=4*m;++i)
			val(i)=lazy(i)=0;
	}
	inline void push_down(int p)
	{
		int v=lazy(p);
		if(v)
		{
			val(ls(p))+=v,lazy(ls(p))+=v;
			val(rs(p))+=v,lazy(rs(p))+=v;
			lazy(p)=0;
		}
	}
	void update(int p,int l,int r,int a,int b,int v)
	{
		if(a<=l&&r<=b)
		{
			val(p)+=v,lazy(p)+=v;
			return;
		}
		push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			update(ls(p),l,mid,a,b,v);
		if(b>mid)
			update(rs(p),mid+1,r,a,b,v);
		val(p)=min(val(ls(p)),val(rs(p)));
	}
	int res;
	void query(int p,int l,int r,int a,int b,int v)
	{
		if(val(p)>v)
			return;
		if(l==r)
		{
			res=l;
			return;
		}
		push_down(p); 
		int mid=(l+r)>>1;
		if(b>mid)
			query(rs(p),mid+1,r,a,b,v);
		if(a<=mid&&res==-1)
			query(ls(p),l,mid,a,b,v);
	}
	inline int query(int a,int b,int v)
	{
		res=-1;
		query(1,1,m,a,b,v);
		return res;
	}
}
typedef pair<int,int> P;
P st_mn[max_n],st_mx[max_n];
int sz_mn,sz_mx;
inline void solve()
{
	map<int,bool> vis;
	for(int i=1,j=0;i<=m;++i)
	{
		if(i-1>0)
			vis[b[i-1]]=false;
		while(j+1<=m&&!vis[b[j+1]])
			vis[b[++j]]=true;
		maxR[i]=j;
	}
	SegTree::clear();
	sz_mn=sz_mx=0;
	st_mn[0].first=st_mx[0].first=m+1;
	for(int L=m;L>=1;--L)
	{
		while(sz_mn>0&&b[L]<b[st_mn[sz_mn].first])
		{
			SegTree::update(1,1,m,st_mn[sz_mn].first,st_mn[sz_mn].second,-(b[L]-b[st_mn[sz_mn].first]));
			--sz_mn;
		}
		st_mn[sz_mn+1]=P(L,st_mn[sz_mn].first-1);
		++sz_mn;
		while(sz_mx>0&&b[L]>b[st_mx[sz_mx].first])
		{
			SegTree::update(1,1,m,st_mx[sz_mx].first,st_mx[sz_mx].second,b[L]-b[st_mx[sz_mx].first]);
			--sz_mx;
		}
		st_mx[sz_mx+1]=P(L,st_mx[sz_mx].first-1);
		++sz_mx;
		if(L+1<=m)
			SegTree::update(1,1,m,L+1,m,-1);
		int res=SegTree::query(L,maxR[L],k);
//		fprintf(stderr,"L=%d res=%d\n",L,res);
		assert(res!=-1);
		if(res-L+1>=res_len)
		{
			res_len=res-L+1;
			res_l=L;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	if(d==0)
	{
		int ans=0,ansL=0;
		for(int i=1;i<=n;++i)
		{
			int j=i;
			while(j+1<=n&&a[j+1]==a[i])
				++j;
			if(j-i+1>ans)
			{
				ans=j-i+1;
				ansL=i;
			}
			i=j;
		}
		printf("%d %d\n",ansL,ansL+ans-1);
		return 0;
	}
	int ans_l=-1,ans_len=0;
	for(int i=1;i<=n;++i)
	{
		int j=i;
		while(j+1<=n&&(a[j+1]-a[i])%d==0)
			++j;
		m=j-i+1;
		for(int k=1;k<=m;++k)
			b[k]=a[i-1+k]>=0?a[i-1+k]/d:(a[i-1+k]-d+1)/d;
		res_l=-1,res_len=0;
//		fprintf(stderr,"i=%d j=%d\n",i,j);
		solve();
		if(res_len>ans_len)
		{
			ans_len=res_len;
			ans_l=res_l+i-1;
		}
		i=j;
	}
	assert(ans_l!=-1);
	printf("%d %d\n",ans_l,ans_l+ans_len-1);
	return 0;
}