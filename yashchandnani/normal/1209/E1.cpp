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
vector<pii> sub[(1<<12)];
void pre(){
	rep(i,(1<<12)){
		rep(j,i+1){
			if((i&j)==j){
				sub[i].pb(mp(__builtin_popcount(j),j));
			}
		}
		sort(all(sub[i]));
		reverse(all(sub[i]));
	}

}
int a[13][2009];
int dp[13][(1<<12)];
int cur[(1<<12)];
void solve(){
	int n,m;
	cin>>n>>m;
	//n=12,m=2000;
	vector<pair<vi,int>> v;
	rep(i,n){
		rep(j,m) {
			cin>>a[i][j];
			//a[i][j]=rand()%100000;
		}
	}
	rep(i,m){
		vi u;
		rep(j,n) u.pb(a[j][i]);
		sort(all(u));
		reverse(all(u));
		v.pb(mp(u,i));
	}
	sort(all(v));
	reverse(all(v));
	fill(dp);
	rep(i,min(n,m)){
		fill(cur);
		rep(j,(1<<n)){
			rep(k,n){
				int gg = 0;
				rep(l,n){
					if((1<<((l-k+n)%n))&j){
						gg+=a[l][v[i].snd];
					}
				}
				cur[j]=max(cur[j],gg);
			}
		}
		trav(j,sub[(1<<n)-1]){
			trav(k,sub[j.snd]){
				dp[i+1][j.snd] = max(dp[i+1][j.snd],dp[i][k.snd]+cur[j.snd^k.snd]);
			}
		}
	}
	cout<<dp[min(n,m)][(1<<n)-1]<<'\n';
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n){
		solve();
	}
	return 0;
}