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

vector<pii> edges[200005];
int depth[200005];
int treesz[200005];

ll retMin, retMax;
int n;

void dfsRet(int curr) {
  for(pii out: edges[curr]) {
    if(depth[out.first] != depth[curr] + 1) continue;
    dfsRet(out.first);
    if(treesz[out.first]%2) {
      retMin += out.second;
    }
    ll amt = min(treesz[out.first], n - treesz[out.first]);
    retMax += amt * out.second;
  }
}

void dfs(int curr) {
  treesz[curr] = 1;
  for(pii out: edges[curr]) {
    if(depth[out.first] > 1 + depth[curr]) {
      depth[out.first] = 1 + depth[curr];
      dfs(out.first);
      treesz[curr] += treesz[out.first];
    }
  }
}

void rsolve() {
  cin >> n;
  n *= 2;
  for(int i = 1; i <= n; i++) {
    edges[i].clear();
    depth[i] = 1e9;
  }
  for(int i = 1; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    edges[x].push_back({y, w});
    edges[y].push_back({x, w});
  }
  depth[1] = 0;
  dfs(1);
  retMin = 0;
  retMax = 0;
  dfsRet(1);
  cout << retMin << " " << retMax << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}