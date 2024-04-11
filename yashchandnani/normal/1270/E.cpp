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
int u[1000009],v[1000009];
int x[1000009],y[1000009];
map<ll,vector<pii>> m;
struct UF {
	vi e,d;
	UF(int n) : e(n, -1), d(n,0) {}
	int find(int x) { 
		if(e[x]<0) return x;
		else {
			int z = e[x];
			int p = find(e[x]);
			d[x]^=d[z];
			e[x] = p;
			return p;
		}
	}
	bool join(int a, int b,int w) {
		int aa = find(a), bb = find(b);
		if (aa == bb) return (d[a]^d[b])==w;
		if (e[aa] > e[bb]) swap(a, b),swap(aa,bb);
		e[aa] += e[bb]; e[bb] = aa;d[bb]=w^d[a]^d[b];
		return true;
	}
};
map<pii,int> mx;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n){
		cin>>x[i]>>y[i];	
		rep(j,i){
			ll d = 1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j]);
			m[d].pb(mp(i,j));
		}
	}
	srand(time(0));
	while(1){
		int cnt = 0;
		bool fg=1;
		UF dsu(n);
		trav(i,m){
			if(sz(i.snd)==1) continue;
			cnt++;
			int x = rand()%2;
			rep(j,sz(i.snd)){
				int l1 = i.snd[j].fst,l2=i.snd[j].snd;
				if(dsu.find(l1)==dsu.find(l2)) x=dsu.d[l1]^dsu.d[l2];
			}
			rep(j,sz(i.snd)){
				int l1 = i.snd[j].fst,l2=i.snd[j].snd;
				cnt++;
				fg&=dsu.join(l1,l2,x);
			}
		}
		rep(i,n) if(dsu.find(i)!=dsu.find(0)){
			dsu.join(0,i,1);
		}
		if(fg) {
			vi ans;
			repA(i,1,n-1){
				if(dsu.d[0]!=dsu.d[i]) ans.pb(i);
			}
			if(sz(ans)){
				cout<<sz(ans)<<'\n';
				trav(i,ans) cout<<i+1<<' ';
				return 0;
			}
		}
	}
	return 0;
}