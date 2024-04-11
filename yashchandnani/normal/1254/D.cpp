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
int s[200009];
vi g[200009];
bool cmp(int l,int r){
	return s[l]<s[r];
}
void pre_dfs(int v,int p){
	s[v]=1;
	trav(i,g[v]){
		if(i!=p){
			pre_dfs(i,v);
			s[v]+=s[i];
		}
	}
	for(auto it=g[v].begin();it!=g[v].end();it++){
		if(*it==p){
			g[v].erase(it);
			break;
		}
	}
	sort(all(g[v]),cmp);
}
int st[200009],en[200009];
int a[200009];
int gg=0;
vector<pair<int,pii>> ax[200009];
void dfs(int v){
	a[gg]=v;
	st[v]=gg;
	gg++;
	trav(i,g[v]) {
		dfs(i);
		if(sz(ax[v])&&ax[v].back().fst==s[i]){
			ax[v].back().snd.snd=gg;
		}
		else ax[v].pb(mp(s[i],mp(st[i],en[i])));
	}
	en[v]=gg;
}
const ll mod =998244353; 
struct FT {
	vector<ll> s;
	FT(int n) : s(n,0) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] = (s[pos]+dif)%mod;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res = (res+s[pos-1])%mod;
		return res;
	}
};

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}
ll modInverse(ll a,ll p){
	ll x,y;
	euclid(a,p,x,y);
	return ((x%p+p)%p);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,q;cin>>n>>q;
	rep(i,n-1){
		int u,v;cin>>u>>v;
		u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	pre_dfs(0,-1);
	dfs(0);
	FT T(n+5);
	ll x = modInverse(n,mod);
	rep(i,q){
		int t,v;
		cin>>t>>v;v--;
		if(t==1){
			int d;cin>>d;
			trav(j,ax[v]){
				ll val = x*d%mod*(n-j.fst)%mod;
				T.update(j.snd.fst,val);
				T.update(j.snd.snd,-val);
			}
			T.update(st[v],d);
			T.update(st[v]+1,-d);
			if(v){
				ll val = x*d%mod*(s[v])%mod;
				T.update(0,val);
				T.update(st[v],-val);
				T.update(en[v],val);
			}
		}
		else{
			cout<<(T.query(st[v]+1)+mod)%mod<<'\n';
		}
	}
	return 0;
}