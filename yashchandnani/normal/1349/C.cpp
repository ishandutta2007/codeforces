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
string s[1009];
int ix[1000009];
const int inf = 1e9;
int val[1000009];
vi g[1000009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,t;cin>>n>>m>>t;
	rep(i,n) cin>>s[i];
	rep(i,n*m) val[i] = inf;
	rep(i,n) rep(j,m) {
		if(j){
			if(s[i][j]==s[i][j-1]){
				val[i*m+j]=val[i*m+j-1]=0;
			}
			else g[i*m+j].pb((i)*m+j-1),g[(i)*m+j-1].pb(i*m+j);
		}
		if(i){
			if(s[i][j]==s[i-1][j]){
				val[i*m+j]=val[(i-1)*m+j]=0;
			}
			else g[i*m+j].pb((i-1)*m+j),g[(i-1)*m+j].pb(i*m+j);
		}
	}
	queue<pii> q;
	rep(i,n) rep(j,m) if(val[i*m+j]==0){
		q.push(mp(0,i*m+j));
	}
	while(!q.empty()){
		auto z = q.front();
		q.pop();
		trav(j,g[z.snd]){
			if(val[j]==inf){
				val[j] = z.fst+1;
				q.push(mp(val[j],j));
			}
		}
	}
	rep(i,t){
		int x,y;cin>>x>>y;x--,y--;
		ll p;cin>>p;
		if(val[x*m+y]==inf||val[x*m+y]>=p) cout<<s[x][y]<<'\n';
		else{
			p-=val[x*m+y];
			if(p%2) cout<<int('1'-s[x][y])<<'\n';
			else cout<<s[x][y]<<'\n';
		}
	}
	return 0;
}