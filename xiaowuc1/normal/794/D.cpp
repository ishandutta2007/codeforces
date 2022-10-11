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
typedef long double ld;

void die() {
  cout << "NO\n";
  exit(0);
}

set<int> edges[300005];
vector<int> adj[300005];
int n, m;
int dp[300005];

void bfs() {
  queue<int> q;
  memset(dp, 1, sizeof(dp));
  for(int i = 0; i < n && sz(q) == 0; i++) {
    if(sz(edges[i]) <= 1) {
      q.push(i);
      dp[i] = 1;
    }
  }
  if(sz(q) == 0) {
    die();
  }
  while(!q.empty()) {
    int curr = q.front(); q.pop();
    if(sz(edges[curr]) > 2) die();
    for(int out: edges[curr]) {
      if(dp[out] > 1 + dp[curr]) {
        dp[out] = 1 + dp[curr];
        q.push(out);
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) adj[i].push_back(i);
  while(m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  map<vector<int>, int> mapper;
  for(int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
    if(!mapper.count(adj[i])) {
      int x = sz(mapper);
      mapper[adj[i]] = x;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int out: adj[i]) {
      if(mapper[adj[i]] != mapper[adj[out]]) {
        edges[mapper[adj[i]]].insert(mapper[adj[out]]);
      }
    }
  }
  bfs();
  cout << "YES\n";
  for(int i = 1; i <= n; i++) {
    if(i > 1) cout << " ";
    cout << dp[mapper[adj[i]]];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}