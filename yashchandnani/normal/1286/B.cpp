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

void solve(){


}
int p[2009],c[2009];
vi g[2009];
int ans[2009];
int s[2009];
void pfs(int u){
	s[u] = 1;
	trav(i,g[u]) pfs(i),s[u]+=s[i];
}
bool fg=0;
void dfs(int u,vi v){
	if(c[u]>=sz(v)) fg=1,ans[u] = 1e5;
	else ans[u] = v[c[u]];
	vi lol;
	trav(i,v) if(i!=ans[u]) lol.pb(i);
	trav(i,g[u]){
		dfs(i,vi(lol.end()-s[i],lol.end()));
		lol = vi(lol.begin(),lol.end()-s[i]);
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	repA(i,1,n) {
		cin>>p[i]>>c[i];
		g[p[i]].pb(i);
	}
	vi v(n+1);
	rep(i,n+1) v[i] = i;
	pfs(0);
	dfs(0,v);
	if(fg) cout<<"NO";
	else {
		cout<<"YES\n";repA(i,1,n) cout<<ans[i]<<' ';
	}
	return 0;
}