#include <bits/stdc++.h>
//#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

long long pow(long long x, long long n, ll mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n bit 1  x^(2^i) 
        ret %= mod;
        x *= x;
        x %= mod;
        n >>= 1;  // n 1bit 
    }
    return ret;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll mod = 1000000007;
  ll N, Q; cin >> N >> Q;
  vector<int> F(3*N+4);
  F[0] = 1;
  rep(i_, 3*N+3) {
    int i=i_ + 1;
    if (i * 2 <= 3 * N + 3) {
      F[i] = ((F[i-1] * (3*N+3 - i + 1))%mod * pow(i, mod-2, mod))%mod;
    }
    else {
      F[i] = F[3*N+3 - i];
    }
  }
  rep(i, 3*N+1) {
    ll f = F[3 * N + 4 -i-1];
    F[3 * N + 4 -i-2] = (F[3 * N + 4 -i-2] - f * 3 + mod * 3)%mod;
    F[3 * N + 4 -i-3] = (F[3 * N + 4 -i-3] - f * 3 + mod * 3)%mod;
  }

  rep(q, Q) {
    int x; cin >> x;
    cout << F[x + 3] << "\n"; 
  }
  
  
}