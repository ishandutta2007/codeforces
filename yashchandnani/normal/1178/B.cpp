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
ll dp[1000009][4];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	string s;cin>>s;
	repD(i,sz(s)-1,1){
		if(s[i-1]=='v'&&s[i]=='v') s[i]='w';
	}
	dp[0][0]=1;
	rep(i,sz(s)){
		if(s[i]=='w'){
			dp[i+1][3] = dp[i][3]+dp[i][2];
			dp[i+1][2] = dp[i][2];
			dp[i+1][1] = dp[i][1]+dp[i][0];
			dp[i+1][0] = dp[i][0];
		}
		else if(s[i]=='o'){
			dp[i+1][3] = dp[i][3];
			dp[i+1][2] = dp[i][2]+dp[i][1];
			dp[i+1][1] = dp[i][1];
			dp[i+1][0] = dp[i][0];
		}
		else{
			dp[i+1][3] = dp[i][3];
			dp[i+1][2] = dp[i][2];
			dp[i+1][1] = dp[i][1];
			dp[i+1][0] = dp[i][0];
		}
	}
	cout<<dp[sz(s)][3];	
	
	return 0;
}