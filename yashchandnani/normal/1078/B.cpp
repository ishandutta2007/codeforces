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
int cnt[109];
bool dp[10009][109];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int t = 0;
	vi v;
	rep(i,n){
		int x;cin>>x;
		if(!cnt[x]) t++;
		v.pb(x);
		cnt[x]++;
	}
	if(t==1){
		cout<<n;
		exit(0);
	}
	bool fg = 0;
	int ans = 0;
	repA(i,1,100){
		if(!cnt[i]) continue;
		int sum = cnt[i]*i;
		fill(dp);
		dp[0][0] = 1;
		trav(j,v){
			if(j==i) continue;
			repD(k,sum,j){
				repD(l,n-cnt[i],1){
					if(dp[k-j][l-1]) dp[k][l]=1;
				}
			}
		}
		int cur = 0;
		repA(j,1,cnt[i]) if(!dp[j*i][j]) cur = j; else break;
		ans = max(ans,cur);
		if(cur==cnt[i]) fg=1;
	}
	if(t==2&&fg) cout<<n;
	else cout<<ans;
	return 0;
}