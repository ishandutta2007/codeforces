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

vi r[3];
void solve(){
	int nr,ng,nb;
	cin>>nr>>ng>>nb;
	rep(i,3) r[i].clear();
	rep(i,nr) {
		int x;cin>>x;
		r[0].pb(x);
	}
	rep(i,ng) {
		int x;cin>>x;
		r[1].pb(x);
	}
	rep(i,nb) {
		int x;cin>>x;
		r[2].pb(x);
	}
	sort(all(r[0]));
	sort(all(r[1]));
	sort(all(r[2]));
	vi v({0,1,2});
	ll ans = 3e18+10;
	do{
		int i = 0,j=0,k=0;
		while(j<sz(r[v[1]])&&r[v[1]][j]<r[v[0]][i]) j++;
		while(k<sz(r[v[2]])&&r[v[2]][k]<r[v[1]][j]) k++;
		while(j<sz(r[v[1]])){
			while(i+1<sz(r[v[0]])&&r[v[0]][i+1]<=r[v[1]][j]) i++;
			while(k<sz(r[v[2]])&&r[v[2]][k]<r[v[1]][j]) k++;
			if(k<sz(r[v[2]])){
				int x = r[v[0]][i],y=r[v[1]][j],z=r[v[2]][k];
				ans=min(ans,2ll*x*x+2ll*y*y+2ll*z*z-2ll*x*y-2ll*y*z-2ll*z*x);
			}
			j++;
		}
	}while(next_permutation(all(v)));
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