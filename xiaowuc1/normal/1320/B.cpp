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
vector<int> edgesr[200005];
int n, m;

int dp[200005];
void bfs(int s) {
  memset(dp, 1, sizeof(dp));
  dp[s] = 0;
  queue<int> q;
  q.push(s);
  while(sz(q)) {
    int curr = q.front(); q.pop();
    for(int out: edgesr[curr]) {
      if(dp[out] > 1 + dp[curr]) {
        dp[out] = 1 + dp[curr];
        q.push(out);
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edgesr[b].push_back(a);
  }
  int k;
  cin >> k;
  vector<int> path;
  for(int i = 0; i < k; i++) {
    int x;
    cin >> x;
    path.push_back(x);
  }
  bfs(path.back());
  int lhs = 0;
  int rhs = 0;
  for(int i = 0; i < k-1; i++) {
    bool can = dp[path[i+1]] - dp[path[i]] == -1;
    bool alt = false;
    for(int out: edges[path[i]]) {
      if(out != path[i+1] && dp[out] == dp[path[i]] - 1) {
        alt = true;
      }
    }
    if(!can) {
      lhs++;
      rhs++;
    }
    else if(alt) rhs++;
  }
  cout << lhs << " " << rhs << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}