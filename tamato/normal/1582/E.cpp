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
  
  int NN = 500;
  int T; cin >> T;
  rep(t, T) {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) {
      cin >> A[N - 1 - i];
    }

    vector<ll> cs(N+1);
    rep(i, N) {
      cs[i+1] = cs[i] + A[i];
    }
    vector<ll> LDS(1); LDS[0] = 1000000000000000000;
    vector<vector<ll>> Q(N+1, vector<ll>(NN, 0));
    rep(i, N) {
      rep(lv, NN) {
        ll ss = Q[i][lv];
        if (ss != 0) {
          int l = LDS.size();
          if (l == lv) {
            LDS.push_back(ss);
          }
          else {
            LDS[lv] = max(LDS[lv], ss);
          }
        }
      }
      int l = LDS.size();
      rep(lv_, l) {
      int lv = lv_ + 1;
      if (i + lv - 1 > N - 1) continue;
      ll s = cs[i + lv] - cs[i];
      if (s < LDS[lv - 1]) {
        Q[i + lv][lv] = max(Q[i + lv][lv], s);
      }
      }
    }
    rep(lv, NN){
    ll ss = Q[N][lv];
    if (ss != 0) {
      int l = LDS.size();
      if (l == lv) {
        LDS.push_back(ss);
      }
      else {
        LDS[lv] = max(LDS[lv], ss);
      }
    }
    }
    cout << LDS.size() - 1 << "\n";

  }

}