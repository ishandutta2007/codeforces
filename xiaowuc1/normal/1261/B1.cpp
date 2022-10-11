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

ll l[105];
ll dp[105][105]; // idx, k -> max sum attainable
int n;
vector<pii> all;

void rsolve() {
  int len, idx;
  cin >> len >> idx;
  int lhs = -1;
  ll expect = dp[0][len];
  vector<int> ret;
  while(len > 0) {
    int cand = -1;
    for(int i = lhs+1; i < n; i++) {
      if(expect == l[i] + dp[i+1][len-1] && (cand == -1 || l[i] < l[cand])) {
        cand = i;
      }
    }
    assert(cand >= 0);
    ret.push_back(l[cand]);
    expect -= l[cand];
    lhs = cand;
    len--;
  }
  cout << ret[--idx] << "\n";
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    all.push_back({l[i], i});
  }
  sort(all(all));
  for(int k = 1; k <= n; k++) {
    for(int i = n-1; i >= 0; i--) {
      dp[i][k] = max(dp[i][k], dp[i+1][k]);
      dp[i][k] = max(dp[i][k], l[i] + dp[i+1][k-1]);
    }
  }
  int q;
  cin >> q;
  while(q--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}