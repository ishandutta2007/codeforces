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
int dp[109][4];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	string s,t;cin>>s>>t;
	int n = sz(s);
	rep(i,109) rep(j,4) dp[i][j] = -109;
	dp[0][3] = 0;
	repA(i,1,n){
		int x = 0;
		if(s[i-1]=='X') x|=1;
		if(t[i-1]=='X') x|=2;
		rep(j,4) dp[i][x] = max(dp[i][x],dp[i-1][j]);
		if(x==0){
			dp[i][3] = max(dp[i][3],dp[i-1][0]+1);
			dp[i][3] = max(dp[i][3],dp[i-1][1]+1);
			dp[i][3] = max(dp[i][3],dp[i-1][2]+1);
			dp[i][1] = max(dp[i][1],dp[i-1][0]+1);
			dp[i][2] = max(dp[i][2],dp[i-1][0]+1);
		}
		else if(x==1){
			dp[i][3] = max(dp[i][3],dp[i-1][0]+1);
		}
		else if(x==2){
			dp[i][3] = max(dp[i][3],dp[i-1][0]+1);
		}
	}
	int ans = 0;
	rep(i,4) ans = max(ans,dp[n][i]);
	cout<<ans;
	return 0;
}