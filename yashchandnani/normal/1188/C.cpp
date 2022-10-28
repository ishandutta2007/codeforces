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
const ll mod = 998244353;
ll f[1009],inv[1009];
void pre(){
	f[0] = f[1] = 1;
	inv[0] = inv[1] = 1;
	repA(i,2,1007){
		f[i] = f[i-1]*i%mod;
		inv[i] = mod-(mod/i)*inv[mod%i]%mod;
	}
	repA(i,2,1007) inv[i] = inv[i-1]*inv[i]%mod;
}
ll C(int n,int r){
	if(r<0||r>n) return 0;
	return f[n]*inv[r]%mod*inv[n-r]%mod;
}
ll dp[1009][1009];
int vis[1009][1009];
ll ans[300009];
int b[1009],nxt[1009];
int t;
ll solve(int n,int k){
	if(k==0) return 1;
	if(k>n) return 0;
	if(vis[n][k] == t) return dp[n][k];
	dp[n][k] = solve(n-1,k);
	while(b[n] - b[nxt[n]]<t) nxt[n]--;
	dp[n][k] += solve(nxt[n],k-1);
	dp[n][k]%=mod;
	vis[n][k] = t;
	return dp[n][k];
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,k;cin>>n>>k;
	pre();
	repA(i,1,n) cin>>b[i];
	sort(b+1,b+n+1);
	repA(i,1,n) nxt[i] = i-1;
	b[0] = -2e6;
	ans[0] = C(n,k);
	ll fns = 0;
	repA(i,1,100009){
		if(1ll*i*(k-1)>300009) {
			fns+= 1ll*(i-1)*(ans[i-1]-ans[i])%mod;
			break;
		}
		t = i;
		ans[i] = solve(n,k);
		fns+= 1ll*(i-1)*(ans[i-1]-ans[i])%mod;
	}
	cout<<(fns%mod+mod)%mod;

	return 0;
}