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
vi g[200009];
int s[200009],p[200009],h[200009],d[200009];
void dfs(int u,int v){
	p[u]=v;
	s[u]=1;
	d[u]=sz(g[u]);
	if(v!=-1) d[u]--;
	trav(i,g[u]) if(i!=v){
		h[i]=h[u]+1;
		dfs(i,u);
		s[u]+=s[i];
	}
	h[u] -= s[u]-1;

}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,k;cin>>n>>k;
	rep(i,n-1){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,-1);
	priority_queue<pii> q;
	repA(i,1,n) if(d[i]==0) q.push(mp(h[i],i));
	ll ans = 0;
	rep(i,k){
		pii z  = q.top();
		q.pop();
		ans+=z.fst;
		if(p[z.snd]!=-1) {
			d[p[z.snd]]--;
			if(d[p[z.snd]]==0) q.push(mp(h[p[z.snd]],p[z.snd]));
		}
	}
	cout<<ans;
	return 0;
}