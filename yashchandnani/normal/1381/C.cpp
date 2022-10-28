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
int b[100009],a[100009];
vector<vi> g;
void solve(){
	int n,x,y;cin>>n>>x>>y;
	g.clear();
	g.resize(n+2);
	int dne = 0;
	rep(i,n){
		cin>>b[i];
		g[b[i]].pb(i);
	}
	priority_queue<pii> q;
	repA(i,1,n+1) {
		if(sz(g[i])) q.push(mp(sz(g[i]),i));
		else dne = i;
	}
	rep(i,x){
		pii z = q.top();
		q.pop();
		int col = z.snd;
		int cnt = z.fst;
		a[g[col].back()] = col;
		g[col].pop_back();
		if(cnt>1) q.push(mp(cnt-1,col));
	}
	vector<pii> v;
	int mx = 0;
	repA(i,1,n+1) {
		trav(j,g[i]) v.pb(mp(i,j));
		mx = max(mx,sz(g[i]));
	}
	int z = y-x;
	rep(i,sz(v)){
		int col =  v[i].fst;
		int pos = v[(i+mx)%sz(v)].snd;
		if(b[pos]!=col&&z>0){
			a[pos] = col;
			z--;
		}
		else a[pos] = dne;
	}
	if(z) cout<<"NO\n";
	else{
		cout<<"YES\n";
		rep(i,n) cout<<a[i]<<' ';
		cout<<'\n';
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();
	return 0;
}