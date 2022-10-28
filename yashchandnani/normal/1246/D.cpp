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
vi g[100009];
int p[100009];
int s;
int dfn[100009];
int d[100009];
bool cmp(int l,int r){
	return d[l]<d[r];
}
void pre_dfs(int u){
	d[u] = 0;
	trav(i,g[u]) pre_dfs(i),d[u]=max(d[u],d[i]+1);
}
pii lol[200009];
int x;
void dfs(int v){
	dfn[s++] = v;
	sort(all(g[v]),cmp);
	trav(i,g[v]) {
		lol[x++] = mp(v,i);
		dfs(i);
		lol[x++] = mp(i,v);
	}
}
int nxt[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	repA(i,1,n-1){
		int x;cin>>x;
		g[x].pb(i);
		p[i] = x;
	}
	pre_dfs(0);
	dfs(0);
	rep(i,n) cout<<dfn[i]<<' ';
	cout<<'\n';
	vi ans;
	x--;
	while(d[lol[x].fst]<d[lol[x].snd]) x--;
	rep(i,n-1) nxt[dfn[i]] = dfn[i+1];
	repA(i,0,x){
		if(d[lol[i].fst]<d[lol[i].snd]){
			ans.pb(nxt[lol[i].fst]);
			nxt[lol[i].snd]=nxt[lol[i].fst];
		}
	}
	cout<<sz(ans)<<'\n';
	trav(i,ans) cout<<i<<' ';
	return 0;
}