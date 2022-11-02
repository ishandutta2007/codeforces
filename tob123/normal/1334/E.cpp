#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 4e7;
const ll MOD = 998244353;

ll D;
bool np[n];
vector<ll> T;
ll F[n/100], F2[n/100];

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

ll choose(ll a, ll b){
  ll res = F[a]*F2[b]%MOD*F2[a-b]%MOD;
  //cerr << a << " " << b << "---> " << res << endl;
  return res;
}

ll magic(ll x){
  //cerr << "magic " << x << endl;
  vector<ll> r;
  ll sum = 0;
  for(ll d : T){
    ll cnt = 0;
    while(x%d == 0){
      x /= d;
      cnt++;
    }
    if(cnt)
      r.push_back(cnt);
    sum += cnt;
  }
  ll res = 1;
  for(ll x : r){
    //cerr << x << " ";
    res *= choose(sum, x);
    res %= MOD;
    sum -= x;
  }
  //cerr << endl;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> D;
  np[1] = np[0] = true;
  F[0] = F2[0] = 1;
  for(ll i=1; i<10000; i++){
    F[i] = i*F[i-1]%MOD;
    F2[i] = mod_inverse(F[i], MOD);
  }
  for(ll i=2; i<n; i++){
    if(!np[i]){
      if(D%i == 0)
        T.push_back(i);
      while(D%i == 0) D /= i;
      for(ll j=2*i; j<n; j+=i){
        np[j] = true;
      }
    }
  }
  if(D > 1)
    T.push_back(D);
  int Q;
  cin >> Q;
  while(Q--){
    ll u, v;
    cin >> u >> v;
    ll ggt = gcd(u, v);
    ll pos = magic(u/ggt) * magic(v/ggt) % MOD;
    cout << pos << "\n";
  }
}