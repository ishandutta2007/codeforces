#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 600005
int a[N],b[N],n,K,t[N+N],L;
/*
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int c[N*4],v[N*4];
	void build(int u,int l,int r)
	{
		c[u]=v[u]=0;
		if(l==r) return ;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void pushup(int u,int l,int r)
	{
		if(c[u]>0) v[u]=t[r+1]-t[l];
		else if(l!=r) v[u]=v[ls]+v[rs];
		else v[u]=0;
	}
	void update(int u,int l,int r,int L,int R,int va)
	{
		if(L<=l&&r<=R)
		{
			c[u]+=va;
			pushup(u,l,r);
			// printf("*** %d %d %d %d %d\n",u,l,r,c[u],v[u]);
			return ;
		}
		if(mid>=L) update(ls,l,mid,L,R,va);
		if(mid<R) update(rs,mid+1,r,L,R,va);
		pushup(u,l,r);
		// printf("*** %d %d %d %d %d\n",u,l,r,c[u],v[u]);
	}
	inline int query(){return v[1];}
	#undef ls
	#undef rs
	#undef mid
}smt;
int chk(int mid)
{
	smt.build(1,1,L);
	int sum=0,l=0;
	for(int i=1;i<=n;i++)
	{
		smt.update(1,1,L,a[i],b[i],1);
		while(l<i&&smt.query()>=mid)
		{
			l++; smt.update(1,1,L,a[l],b[l],-1);
		}
		sum+=l;
	}
	return sum;
}
*/
struct Node
{
	int l,r;
	int id;
	Node(int a=0,int b=0,int c=0):l(a),r(b),id(c){};
	bool operator < (const Node &x) const {return l<x.l;}
};
set<Node> s;
int Cnt=0;
struct BIT
{
	int len,t[N];
	void init(int l){len=l,memset(t,0,sizeof(t));}
	inline int lowbit(int x){return x&(-x);}
	void update(int u,int v){Cnt++; if(!u) return ;for(int i=u;i<=len;i+=lowbit(i)) t[i]+=v;}
	int query(int u)
	{
		int ans=0;
		for(int i=u;i>0;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
}t1,t2;
auto split(int pos)
{
	auto it=s.upper_bound(Node(pos,0,0));
	assert(it!=s.begin());
	it--;
	if((*it).l==pos) return it;
	auto [l,r,id]=*it;
	s.erase(it);
	s.insert(Node(l,pos-1,id));
	return s.insert(Node(pos,r,id)).fir;
}
vector<pii> opt;
int siz[N];
void assign(int l,int r,int id)
{
	auto R=split(r+1),L=split(l);
	for(auto it=L;it!=R;++it)
	{
		auto [l,r,id]=*it;
		// printf("- %d %d %d\n",l,r,id);
		opt.eb(id,t[l]-t[r+1]);
//		t1.update(id,id*(t[l]-t[r+1]));
//		t2.update(id,t[l]-t[r+1]);
	}
	s.erase(L,R);
	s.insert(Node(l,r,id));
	// printf("+ %d %d %d\n",l,r,id);
	opt.eb(id,t[r+1]-t[l]);
//	t1.update(id,id*(t[r+1]-t[l]));
//	t2.update(id,t[r+1]-t[l]);
}
inline int Query(int i,int l)
{
	return t2.query(i)-t2.query(l);
}
void init()
{
	s.clear();
	s.insert(Node(1,L-1,0));
	for(int i=1;i<=n;i++)
	{
		assign(a[i],b[i],i);
		siz[i]=opt.size();
	}
}
int chk(int mid)
{
//	cout<<mid<<"--\n";
//	s.clear();
//	s.insert(Node(1,L-1,0));
	t1.init(n),t2.init(n);
	int sum=0,l=0;
	for(int i=1;i<=n;i++)
	{
//		assign(a[i],b[i],i);
		for(int j=siz[i-1];j<siz[i];j++)
		{
//			printf("%lld %lld\n",opt[j].fir,opt[j].sec);
			t1.update(opt[j].fir,opt[j].fir*opt[j].sec);
			t2.update(opt[j].fir,opt[j].sec);
		}
		while(l<i&&Query(i,l)>=mid) l++;
//		printf("%lld %lld %lld\n",i,l,Query(i,l));
		sum+=l;
	}
//	cout<<sum<<endl;
//	cout<<Cnt<<endl;
	return sum;
}
int calc(int mid)
{
	// cout<<mid<<"--\n";
	t1.init(n),t2.init(n);
	int sum=0,l=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=siz[i-1];j<siz[i];j++)
		{
//			printf("%lld %lld\n",opt[j].fir,opt[j].sec);
			t1.update(opt[j].fir,opt[j].fir*opt[j].sec);
			t2.update(opt[j].fir,opt[j].sec);
		}
		while(l<i&&Query(i,l)>=mid) l++;
		int A=t1.query(l),B=(t2.query(i)-t2.query(l))*l;
		sum+=A+B;
		// printf("%d %d\n",A,B);
	} 
	return sum;
}
/*
int calc(int mid)
{
	// cout<<mid<<"--\n";
	s.clear();
	s.insert(Node(1,L-1,0));
	t1.init(n),t2.init(n);
	smt.build(1,1,L);
	int sum=0,l=0;
	for(int i=1;i<=n;i++)
	{
		smt.update(1,1,L,a[i],b[i],1);
		assign(a[i],b[i],i);
		while(l<i&&smt.query()>=mid)
		{
			l++; smt.update(1,1,L,a[l],b[l],-1);
			// printf("++ %d %d %d\n",l,i,smt.query());
		}
		// printf("%d %d %d\n",l,i,smt.query());
		int A=t1.query(l),B=(t2.query(i)-t2.query(l))*l;
		sum+=A+B;
	}
	return sum;
}
*/
signed main()
{
	cin>>n>>K;
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=read(),t[i]=a[i],t[i+n]=b[i];
	sort(t+1,t+n+n+1);
	L=unique(t+1,t+n+n+1)-t-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(t+1,t+L+1,a[i])-t;
	for(int i=1;i<=n;i++) b[i]=lower_bound(t+1,t+L+1,b[i])-t-1;
	// for(int i=1;i<=n;i++) printf("%d %d\n",a[i],b[i]);
	init();
	int _l=1,_r=inf,_ans,_re;
	while(_l<=_r)
	{
		int mid=(_l+_r)/2;
		int X=chk(mid);
		if(X>=K) _l=mid+1,_ans=mid,_re=X;
		else _r=mid-1;
	}
//	cout<<_ans<<endl;
	cout<<calc(_ans)-(_re-K)*_ans<<endl;
	return 0;
}