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
typedef pair<int, pii> state;

vector<int> edges[300005];
int dp[300005];

ll bfs(int s) {
  if(dp[s]) return 1;
  dp[s] = 1;
  int pos = 0;
  int neg = 0;
  queue<int> q;
  q.push(s);
  while(sz(q)) {
    s = q.front(); q.pop();
    if(dp[s] > 0) pos++;
    else neg++;
    for(int out: edges[s]) {
      if(dp[s] == dp[out]) return 0;
      if(dp[out] == 0) {
        dp[out] = -dp[s];
        q.push(out);
      }
    }
  }
  ll reta = 1;
  ll retb = 1;
  while(pos--) {
    reta *= 2;
    reta %= 998244353;
  }
  while(neg--) {
    retb *= 2;
    retb %= 998244353;
  }
  return reta + retb;
}

void rsolve() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) edges[i].clear();
  for(int i = 1; i <= n; i++) dp[i] = 0;
  while(m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  ll ret = 1;
  for(int i = 1; i <= n; i++) {
    ret *= bfs(i);
    ret %= 998244353;
  }
  cout << ret << "\n";
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