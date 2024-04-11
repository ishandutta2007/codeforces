#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

#include <unordered_map>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;
ll dp[51][51][51];
ll comb[51][51];

ll solve(int n, int withoutroot, int withroot) {
  if(withroot > n) return 0;
  if(dp[n][withoutroot][withroot] >= 0) return dp[n][withoutroot][withroot];
  dp[n][withoutroot][withroot] = 0;
  for(int lhs = 0; lhs <= n-1; lhs++) {
    int rhs = n-1-lhs;
    for(int lhswithout = 0; lhswithout <= withoutroot; lhswithout++) {
      for(int lhswith = lhswithout; lhswith <= lhswithout+1 && lhswith <= lhs; lhswith++) {
        for(int rhswithout = 0; rhswithout <= withoutroot; rhswithout++) {
          for(int rhswith = rhswithout; rhswith <= rhswithout+1 && rhswith <= rhs; rhswith++) {
            int newwithout = lhswith + rhswith;
            int newwith = newwithout;
            // match to lhs
            if(lhs) newwith = max(newwith, 1 + lhswithout + rhswith);
            // match to rhs
            if(rhs) newwith = max(newwith, 1 + rhswithout + lhswith);
            if(newwithout != withoutroot) continue;
            if(newwith != withroot) continue;
            ll scale = solve(lhs, lhswithout, lhswith) * solve(rhs, rhswithout, rhswith);
            scale %= MOD;
            scale *= comb[lhs+rhs][lhs];
            scale %= MOD;
            scale *= n;
            scale %= MOD;
            scale *= (MOD+1)/2;
            scale %= MOD;
            dp[n][withoutroot][withroot] += scale;
            if(dp[n][withoutroot][withroot] >= MOD) dp[n][withoutroot][withroot] -= MOD;
          }
        }
      }
    }
  }
  return dp[n][withoutroot][withroot];
}

ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r *= b;
      r %= m;
    }
    e /= 2;
    if(e) {
      b *= b;
      b %= m;
    }
  }
  return r;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 1;
  dp[1][0][0] = 1;
  int n, k;
  cin >> n >> k;
  comb[0][0] = 1;
  for(int i = 1; i <= n; i++) {
    comb[i][0] = 1;
    for(int j = 1; j <= i; j++) {
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
      comb[i][j] %= MOD;
    }
  }
  ll ret = 0;
  ret += solve(n, k, k) + solve(n, k-1, k);
  ret %= MOD;
  ret *= modpow(n, MOD-2, MOD);
  ret %= MOD;
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}