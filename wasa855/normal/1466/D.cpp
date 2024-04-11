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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
vector<int> G[N];
int w[N],cnt[N],n;
void work()
{
	n=read();
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	int sum=0;
	for(int i=1;i<=n;i++) cnt[i]=(int)G[i].size()-1;
	// int maxn=0;
	// for(int i=1;i<=n;i++) if(G[i].size()!=1&&w[i]>w[maxn]) maxn=i;
	// cnt[maxn]++;
	for(int i=1;i<=n;i++) sum+=w[i];
	priority_queue<int> q;
	for(int i=1;i<=n;i++) for(int j=1;j<=cnt[i];j++) q.push(w[i]);
	for(int i=1;i<n;i++)
	{
		printf("%lld ",sum);
		if(!q.empty()) sum+=q.top(),q.pop();
	}
	cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}