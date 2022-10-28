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
typedef vector<ll> vi;
vector<vector<ll>> A;
ll f[509];
ll mod;
void pre(){
	A.resize(409,vector<ll>(409,0));
	f[0] = 1;
	f[1] = 1;
	repA(i,2,500) f[i] = f[i-1]*i%mod;
	repA(n,1,408){
		repA(k,1,n){
			if(k==1) A[n-1][k-1] = f[n];
			else if(k==n) A[n-1][k-1] = 1;
			else{
				repA(m,0,n-k){
					A[n-1][k-1]+=f[m+1]*A[n-m-2][k-2]%mod;
				}
				A[n-1][k-1]%=mod;
			}
		}
	}

}

void solve(){


}
ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}
ll modInverse(ll a,ll p){
	ll x,y;
	euclid(a,p,x,y);
	return ((x%p+p)%p);
}
int matInv(vector<vector<ll>>& A) {
	int n = sz(A); vi col(n);
	vector<vector<ll>> tmp(n, vector<ll>(n));
	tmp[0][0] = 1;
	repA(i,1,n-1) {
		ll x=0;
		rep(j,i){
			x-=A[i][j]*tmp[j][0]%mod;
		}
		tmp[i][0] = (x%mod)*modInverse(A[i][i],mod)%mod;
	}

	rep(i,n) rep(j,n) A[i][j] = tmp[i][j];
	return n;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n>>mod;
	pre();
	matInv(A);
	trace(A[1][0]);
	rep(i,409) if(i%2) A[i][0]+=2; else A[i][0]-=2;
	A[1][0] = -2;
	rep(i,n){
		int x;cin>>x;
		cout<<((-A[x-1][0])%mod+mod)%mod<<'\n';
	}
	return 0;
}