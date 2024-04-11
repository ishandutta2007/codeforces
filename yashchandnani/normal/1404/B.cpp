#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
vector<vi> g;
int mxd = 0,mxdix = -1;
int dis[100009];
void dfs(int u,int p){
	trav(i,g[u]){
		if(i!=p){
			dis[i]=dis[u]+1;
			if(dis[i]>mxd) mxd=dis[i],mxdix =i;
			dfs(i,u);
		}
	}
}
void solve(){
	int n,a,b,da,db;cin>>n>>a>>b>>da>>db;
	g.clear();
	g.resize(n+1);
	rep(i,n-1){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	mxd =0,mxdix=a;
	dis[a]=0;
	dfs(a,-1);
	if(dis[b]<=da){
		cout<<"Alice\n";
		return;
	}
	if(db<=2*da){
		cout<<"Alice\n";
		return;
	
	}
	mxd = 0;
	dis[mxdix]=0;
	dfs(mxdix,-1);
	if(mxd<=2*da){
		cout<<"Alice\n";
		return;
	
	}
	cout<<"Bob\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();
	return 0;
}