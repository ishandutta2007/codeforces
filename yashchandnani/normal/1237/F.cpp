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
ll f[100009],inv[100009],p[100009];
const ll mod = 998244353;
ll C(int n,int r){
	if(n<0||r<0||r>n) return 0;
	return f[n]*inv[r]%mod*inv[n-r]%mod;
}
void pre(){
	f[0] = f[1] = inv[0] = inv[1] = 1;
	repA(i,2,100000) f[i] = f[i-1]*i%mod,inv[i] = mod-inv[mod%i]*(mod/i)%mod;
	repA(i,2,100000) inv[i] = inv[i]*inv[i-1]%mod;
	p[0] = 1;
	repA(i,2,100000) p[i] = p[i-2]*C(i,2)%mod,i++;
}

void solve(){


}
bool visx[4001],visy[4001];
ll ans1[4001][4001],ans2[4001][4001];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int h,w,n;cin>>h>>w>>n;
	rep(i,n){
		int x,y;
		cin>>x>>y;
		visx[x]=1;
		visy[y]=1;
		cin>>x>>y;
		visx[x]=1;
		visy[y]=1;
	}
	ans1[0][0] = 1;
	ans2[0][0] = 1;
	int cntx = h,cnty=w;
	repA(i,1,h){
		if(visx[i]) cntx--;
		if(visx[i]||visx[i-1]||i==1) {
			rep(j,h+1) ans1[i][j] = ans1[i-1][j];
		}
		else {
			rep(j,h+1) ans1[i][j] = (ans1[i-2][j-1]+ans1[i-1][j])%mod;
		}
	}
	repA(i,1,w){
		if(visy[i]) cnty--;
		if(visy[i]||visy[i-1]||i==1) {
			rep(j,h+1) ans2[i][j] = ans2[i-1][j];
		}
		else {
			rep(j,h+1) ans2[i][j] = (ans2[i-2][j-1]+ans2[i-1][j])%mod;
		}
	}
	ll fns = 0;
	rep(i,h+1) rep(j,w+1){
		ll cur = ans1[h][i]*ans2[w][j]%mod;
		cur = cur*C(cntx-2*i,j)%mod*C(cnty-2*j,i)%mod;
		cur=cur*f[i]%mod*f[j]%mod;
		fns+=cur;
	}
	cout<<fns%mod;
	return 0;
}