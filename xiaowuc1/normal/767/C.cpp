#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void die() {
  cout << "-1\n";
  exit(0);
}

vector<int> children[1000005];
int dp[1000005];
int n;
int all;
int root;

int dfs(int curr) {
  // return a vertex if it is one-third!
  vector<int> good;
  for(int out: children[curr]) {
    int ans = dfs(out);
    dp[curr] += dp[out];
    if(ans >= 0) good.push_back(ans);
    else if(dp[out] * 3 == all) {
      good.push_back(out);
    }
  }
  if(good.size() > 1) {
    cout << good[0] << " " << good[1] << "\n";
    exit(0);
  }
  if(curr == root) return -1;
  if(good.size() && 2 * all == 3 * dp[curr]) {
    cout << good[0] << " " << curr << "\n";
    exit(0);
  }
  if(good.size()) return good[0];
  return -1;
}

void solve() {
  cin >> n;
  root = -1;
  for(int i = 1; i <= n; i++) {
    int p, v;
    cin >> p >> v;
    all += v;
    if(p == 0) root = i;
    else children[p].push_back(i);
    dp[i] = v;
  }
  if(all%3 != 0) {
    die();
  }
  assert(root >= 0);
  dfs(root);
  die();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}