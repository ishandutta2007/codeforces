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
	int n,m,k;cin>>n>>m>>k;
	string s;cin>>s;
	int cnt[26] = {0};
	trav(i,s) cnt[i-'A']++;
	int ans = 1e9;
	int ss = 0;
	rep(i,26) cnt[i] = min(cnt[i],60009),ss+=cnt[i];;
	rep(i,26){
		if(cnt[i]==0) continue;
		vector<bool> b(ss+1,0);
		b[0] = 1;
		int sum = 0;
		rep(j,26){
			if(j!=i){
				sum+=cnt[j];
				repD(k,ss,cnt[j]){
					if(b[k-cnt[j]]) b[k] = 1;
				}
			}
		}
		rep(j,sum+cnt[i]+1){
			if(b[j]){
				int x = max(0,n-j);
				int y = max(0,m-(sum-j));
				if(x+y<=cnt[i]){
					ans = min(ans,x*y);
				}
			}
		}
	}
	cout<<ans<<'\n';
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	
	
	return 0;
}