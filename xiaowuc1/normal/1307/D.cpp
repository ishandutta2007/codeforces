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
typedef vector<vector<ll>> matrix;

mt19937 g1;
inline ll get_random_int(ll a, ll b) {
  return uniform_int_distribution<ll>(a, b)(g1);
}

vector<int> edges[200005];
int n, m, k;
void bfs(int s, vector<int>& dp) {
  for(int i = 0; i < sz(dp); i++) dp[i] = 1e9;
  dp[s] = 0;
  queue<int> q;
  q.push(s);
  while(sz(q)) {
    int curr = q.front(); q.pop();
    for(int out: edges[curr]) {
      if(dp[out] > dp[curr] + 1) {
        dp[out] = dp[curr] + 1;
        q.push(out);
      }
    }
  }
}
vector<int> dps;
bool dumbsort(int a, int b) {
  return dps[a] < dps[b];
}
void solve() {
  cin >> n >> m >> k;
  vector<int> sss;
  for(int i = 0; i < k; i++) {
    int x;
    cin >> x;
    sss.push_back(x);
  }
  while(m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  vector<int> dpt;
  dps.resize(n+1);
  dpt.resize(n+1);
  bfs(1, dps);
  bfs(n, dpt);
  sort(all(sss), dumbsort);
  int ret = -1;
  g1.seed(std::chrono::system_clock::now().time_since_epoch().count());
  for(int i = 1; i < k; i++) {
    for(int dx = max(-i, -200); dx <= 200 && i + dx < sz(sss); dx++) {
      if(dx == 0) continue;
      int a = i;
      int b = i+dx;
      int cand = min(dps[n], 1 + min(dps[sss[a]] + dpt[sss[b]], dps[sss[b]] + dpt[sss[a]]));
      ret = max(ret, cand);
    }
  }
  for(int qq = 0; qq < 1e5; qq++) {
    int a = get_random_int(0, k-1);
    int b = get_random_int(0, k-1);
    if(a==b) continue;
    int cand = min(dps[n], 1 + min(dps[sss[a]] + dpt[sss[b]], dps[sss[b]] + dpt[sss[a]]));
    ret = max(ret, cand);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}