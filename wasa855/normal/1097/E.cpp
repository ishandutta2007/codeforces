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
#define ll long long
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
int n;
vector<int> ans[1005];
int Acnt=0;
int getf(int n)
{
	if(n==1) return 1;
	int l=0,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(1LL*mid*(mid+1)/2>n) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans-1;
}
struct Node
{
	int val,pos;
	Node(int A=0,int B=0){val=A,pos=B;}
	bool operator < (const Node &x) const {return val!=x.val?val<x.val:pos>x.pos;}
	bool operator > (const Node &x) const {return val!=x.val?val>x.val:pos<x.pos;}
};
Node max(Node x,Node y){return x>y?x:y;}
struct BIT
{
	int len;
	Node t[N];
	void init(int l){len=l,memset(t,0,sizeof(t));}
	inline int lowbit(int x){return x&(-x);}
	void update(int u,Node v){for(int i=u;i<=len;i+=lowbit(i)) t[i]=max(t[i],v);}
	Node query(int u)
	{
		Node ans(0,-1);
		for(int i=u;i>0;i-=lowbit(i)) ans=max(ans,t[i]);
		return ans;
	}
}bit;
int f[N],pre[N];
vector<int> a,b,c;
int LIS()
{
	int n=a.size();
	f[0]=1; pre[0]=-1; bit.init(::n); bit.update(a[0],Node(1,0));
	for(int i=1;i<n;i++)
	{
		auto [val,pos]=bit.query(a[i]);
		f[i]=val+1,pre[i]=pos;
		bit.update(a[i],Node(f[i],i));
	}
	int maxn=0;
	for(int i=0;i<n;i++) maxn=max(maxn,f[i]);
	// for(int i=0;i<n;i++) printf("%d %d\n",f[i],pre[i]);
	return maxn;
}
bool vis[N];
set<Node> s;
void solve()
{
	if(a.size()==0) return ;
	int n=a.size();
	int R=LIS();
	if(R>getf(n))
	{
		int maxid=0;
		for(int i=0;i<n;i++) if(f[i]>f[maxid]) maxid=i;
		int cur=maxid;
		memset(vis,0,sizeof(vis));
		while(cur!=-1)
		{
			vis[cur]=1;
			cur=pre[cur];
		}
		b.clear(),c.clear();
		for(int i=0;i<n;i++)
		{
			if(!vis[i]) b.pb(a[i]);
			else c.pb(a[i]);
		}
		ans[++Acnt]=c;
		a=b;
		solve();
	}
	else
	{
		int t=getf(n);
		while(t--)
		{
			Acnt++;
			s.insert(Node(inf-Acnt,Acnt));
		}
		for(int i=0;i<n;i++)
		{
			auto x=s.upper_bound(Node(a[i],0));
			// printf("%d %d\n",x->val,x->pos);
			ans[x->pos].pb(a[i]);
			int P=x->pos;
			s.erase(x);
			s.insert(Node(a[i],P));
		}
	}
}
void work()
{
	s.clear(); Acnt=0;
	n=read(); a.resize(n);
	for(int i=0;i<n;i++) a[i]=read();
	if(n==1)
	{
		printf("1\n1 1\n");
		return ;
	}
	solve();
	int cnt=0;
	for(int i=1;i<=Acnt;i++) if(!ans[i].empty()) cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=Acnt;i++)
	{
		if(ans[i].empty()) continue;
		printf("%d ",(int)ans[i].size());
		for(int j:ans[i]) printf("%d ",j);
		puts("");
	}
	for(int i=1;i<=Acnt;i++) ans[i].clear();
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}