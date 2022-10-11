#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX_D = 17;

int n;
vector<int> bestIDs[100005];
vector<int> edges[100005];
int depth[100005];
int lca[100005][MAX_D];
vector<int> dp[100005][MAX_D];

vector<int> merge(vector<int>& a, vector<int>& b) {
  vector<int> ret;
  int i = 0;
  int j = 0;
  while(ret.size() < 10 && (i < a.size() || j < b.size())) {
    if(i == a.size()) ret.push_back(b[j++]);
    else if(j == b.size()) ret.push_back(a[i++]);
    else if(a[i] < b[j]) ret.push_back(a[i++]);
    else ret.push_back(b[j++]);
  }
  return ret;
}

vector<int> getLCA(int x, int y) {
  vector<int> ret;
  if(depth[x] < depth[y]) swap(x, y);
  for(int d = MAX_D-1; d >= 0; d--) {
    if(depth[x] - (1<<d) >= depth[y]) {
      ret = merge(ret, dp[x][d]);
      x = lca[x][d];
    }
  }
  for(int d = MAX_D-1; d >= 0; d--) {
    if(lca[x][d] != lca[y][d]) {
      ret = merge(ret, dp[x][d]);
      ret = merge(ret, dp[y][d]);
      x = lca[x][d];
      y = lca[y][d];
    }
  }
  if(x != y) {
    ret = merge(ret, dp[x][0]);
    ret = merge(ret, dp[y][0]);
    x = lca[x][0];
    y = lca[y][0];
  }
  ret = merge(ret, bestIDs[x]);
  return ret;
}

void genLCA() {
  for(int d = 1; d < MAX_D; d++) {
    for(int i = 1; i <= n; i++) {
      lca[i][d] = lca[lca[i][d-1]][d-1];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int out: bestIDs[i]) {
      dp[i][0].push_back(out);
    }
  }
  for(int d = 1; d < MAX_D; d++) {
    for(int i = 1; i <= n; i++) {
      dp[i][d] = merge(dp[i][d], dp[i][d-1]);
      dp[i][d] = merge(dp[i][d], dp[lca[i][d-1]][d-1]);
    }
  }
}

void dfs(int curr, int par) {
  for(int out: edges[curr]) {
    if(out == par) continue;
    depth[out] = depth[curr] + 1;
    lca[out][0] = curr;
    dfs(out, curr);
  }
}

void solve() {
  int m, q;
  cin >> n >> m >> q;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 1; i <= m; i++) {
    int loc;
    cin >> loc;
    if(bestIDs[loc].size() < 10) bestIDs[loc].push_back(i);
  }
  dfs(1, -1);
  genLCA();
  while(q--) {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> ret = getLCA(a, b);
    cout << min(c, (int)ret.size());
    for(int i = 0; i < c && i < ret.size(); i++) {
      cout << " " << ret[i];
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}