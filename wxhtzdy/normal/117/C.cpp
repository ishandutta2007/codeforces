#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=5050;
VI e[N],cyc;
int n,prv[N],g[N][N];
bool vis[N];
char s[N];
void ans(int x,int y,int z) {
	printf("%d %d %d",x+1,y+1,z+1);
	exit(0);
}
void dfs(int u,int p) {
	if (!cyc.empty()) return;
	vis[u]=true;
	prv[u]=p;
	rep(i,0,n) if (g[p][u]&&g[u][i]&&g[i][p]) ans(p,u,i);
	rep(i,0,n) if (!vis[i]&&g[u][i]) dfs(i,u);
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s",&s);
		rep(j,0,n) g[i][j]=(s[j]-'0');
	}
	rep(i,0,n) if (!vis[i]) dfs(i,i);
	puts("-1");
}