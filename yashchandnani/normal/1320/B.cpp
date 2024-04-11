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
vi rg[200009];
int d[200009];
bool vis[200009];
int p[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	rep(i,m){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		rg[v].pb(u);
	}
	int k;cin>>k;
	rep(i,k) cin>>p[i];
	queue<int> q;
	vis[p[k-1]]=1;
	q.push(p[k-1]);
	while(!q.empty()){
		int z = q.front();
		q.pop();
		trav(i,rg[z]) if(!vis[i]) d[i]=d[z]+1,vis[i]=1,q.push(i);
	}
	int ans1=0,ans2=0;
	rep(i,k-2){
		if(d[p[i+1]]>=d[p[i]]){
			ans1++;
		}
		trav(j,g[p[i]]){
			if(j!=p[i+1]&&d[j]<=d[p[i+1]]) {
				ans2++;
				break;
			}
		}
	}
	cout<<ans1<<' '<<ans2;

	return 0;
}