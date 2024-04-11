#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

typedef pair<ll, ll> PLL;

// return a % b (positive value)
ll mod(ll a, ll b) {
	return ((a % b) + b) % b;
}

// return a^b mod m
ll powmod(ll a, ll b, ll m) {
	ll res = 1;
	while(b > 0)
		if(b & 1) res = (res * a) % m, --b;
		else a = (a * a) % m, b >>= 1;
	return res % m;
}

// computes gcd(a,b)
ll gcd(ll a, ll b) {
	ll tmp;
	while(b) {a %= b; swap(a, b); }
	return a;
}

// computes lcm(a,b)
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

// returns d = gcd(a,b); finds x,y such that d = ax + by
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
	ll xx = y = 0; ll yy = x = 1;
	while (b) {
		ll q = a / b; ll t = b; b = a % b;
		a = t; t = xx; xx = x - q * xx; x = t;
		t = yy; yy = y - q * yy; y = t;
	}
	return a;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
ll mod_inverse(ll a, ll n) {
	ll x, y;
	ll d = extended_euclid(a, n, x, y);
	if(d > 1) return -1;
	return mod(x, n);
}

const ll MOD = 998244353;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<vector<ll>> dp(N+1, vector<ll>(2));
  ll half = mod_inverse(2, MOD);
  dp[0][0] = 1;
  dp[0][1] = 0;
  for(int i=1; i<=N; i++){
    for(int j=0; j<2; j++){
      if(i > 1){
        dp[i][j] = dp[i-2][1]*half%MOD*half%MOD;
      }
      (dp[i][j] += dp[i-1][0]*half) %= MOD;
    }
  }
  cout << dp[N][0] << "\n";
}