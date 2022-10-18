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
#define N 200005
vector<int> G[N];
int ans=0;
int dfs(int u,int f)
{
	int sum=0;
	for(int v:G[u])
	{
		if(v==f) continue;
		sum+=dfs(v,u);
	}
	// printf("%d %d\n",u,sum);
	if(f==0)
	{
		if(!sum) ans++;
		return 0;
	}
	if(!sum)
	{
		ans++;
		return 1;
	}
	else
	{
		ans--;
		return 0;
	}
}
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	ans=0;
	dfs(1,0);
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}