#include<bits/stdc++.h>
using namespace std;
int N;
const int max_N=3e5+5;
int p[max_N];
namespace RMQ
{
	int mx[19][max_N],mn[19][max_N],Log[max_N];
	inline void init()
	{
		Log[0]=-1;
		for(int i=1;i<=N;++i)
		{
			mx[0][i]=mn[0][i]=p[i];
			Log[i]=Log[i>>1]+1;
		}
		for(int i=1;i<=Log[N];++i)
			for(int j=1;j+(1<<i)-1<=N;++j)
			{
				mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
				mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
			}
	}
	inline int query_mx(int l,int r)
	{
		int k=Log[r-l+1];
		return max(mx[k][l],mx[k][r-(1<<k)+1]);
	}
	inline int query_mn(int l,int r)
	{
		int k=Log[r-l+1];
		return min(mn[k][l],mn[k][r-(1<<k)+1]);
	}
}
inline bool judge(int l,int r)
{
	return RMQ::query_mx(l,r)-RMQ::query_mn(l,r)==r-l;
}
namespace SegmentTree
{
	struct Node
	{
		int mn,lazy;
	}node[max_N<<2];
	#define mn(p) node[p].mn
	#define lazy(p) node[p].lazy
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	inline void push_down(int p)
	{
		int v=lazy(p);
		lazy(p)=0;
		mn(ls(p))+=v,lazy(ls(p))+=v;
		mn(rs(p))+=v,lazy(rs(p))+=v;
	}
	inline void push_up(int p)
	{
		mn(p)=min(mn(ls(p)),mn(rs(p)));
	}
	void update(int p,int l,int r,int a,int b,int v)
	{
		if(a<=l&&r<=b)
		{
			mn(p)+=v,lazy(p)+=v;
			return;
		}
		if(lazy(p))
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
		update(1,1,N,a,b,v);
	}
	int res;
	void query(int p,int l,int r)
	{
		if(l==r)
		{
			res=l;
			return;
		}
		if(lazy(p))
			push_down(p);
		int mid=(l+r)>>1;
		if(!mn(ls(p)))
			query(ls(p),l,mid);
		else
			query(rs(p),mid+1,r);
		push_up(p);
	}
	inline int query()
	{
		query(1,1,N);
		return res;
	}
}
int st1[max_N],st2[max_N],tp1,tp2;
const int max_cnt=6e5+5;
int st[max_cnt],tp,L[max_cnt],R[max_cnt],M[max_cnt],cnt;
bool typ[max_cnt];
int cnt_son[max_cnt];
inline void build()
{
	for(int i=1;i<=N;++i)
	{
		while(tp1&&p[i]<=p[st1[tp1]])
			SegmentTree::update(st1[tp1-1]+1,st1[tp1],p[st1[tp1]]),--tp1;
		while(tp2&&p[i]>=p[st2[tp2]])
			SegmentTree::update(st2[tp2-1]+1,st2[tp2],-p[st2[tp2]]),--tp2;
		SegmentTree::update(st1[tp1]+1,i,-p[i]);
		SegmentTree::update(st2[tp2]+1,i,p[i]);
		st1[++tp1]=st2[++tp2]=i;
		++cnt;
		L[cnt]=R[cnt]=i;
		int now=cnt,l=SegmentTree::query();
		while(tp&&L[st[tp]]>=l)
		{
			if(typ[st[tp]]&&judge(M[st[tp]],R[now]))
			{
				R[st[tp]]=R[now],M[st[tp]]=L[now];
				++cnt_son[st[tp]];
				now=st[tp--];
			}
			else if(judge(L[st[tp]],R[now]))
			{
				typ[++cnt]=true;
				cnt_son[cnt]+=2;
				L[cnt]=L[st[tp--]],R[cnt]=R[now],M[cnt]=L[now];
				now=cnt;
			}
			else
			{
				++cnt;
				do
					--tp;
				while(tp&&!judge(L[st[tp]],R[now]));
				L[cnt]=L[st[tp--]],R[cnt]=R[now];
				now=cnt;
			}
		}
		st[++tp]=now;
		SegmentTree::update(1,i,-1);
	}
}
inline long long C2(int x)
{
	return x*(x-1ll)>>1;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[x]=y;
	}
	RMQ::init();
	build();
	long long ans=0;
	for(int u=1;u<=cnt;++u)
		ans+=typ[u]?C2(cnt_son[u]):1;
	printf("%lld\n",ans);
	return 0;
}