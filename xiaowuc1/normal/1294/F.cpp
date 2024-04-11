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

vector<int> edges[200005];
int deg[200005];
int dp[200005];
int par[200005];

int prop(int a, int b) {
  queue<int> q;
  memset(dp, 1, sizeof(dp));
  while(true) {
    dp[b] = 0;
    q.push(b);
    if(a == b) break;
    b = par[b];
  }
  int curr;
  while(sz(q)) {
    curr = q.front(); q.pop();
    for(int out: edges[curr]) {
      if(dp[out] > 1 + dp[curr]) {
        dp[out] = 1 + dp[curr];
        par[out] = curr;
        q.push(out);
      }
    }
  }
  return curr;
}

int bfs(int s) {
  memset(dp, 1, sizeof(dp));
  dp[s] = 0;
  queue<int> q;
  int curr;
  q.push(s);
  while(sz(q)) {
    curr = q.front(); q.pop();
    for(int out: edges[curr]) {
      if(dp[out] > 1 + dp[curr]) {
        dp[out] = 1 + dp[curr];
        par[out] = curr;
        q.push(out);
      }
    }
  }
  return curr;
}

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  vector<int> leaves;
  for(int i = 1; i <= n; i++) if(deg[i] == 1) leaves.push_back(i);
  if(sz(leaves) == 3) {
    cout << n-1 << "\n";
    cout << leaves[0] << " " << leaves[1] << " " << leaves[2] << "\n";
    return;
  }
  if(sz(leaves) == 2) {
    cout << n-1 << "\n";
    cout << leaves[0] << " " << leaves[1] << " ";
    int ret = 1;
    while(deg[ret] == 1) ret++;
    cout << ret << "\n";
    return;
  }
  int a = bfs(leaves[0]);
  int b = bfs(a);
  int ret = dp[b];
  int c = prop(a, b);
  ret += dp[c];
  cout << ret << "\n";
  cout << a << " " << b << " " << c << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}