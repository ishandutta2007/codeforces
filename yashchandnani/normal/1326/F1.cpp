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
const int N = 14;
int ix[(1<<N)];
vi cnt[N];
bool cmp(int l,int r){
	return mp(__builtin_popcount(l),l)<mp(__builtin_popcount(r),r);
}
vector<ll> dp[N+1][5000][N];
vi v;
int n;
void pre(){
	rep(i,(1<<n)) v.pb(i);
	sort(all(v),cmp);
	rep(i,sz(v)) {
		int k = __builtin_popcount(v[i]);
		ix[v[i]]=sz(cnt[k]);
		cnt[k].pb(v[i]);
	}
}

void solve(){


}
string s[N];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	pre();
	rep(i,n) {
		//s[i]=string(n,'1');
		cin>>s[i];
	}
	int lim = (1<<n);
	rep(i,n) dp[1][i][i].resize(lim/2,0),dp[1][i][i][0]=1;
	repA(i,2,n){
		rep(j,sz(cnt[i-2])) rep(k,n) dp[i-2][j][k].clear();
		rep(j,sz(cnt[i])) rep(k,n) dp[i][j][k].resize(1<<(i-1),0);
		rep(j,sz(cnt[i])) rep(k,n) rep(l,1<<(i-1)) {
			int v = cnt[i][j];
			if((v&(1<<k))==0) continue;
			if((l&(1<<(i-2)))){
				rep(x,n) if(x!=k&&s[k][x]=='1'&&((1<<x)&v)) {
					dp[i][j][k][l]+=dp[i-1][ix[v^(1<<k)]][x][l^(1<<(i-2))];
				}
			}
			else{
				rep(x,n) if(x!=k&&s[k][x]=='0'&&((1<<x)&v)) {
					dp[i][j][k][l]+=dp[i-1][ix[v^(1<<k)]][x][l];
				}
			}
		}
	}
	rep(i,lim/2){
		ll ans = 0;
		rep(j,n) ans+=dp[n][0][j][i];
		cout<<ans<<' ';
	}
	return 0;
}