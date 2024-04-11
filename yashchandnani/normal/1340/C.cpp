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
int d[10009];
bool vis[10009][1009];
vector<pii> dx[10009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	rep(i,m) {
	cin>>d[i];
	}
	sort(d,d+m);
	int g,r;cin>>g>>r;
	dx[0].pb(mp(0,0));
	ll fns=-1;
	rep(i,10000) rep(di,1001) {
		trav(z,dx[di]){
			if(!vis[z.fst][z.snd]) vis[z.fst][z.snd]=1;
			else continue;
			if(z.fst==m-1){
				fns=di+i*1001;
				goto gg;
			}
			int i = z.fst;
			if(i>0){
				int l = d[i]-d[i-1]+z.snd;
				if(l==g) l=0;
				if(l<g&&!vis[i-1][l]){
					dx[(di+d[i]-d[i-1])%1001].pb(mp(i-1,l));
				}
			}
			if(i+1<m){
				int l = d[i+1]-d[i]+z.snd;
				if(l==g) l=0;
				if(l<g&&!vis[i+1][l]){
					dx[(di+d[i+1]-d[i])%1001].pb(mp(i+1,l));
				}
			}
		}
		dx[di].clear();
	}
gg:
	if(fns>0){
		ll x = (fns-1)/g;
		fns+=x*r;
	}
	cout<<fns;
	return 0;
}