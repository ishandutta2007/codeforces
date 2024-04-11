#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
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
typedef vector<vector<ll>> matrix;

ll l[200005];
int n;
set<ll> used;
ll ret;

inline void compute(ll g) {
  if(g == 1 || used.count(g)) return;
  used.insert(g);
  ll cand = 0;
  for(int i = 0; i < n; i++) {
    if(l[i] < g) cand += g - l[i];
    else {
      ll thresh = l[i] % g;
      cand += min(thresh, g - thresh);
    }
  }
  ret = min(ret, cand);
}

inline void check(ll v) {
  if(v <= 1) return;
  for(ll i = 2; i * i <= v; i++) {
    if(v%i) continue;
    compute(i);
    while(v%i == 0) v /= i;
  }
  compute(v);
}

mt19937 g1;
ll get_random_int(ll a, ll b) {
  return uniform_int_distribution<ll>(a, b)(g1);
}
void solve() {
  g1.seed(std::chrono::system_clock::now().time_since_epoch().count());
  auto t = clock();
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  ret = 1e18;
  while(clock()-t < 2.4 * CLOCKS_PER_SEC) {
    int idx = get_random_int(0, n-1);
    int delta = get_random_int(-1, 1);
    check(l[idx] + delta);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}