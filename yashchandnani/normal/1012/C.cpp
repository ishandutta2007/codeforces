#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
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
int a[5009][3];
unsigned long long dp[2][3009][3][2];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	repA(i,1,n) cin>>a[i][0];
	repA(i,1,n-1) a[i][1] = min(a[i][0],a[i+1][0]-1);
	repA(i,2,n) a[i][2] = min(a[i][0],a[i-1][0]-1);
	repA(i,1,n) sort(a[i],a[i]+3);
	rep(j,3000) rep(k,3) rep(l,2) dp[0][j][k][l] = 1e18;
	dp[0][0][0][0] = 0;
	int cur =0,prev=1;
	repA(i,1,n){
		swap(prev,cur);
		repA(j,0,(i+10)/2) rep(k,3) rep(l,2) dp[cur][j][k][l] = 1e18;
		rep(j,3) dp[cur][0][j][0] = a[i][2]-a[i][j];
		repA(j,1,(i+1)/2){
			rep(k,3){
				rep(l,3){
					if(a[i-1][k]>a[i][l]) dp[cur][j][l][0] = min(dp[cur][j][l][0],dp[prev][j][k][1]+a[i][2]-a[i][l]);
					if(a[i-1][k]<a[i][l]) dp[cur][j][l][1] = min(dp[cur][j][l][1],dp[prev][j-1][k][0]+a[i][2]-a[i][l]);
					dp[cur][j][l][0] = min(dp[cur][j][l][0],dp[prev][j][k][0]+a[i][2]-a[i][l]);	
				}
			}
		}
	}
	repA(i,1,(n+1)/2) {
			ll ans = 1e18;
			rep(j,3) rep(k,2) ans = min(ans,(ll)dp[cur][i][j][k]);
			cout<<ans<<' ';
	}
	return 0;
}