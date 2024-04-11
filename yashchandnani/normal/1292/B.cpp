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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	ll x0,y0,ax,ay,bx,by;cin>>x0>>y0>>ax>>ay>>bx>>by;
	ll xs,ys,t;cin>>xs>>ys>>t;
	vector<pair<ll,ll>> v;
	v.pb(mp(x0,y0));
	ll lim = 2e16;
	while(ax*x0+bx<=lim&&ay*y0+by<=lim){
		x0 = ax*x0+bx;
		y0 = ay*y0+by;
		v.pb(mp(x0,y0));
	}
	lim = lim*100+lim/2;
	int ans = 0;
	rep(i,sz(v)){
		if(abs(xs-v[i].fst)+abs(ys-v[i].snd)<=t) ans=max(ans,1);
		rep(j,i){
			ll d = abs(v[i].fst-v[j].fst)+abs(v[i].snd-v[j].snd);
			if(d+abs(xs-v[i].fst)+abs(ys-v[i].snd)<=t) ans=max(ans,i-j+1);
			if(d+abs(xs-v[j].fst)+abs(ys-v[j].snd)<=t) ans=max(ans,i-j+1);
		}
	}
	cout<<ans;	
	return 0;
}