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
int ans = 0;
struct UF {
	vi e;
	vi d;
	vi cnt[2];
	int x;
	UF(int n) : e(n, -1),d(n,0) {cnt[0].resize(n,1);cnt[1].resize(n,0);x=n-1;}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { 
		if(e[x]<0) return x;
		int p = e[x];
		int r = find(p);
		d[x]^=d[p];
		e[x]=r;
		return r;
	}
	void join(int aa, int bb, int w) {
		int a = find(aa), b = find(bb);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b),swap(aa,bb);
		int gg = find(x);
		if(a==gg) ans-=cnt[1-d[x]][a];
		else ans-=min(cnt[0][a],cnt[1][a]);
		if(b==gg) ans-=cnt[1-d[x]][b];
		else ans-=min(cnt[0][b],cnt[1][b]);
		e[a] += e[b]; e[b] = a;
		d[b] = d[aa]^d[bb]^w;
		if(d[b]) cnt[0][a] +=cnt[1][b],cnt[1][a]+=cnt[0][b];
		else cnt[0][a]+=cnt[0][b],cnt[1][a]+=cnt[1][b];
		gg = find(x);
		if(gg==a) ans+=cnt[1-d[x]][a];
		else ans+=min(cnt[0][a],cnt[1][a]);
	}
};

void solve(){


}
vi g[300009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,k;cin>>n>>k;
	string s;cin>>s;
	rep(i,k){
		int l;cin>>l;
		rep(j,l){
			int x;cin>>x;
			g[x-1].pb(i);
		}
	}
	UF dsu(k+1);
	rep(i,n){
		if(sz(g[i])==0) {
			cout<<ans<<'\n';
			continue;
		}
		if(sz(g[i])==1) g[i].pb(k);
		if(s[i]=='1') dsu.join(g[i][0],g[i][1],0);
		else dsu.join(g[i][0],g[i][1],1);
		cout<<ans<<'\n';
	}
	return 0;
}