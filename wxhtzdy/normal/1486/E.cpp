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
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,m;
ll d[N][55];
vector<PII> e[N];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m+1) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w)); e[v].pb(mp(u,w));
	}
	priority_queue<array<ll,3>> q;
	rep(i,1,n+1) rep(j,0,51) d[i][j]=(1<<29);
	q.push({0,1,0}); d[1][0]=0;
	while (SZ(q)) {
		auto u=q.top(); q.pop();
		if (-u[0]>d[u[1]][u[2]]) continue;
		for (auto x:e[u[1]]) {
			if (u[2]==0) {
				if (d[x.fi][x.se]>d[u[1]][0]) {
					d[x.fi][x.se]=d[u[1]][0];
					q.push({-d[x.fi][x.se],x.fi,x.se});
				}
			} else {
				if (d[x.fi][0]>d[u[1]][u[2]]+(u[2]+x.se)*(u[2]+x.se)) {
					d[x.fi][0]=d[u[1]][u[2]]+(u[2]+x.se)*(u[2]+x.se);
					q.push({-d[x.fi][0],x.fi,0});
				}
			}
		}
	}
	rep(i,1,n+1) {
		printf("%lld ",(d[i][0]==1<<29)?-1:d[i][0]);
	}
}