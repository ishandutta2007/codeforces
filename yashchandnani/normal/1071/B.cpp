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
string u[2009];
int dp[2009][2009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,k;cin>>n>>k;
	if(k>=2*n-1){
		string s(2*n-1,'a');
		cout<<s;
		exit(0);
	}
	rep(i,n) cin>>u[i];
	dp[0][0] = k;
	rep(i,n){
		rep(j,n){
			if(dp[i][j]>0&&u[i][j]!='a') u[i][j] = 'a',dp[i][j]--;
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
		}
	}
	string ans;
	ans+=u[0][0];
	vector<pii> v(1,mp(0,0));
	rep(i,2*n-2){
		vector<pii> s;
		char mn = 'z';
		trav(i,v){
			if(i.fst+1<n&&u[i.fst+1][i.snd]<mn) mn = u[i.fst+1][i.snd];
			if(i.snd+1<n&&u[i.fst][i.snd+1]<mn) mn = u[i.fst][i.snd+1];
		}
		ans+=mn;
		trav(i,v){
			if(i.fst+1<n&&u[i.fst+1][i.snd]<=mn) s.pb(mp(i.fst+1,i.snd));;
			if(i.snd+1<n&&u[i.fst][i.snd+1]<=mn) s.pb(mp(i.fst,i.snd+1));;
		}
		sort(all(s));
		s.resize(distance(s.begin(),unique(all(s))));
		v = s;
	}
	cout<<ans;	
	return 0;
}