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

const int N=200100;
int n,k,x[N],y[N],t[N],f[N],mn[N],vis[N],_;

int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}

void unite(int a,int b) {
	a=find(a);
	b=find(b);
	if (a==b) return;
	f[a]=b;
}

void solve() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d%d%d",x+i,y+i,t+i);	
	rep(i,1,n+1) f[i]=i,mn[i]=1e9,vis[i]=0;
	map<int,VI> mx,my;
	rep(i,1,n+1) {
		mx[x[i]].pb(i);
		my[y[i]].pb(i);
	}
	for (auto c:mx) {
		VI v=c.se;
		sort(all(v),[&](int i,int j){ return y[i]<y[j]; });
		rep(i,0,SZ(v)) {
			if (i>0&&y[v[i]]-y[v[i-1]]<=k) unite(v[i],v[i-1]);
		}
	}
	for (auto c:my) {
		VI v=c.se;
		sort(all(v),[&](int i,int j){ return x[i]<x[j]; });
		rep(i,0,SZ(v)) {
			if (i>0&&x[v[i]]-x[v[i-1]]<=k) unite(v[i],v[i-1]);
		}
	}
	rep(i,1,n+1) mn[find(i)]=min(mn[find(i)],t[i]);
	VI vec;
	rep(i,1,n+1) if (find(i)==i) vec.pb(mn[i]);
	sort(all(vec));
	int ans=-1;
	while (SZ(vec)&&vec.back()>ans) ans++,vec.pop_back();
	printf("%d\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}