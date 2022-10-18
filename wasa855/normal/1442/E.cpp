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
int col[N];
vector<int> G[N];
int n,dgr[N];
int solve(int c)
{
	queue<int> q[3];
	for(int i=1;i<=n;i++) dgr[i]=G[i].size()-1;
	for(int i=1;i<=n;i++) if(!dgr[i]) q[col[i]].push(i);
	int cnt=n,ans=0;
	while(cnt)
	{
		c=3-c,ans++;
		while(!q[0].empty()||!q[c].empty())
		{
			int u; cnt--;
			if(!q[0].empty()) u=q[0].front(),q[0].pop();
			else u=q[c].front(),q[c].pop();
			for(int v:G[u])
			{
				if(!--dgr[v]) q[col[v]].push(v);
			}
		}
	}
	return ans;
}
void work()
{
	cin>>n;
	for(int i=1;i<=n;i++) col[i]=read();
	if(n==1) {printf("1\n"); return ;}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	printf("%d\n",min(solve(1),solve(2)));
	for(int i=1;i<=n;i++) G[i].clear();
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}