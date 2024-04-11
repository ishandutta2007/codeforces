#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
#define N 2050
int a[N],ans[N],n;
int p[N];
int sum=0;
int query(int u,int v)
{
	if(u==v) return 2047;
	sum++;
	cout<<"? "<<u<<" "<<v<<endl;
#ifdef LOCAL
	printf("%d\n",ans[u]|ans[v]);
	return ans[u]|ans[v];
#endif
	return read();
}
struct Query
{
	set<pii> s;
	bool ok;
	void chk()
	{
		int ans=2047;
		for(auto [i,_]:s) ans&=i;
		if(ans==0) ok=1;
	}
	void insert(int x,int id)
	{
		for(auto [i,_]:s) if((i|x)==x) return ;
		vector<pii> e;
		for(auto [i,_]:s) if((i|x)==i) e.pb(mp(i,_));
		for(auto i:e) s.erase(i);
		s.insert(mp(x,id));
		chk();
	}
	int q(int id)
	{
		if(ok)
		{
			int ans=2047;
			for(auto [_,i]:s) ans&=query(id,i);
			return ans;
		}
		else
		{
			int ans=2047;
			for(int i=1;i<=25;i++) ans&=query(id,rnd()%n+1);
			return ans;
		}
	}
}q;
signed main()
{
	cin>>n;
#ifdef LOCAL
	// for(int i=1;i<=n;i++) ans[i]=read();
	for(int i=1;i<=n;i++) ans[i]=2048-i;
#endif
	for(int i=1;i<=n;i++) p[i]=i;
	shuffle(p+1,p+n+1,rnd);
	int cur=q.q(p[1]),cid=1;
	a[p[1]]=cur;
	q.insert(a[p[1]],p[1]);
	for(int i=2;i<=n;i++)
	{
		if(query(p[i],p[cid])==cur)
		{
			a[p[i]]=q.q(p[i]);
			cur=a[p[i]];
			cid=i;
			q.insert(a[p[i]],p[i]);
			if(a[p[i]]==0) break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==p[cid]||a[p[i]]) continue;
		a[p[i]]=query(p[i],p[cid]);
	}
	cout<<"! ";
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	cout<<endl;
#ifdef LOCAL
	for(int i=1;i<=n;i++) assert(a[i]==ans[i]);
	cerr<<sum<<endl;
#endif
	return 0;
}


//