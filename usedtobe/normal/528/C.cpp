#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define fec(i,a) for (__typeof e[a].begin() i=cur[a];i!=e[a].end();++i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=501000;
int n,m,vis[N],u,v;
vector<PII> e[N];
VI vec,pth;
int cur[N];
int cou;
void dfs(int u) {
	int sz=e[u].size();
	for(int i=cur[u];i<sz;i=cur[u]){
		cur[u]++;
		PII v=e[u][i];cur[u]=i+1;
		if (!vis[v.se]) {
			vis[v.se]=1;
			dfs(v.fi);
		}
	}
	pth.pb(u);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].pb(mp(v,i)); e[v].pb(mp(u,i));
	}
	rep(i,1,n+1) if (SZ(e[i])%2==1) vec.pb(i);
	rep(i,0,SZ(vec)/2) {
		u=vec[2*i],v=vec[2*i+1];
		e[u].pb(mp(v,m)); e[v].pb(mp(u,m)); m++;
	}
	if (m%2==1) e[1].pb(mp(1,m)),m++;
	dfs(1);
	printf("%d\n",m);
	rep(i,0,SZ(pth)-1) {
		u=pth[i]; v=pth[i+1];
		if (i%2) printf("%d %d\n",u,v); else printf("%d %d\n",v,u);
	}
}