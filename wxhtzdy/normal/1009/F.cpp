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

const int N=1010000;
int n,mx[N],dep[N];
VI e[N];
map<int,int> cnt[N];

void gao(int u,int f) {
	dep[u]=dep[f]+1;
	cnt[u][dep[u]]++;
	mx[u]=dep[u];
	for (auto v:e[u]) {
		if (v==f) continue;
		gao(v,u);
		if (SZ(cnt[u])<SZ(cnt[v])) {
			swap(cnt[u],cnt[v]);
			mx[u]=mx[v];
		}
		for (auto x:cnt[v]) {
			cnt[u][x.fi]+=x.se;
			if (cnt[u][x.fi]==cnt[u][mx[u]]) mx[u]=min(mx[u],x.fi);
			else if (cnt[u][x.fi]>cnt[u][mx[u]]) mx[u]=x.fi;
		}
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].pb(y); e[y].pb(x);
	}
	gao(1,0);
	rep(i,1,n+1) printf("%d\n",mx[i]-dep[i]);
}