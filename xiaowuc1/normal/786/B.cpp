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

const int RAGETREE_SZ = 1 << 17;

vector<int> getNodes(int lhs, int rhs) {
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  vector<int> ret;
  while(lhs <= rhs) {
    if(lhs == rhs) {
      ret.push_back(lhs);
      return ret;
    }
    if(lhs%2) ret.push_back(lhs++);
    if(rhs%2==0) ret.push_back(rhs--);
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}

ll dp[2 * RAGETREE_SZ];
vector<pll> edges[2 * RAGETREE_SZ];

void dijkstra(int s) {
  memset(dp, 1, sizeof(dp));
  priority_queue<pll> q;
  dp[s] = 0;
  q.push({0, s});
  while(sz(q)) {
    pll curr = q.top(); q.pop();
    if(dp[curr.second] != -curr.first) continue;
    if(curr.second < RAGETREE_SZ) {
      if(dp[curr.second * 2] > dp[curr.second]) {
        dp[curr.second * 2] = dp[curr.second];
        q.push(pll(-dp[curr.second], 2 * curr.second));
      }
      if(dp[curr.second * 2 + 1] > dp[curr.second]) {
        dp[curr.second * 2 + 1] = dp[curr.second];
        q.push(pll(-dp[2 * curr.second + 1], 2 * curr.second + 1));
      }
    }
    while(curr.second >= 1) {
      for(pll out: edges[curr.second]) {
        int nd = out.first;
        ll nw = out.second - curr.first;
        if(nw < dp[nd]) {
          dp[nd] = nw;
          q.push({-nw, nd});
        }
      }
      edges[curr.second].clear();
      curr.second /= 2;
    }
  }
}

void solve() {
  int n, q, s;
  cin >> n >> q >> s;
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int v, u, w;
      cin >> v >> u >> w;
      edges[v+RAGETREE_SZ].push_back(pll(u+RAGETREE_SZ, w));
    }
    else {
      int v, l, r, w;
      cin >> v >> l >> r >> w;
      vector<int> actualnodes = getNodes(l, r);
      for(int out: actualnodes) {
        if(t == 2) {
          edges[v+RAGETREE_SZ].push_back(pll(out, w));
        }
        else {
          edges[out].push_back(pll(v+RAGETREE_SZ, w));
        }
      }
    }
  }
  dijkstra(s + RAGETREE_SZ);
  for(int i = 1; i <= n; i++) {
    if(i > 1) cout << " ";
    ll ret = dp[i + RAGETREE_SZ];
    if(ret >= 1e15) cout << "-1";
    else cout << ret;
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}