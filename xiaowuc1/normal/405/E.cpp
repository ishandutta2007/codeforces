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

void die() {
  cout << "No solution\n";
  exit(0);
}

vector<int> edges[100005];
int ans[100005];
set<pii> ret;

bool seen[100005];

void dfs(int curr, int par = -1) {
  for(int out: edges[curr]) {
    if(out == par) continue;
    if(seen[out]) continue;
    seen[out] = true;
    dfs(out, curr);
    if(ans[out]%2 && ret.count({curr, out})) {
      ans[out]++;
      ans[curr]--;
      ret.erase({curr, out});
      ret.insert({out, curr});
    }
    if(ans[out]%2 && ret.count({out, curr})) {
      ans[out]--;
      ans[curr]++;
      ret.erase({out, curr});
      ret.insert({curr, out});
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ret.insert({a, b});
    edges[a].push_back(b);
    edges[b].push_back(a);
    ans[a]++;
  }
  seen[1] = true;
  dfs(1);
  for(int i = 1; i <= n; i++) {
    if(ans[i]%2) die();
  }
  auto it = ret.begin();
  while(it != ret.end()) {
    cout << it->second << " " << it->first << " ";
    it++;
    cout << it->second << "\n";
    it++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}