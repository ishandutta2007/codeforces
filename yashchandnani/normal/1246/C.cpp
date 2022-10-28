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
string s[20009];
ll dp[2][2009][2009];
ll r[2009][2009];
ll c[2009][2009];
int x[2009][2009];
int y[2009][2009];
const int mod = 1e9+7;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	rep(i,n) cin>>s[i];
	if(n==1||m==1){
		rep(i,n) rep(j,m) if(s[i][j]=='R'){
			cout<<0;
			exit(0);
		}
		cout<<1;
		exit(0);
	}
	if(s[0][0]=='R'||s[n-1][m-1]=='R'){
		cout<<0;
		return 0;
	}
	rep(i,n) rep(j,m){
		if(s[i][j]=='R') r[i][j] = c[i][j] = 1;
	}
	repA(i,1,n-1) rep(j,m) c[i][j]+=c[i-1][j];
	repA(j,1,m-1) rep(i,n) r[i][j]+=r[i][j-1];
	dp[0][0][0] = 1;
	dp[1][0][0] = 1;
	repA(i,1,n-1){
		if(n-i-1>=c[n-1][0]) dp[1][i][0] = 1;
	}
	repA(j,1,m-1) if(m-j-1>=r[0][m-1]) dp[0][0][j] = 1;
	repA(i,1,n-1) repA(j,1,m-1){
		x[i][j] = x[i-1][j];
		y[i][j] = y[i][j-1];
		while(x[i][j]<i&&c[n-1][j]-c[x[i][j]][j]>n-i-1) x[i][j]++;
		while(y[i][j]<j&&r[i][m-1]-r[i][y[i][j]]>m-j-1) y[i][j]++;
	}
	fill(r);
	fill(c);
	repA(i,1,n-1) r[i][0] = dp[1][i][0];
	repA(i,1,m-1) c[0][i] = dp[0][0][i];
	repA(i,1,n-1) repA(j,1,m-1){
		dp[0][i][j] = r[i][j-1];
		dp[1][i][j] = c[i-1][j];
		if(x[i][j]) dp[1][i][j]-=c[x[i][j]-1][j];
		if(y[i][j]) dp[0][i][j]-=r[i][y[i][j]-1];
		dp[0][i][j]%=mod;
		dp[1][i][j]%=mod;
		r[i][j]=(r[i][j-1]+dp[1][i][j])%mod;
		c[i][j]=(c[i-1][j]+dp[0][i][j])%mod;
	}
	cout<<(dp[0][n-1][m-1]+dp[1][n-1][m-1]+2*mod)%mod;
	return 0;
}