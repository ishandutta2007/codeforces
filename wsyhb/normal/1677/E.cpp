//
#include<bits/stdc++.h>
using namespace std;
int n,q;
const int max_n=2e5+5;
int p[max_n],pos[max_n],Left[max_n],Right[max_n],st[max_n],tp;
vector<int> Div[max_n],id[max_n];
const int max_q=1e6+5;
int l[max_q],r[max_q];
long long ans[max_q];
typedef pair<int,int> P;
inline bool cmp(const P &a,const P &b)
{
	return a.first!=b.first?a.first>b.first:a.second<b.second;
}
struct Segment
{
	int L,R,v;
	inline Segment(int l,int r,int V)
	{
		L=l,R=r,v=V;
	}
};
vector<Segment> S[max_n];
inline void add(int a,int b,int c,int d)
{
//	fprintf(stderr,"a=%d b=%d c=%d d=%d\n",a,b,c,d);
	assert(a<=b&&c<=d);
	S[a].push_back(Segment(c,d,1));
	S[b+1].push_back(Segment(c,d,-1));
}
struct SegTree
{
	struct Node
	{
		long long sum,lazy;
	}node[max_n<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	#define sum(p) node[p].sum
	#define lazy(p) node[p].lazy
	inline void push_down(int p,int l,int r,int mid)
	{
		long long v=lazy(p);
		lazy(p)=0;
		sum(ls(p))+=v*(mid-l+1);
		lazy(ls(p))+=v;
		sum(rs(p))+=v*(r-mid);
		lazy(rs(p))+=v;
	}
	void add(int p,int l,int r,int a,int b,int v)
	{
		if(a<=l&&r<=b)
		{
			sum(p)+=(r-l+1ll)*v;
			lazy(p)+=v;
			return;
		}
		int mid=(l+r)>>1;
		if(lazy(p))
			push_down(p,l,r,mid);
		if(a<=mid)
			add(ls(p),l,mid,a,b,v);
		if(b>mid)
			add(rs(p),mid+1,r,a,b,v);
		sum(p)=sum(ls(p))+sum(rs(p));
	}
	long long res;
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res+=sum(p);
			return;
		}
		int mid=(l+r)>>1;
		if(lazy(p))
			push_down(p,l,r,mid);
		if(a<=mid)
			query(ls(p),l,mid,a,b);
		if(b>mid)
			query(rs(p),mid+1,r,a,b);
	}
	inline long long query(int L,int R)
	{
		res=0;
		query(1,1,n,L,R);
		return res;
	}
}T1,T2;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",p+i);
		pos[p[i]]=i;
	}
	for(int i=1;i*i+i<=n;++i)
		for(int j=i*i+i;j<=n;j+=i)
			Div[j].push_back(i);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",l+i,r+i);
		id[l[i]-1].push_back(i);
		id[r[i]].push_back(i);
	}
	for(int i=1;i<=n;++i)
	{
		while(tp>0&&p[st[tp]]<p[i])
			--tp;
		Left[i]=st[tp];
		st[++tp]=i;
	}
	tp=0,st[0]=n+1;
	for(int i=n;i>=1;--i)
	{
		while(tp>0&&p[st[tp]]<p[i])
			--tp;
		Right[i]=st[tp];
		st[++tp]=i;
	}
	for(int i=1;i<=n;++i)
	{
		int v=p[i],L=Left[i]+1,R=Right[i]-1;
		vector<P> lim;
		for(int k=0;k<int(Div[v].size());++k)
		{
			int d=Div[v][k];
			int x=pos[d],y=pos[v/d];
			int L_lim=min(min(x,y),i);
			int R_lim=max(max(x,y),i);
			if(L_lim<L||R_lim>R)
				continue;
			lim.push_back(P(L_lim,R_lim));
		}
		sort(lim.begin(),lim.end(),cmp);
		int now=R+1;
//		fprintf(stderr,"i=%d\n",i);
		for(int k=0;k<int(lim.size());++k)
		{
			int l=lim[k].first,r=lim[k].second;
			if(r<now)
			{
				add(L,l,r,now-1);
				now=r;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(vector<Segment>::iterator it=S[i].begin();it!=S[i].end();++it)
		{
			T1.add(1,1,n,it->L,it->R,it->v);
			T2.add(1,1,n,it->L,it->R,-(i-1)*(it->v));
		}
		for(int k=0;k<int(id[i].size());++k)
		{
			int x=id[i][k];
			ans[x]+=(i==l[x]-1?-1:1)*(i*T1.query(l[x],r[x])+T2.query(l[x],r[x]));
		}
	}
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
	return 0;
}