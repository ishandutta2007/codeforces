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
int a[200009];
vi g[200009];
int d1[200009];
int d2[200009];
bool vis[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,k;cin>>n>>m>>k;
	rep(i,k) cin>>a[i];
	rep(i,m){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	queue<int> q;
	q.push(1);
	vis[1]=1;	
	while(!q.empty()){
		int z = q.front();
		q.pop();
		trav(i,g[z]) if(!vis[i]) d1[i] = d1[z]+1,vis[i]=1,q.push(i);
	}
	fill(vis);
	vis[n]=1;
	q.push(n);
	while(!q.empty()){
		int z = q.front();
		q.pop();
		trav(i,g[z]) if(!vis[i]) d2[i] = d2[z]+1,vis[i]=1,q.push(i);
	}
	vector<pii> v1,v2;
	rep(i,k) v1.pb(mp(d1[a[i]]-d2[a[i]],a[i])),v2.pb(mp(d2[a[i]],a[i]));
	int ans = d1[n];
	int cur = 0;
	sort(all(v1));
	int mx = 0;
	trav(i,v1){
		if(i!=v1[0]) cur=max(cur,mx+1+d2[i.snd]);
		mx=max(mx,d1[i.snd]);
	}
	cout<<min(ans,cur);
	return 0;
}