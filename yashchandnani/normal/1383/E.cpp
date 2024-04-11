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
const ll mod = 1e9+7;
vi v;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	string s;cin>>s;
	int cnt = 0;
	trav(i,s){
		if(i=='1'){
			v.pb(cnt);
			cnt=0;
		}
		else cnt++;
	}
	v.pb(cnt);
	if(sz(v)==1){
		cout<<v[0];
	}
	else if(sz(v)==2){
		cout<<1ll*(v[0]+1)*(v[1]+1)%mod;
	}
	else{
		vector<pair<ll,int>> g;
		g.pb(mp(0,1e9));
		ll ans = v[0]+1;
		repA(i,1,sz(v)-2){
			int x = v[i],lst=-1;
			ll gg = 0;
			ll gans = ans;
			while(g.back().snd<x){
				gg+=(gans-g.back().fst)*(x-lst)%mod;
				gg%=mod;
				lst=g.back().snd;
				gans = g.back().fst;
				g.pop_back();
			}
			gg+=(gans-g.back().fst)*(x-lst)%mod;
			gg%=mod;
			g.pb(mp(ans,x));
			ans+=gg;
			ans%=mod;
		}
		ans=ans%mod;
		ans=ans*(v.back()+1)%mod;
		cout<<(ans+mod)%mod;
	}
	return 0;
}