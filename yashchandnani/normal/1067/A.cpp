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
ll dp[100009][209][2];
int a[100009];
const ll mod = 998244353;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	dp[0][0][0] = 1;
	int lst;
	repA(i,1,n){
		int x=0;
		cin>>x;
		a[i] = x;
		ll sum = dp[i-1][0][0];
		repA(j,1,200){
			sum%=mod;
			dp[i][j][0] = sum;
			if(x!=-1&&x!=j) dp[i][j][0] = 0;
			sum+=dp[i-1][j][0]+dp[i-1][j][1];
		}
		sum = 0;
		repD(j,200,1){
			sum+=dp[i-1][j][1];
			sum%=mod;
			dp[i][j][1] = (sum+dp[i-1][j][0])%mod;
			if(x!=-1&&x!=j) dp[i][j][1] = 0;
		}
		lst = x;
		//trace(dp[i][1][0]);
		//trace(dp[i][2][0]);
		//trace(dp[i][1][1]);
		//trace(dp[i][2][1]);
	}
	ll ans =0;
	repA(j,1,200) if(lst==-1||j==lst) {
		ans+=dp[n][j][1];
	}
	cout<<ans%mod;
	return 0;
}