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
int cnt1[5009];
int cnt2[5009];
vi g[5009];
int s[5009];
const ll mod = 1e9+7;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	rep(i,n) {
		int x;cin>>x;
		s[i] = x;
		cnt2[x]++;
	}
	rep(i,m){
		int f,h;cin>>f>>h;
		g[f].pb(h);
	}
	repA(i,1,n) sort(all(g[i]));
	int mx = 0;
	ll ans=0;
	int cur = 0;
	ll cns = 1;
	repA(i,1,n){
		if(sz(g[i])&&g[i][0]<=cnt2[i]){
			cur++;
			cns = cns*ll(upper_bound(all(g[i]),cnt2[i])-g[i].begin())%mod;
		}
	}
	mx=cur,ans=cns;
	rep(j,n){
		cnt1[s[j]]++;
		cnt2[s[j]]--;
		int cur =0;
		ll cns = 1;
		bool fg=0;
		repA(i,1,n){
			int ix1 = upper_bound(all(g[i]),cnt1[i])-g[i].begin();
			int ix2 = upper_bound(all(g[i]),cnt2[i])-g[i].begin();
			if(i==s[j]) {
				if(ix1==0) cns =0,fg=1;
				else if(g[i][ix1-1]!=cnt1[i]) cns=0,fg=1;
				else {
					cur++;
					if(ix2>=ix1) ix2--;
					ix1=0;
				}
			}
			if(ix1>ix2) swap(ix1,ix2);
			if(ix1>0&&ix2>1){
				cur+=2;
				cns=cns*(1ll*ix1*(ix2-1))%mod;
			}
			else if(ix1>0||ix2>0){
				cur++;
				cns=cns*(ix1+ix2)%mod;
			}
		}
		if(!fg){
			if(cur>mx) mx=cur,ans=cns;
			else if(cur==mx) ans=(ans+cns)%mod;
		}
	}
	cout<<mx<<' '<<ans;
	return 0;
}