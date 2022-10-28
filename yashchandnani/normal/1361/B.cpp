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
int cnt[1000029];
const ll mod = 1000000007; // faster if const
ll modpow(ll a, ll e) {
		if (e == 0) return 1;
			ll x = modpow(a * a % mod, e >> 1);
				return e & 1 ? x * a % mod : x;
}
vi vx;
void solve(){
	int n,p;cin>>n>>p;
	vi v(n); rep(i,n) cin>>v[i];
	if(p==1){
		cout<<n%2<<'\n';
		return;
	}
	sort(all(v));
	vx=v;
	ll ans=0;
	while(sz(v)){
		int x = v.back();v.pop_back();
		ans = modpow(p,x);
		while(sz(v)&&cnt[x]==0){
				int y = v.back();
				ans+=mod-modpow(p,y);
				while(cnt[y]==p-1) cnt[y]=0,y++;
				cnt[y]++;
				v.pop_back();
		}
		if(sz(v)){
			cnt[x]=0;	
		}
	}
	cout<<ans%mod<<'\n';
	trav(i,vx) repA(j,i,i+20) cnt[j]=0;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();
	return 0;
}