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
typedef pair<ll, ll> pll;

bool comp[2005];
vector<int> primes;
const int MOD = 1 << 30;
map<ll, int> dp[303];

int solve(int idx, int aa, int bb, int cc) {
  if(idx < 0) return 1;
  /*
  if(aa < primes[idx]) aa = 1;
  if(bb < primes[idx]) bb = 1;
  if(cc < primes[idx]) cc = 1;
  */
  if(aa>bb) swap(aa, bb);
  if(aa>cc) swap(aa, cc);
  if(bb>cc) swap(bb, cc);
  if(aa+bb+cc == 3) return 1;
  ll key = aa;
  key <<= 11;
  key |= bb;
  key <<= 11;
  key |= cc;
  if(dp[idx].count(key)) return dp[idx][key];
  int ret = 0;
  for(int a = aa, aamt=0; a >= 1; a /= primes[idx], aamt++) {
    for(int b = bb, bamt=0; b >= 1; b /= primes[idx], bamt++) {
      for(int c = cc, camt=0; c >= 1; c /= primes[idx], camt++) {
        ret = (ret + ((aamt+bamt+camt+1LL) * solve(idx-1, a, b, c))) % MOD;
      }
    }
  }
  dp[idx][key] = ret;
  return ret;
}

void solve() {
  for(int i = 2; i < 2000; i++) for(int j = 2*i; j <= 2000; j += i) comp[j] = true;
  int a, b, c;
  cin >> a >> b >> c;
  for(int i = 2; i < 2000; i++) if(!comp[i]) primes.push_back(i);
  vector<int> cand;
  cand.push_back(a);
  cand.push_back(b);
  cand.push_back(c);
  sort(all(cand));
  cout << solve(sz(primes)-1, a, b, c) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}