#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m, k;
// edges[i] contains <j, id> saying edge to j, with id
vector<pii> edges[200005];
int dp[200005];
vector<string> ret;

char ans[200005];

vector<int> parEdges[200005];
// parEdges[i] contains <parent ID>

vector<int> ambiguous;

void dfs(int idx) {
  if(ret.size() == k) return;
  if(idx == ambiguous.size()) {
    ret.push_back(string(ans));
    return;
  }
  int from = ambiguous[idx];
  for(int a = 0; a < parEdges[from].size() && ret.size() <= k; a++) {
    ans[parEdges[from][a]] = '1';
    dfs(idx+1);
    ans[parEdges[from][a]] = '0';
  }
}

void genEdges() {
  for(int i = 1; i <= n; i++) {
    for(pii out: edges[i]) {
      if(dp[out.first] + 1 == dp[i]) {
        parEdges[i].push_back(out.second);
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(parEdges[i].size() == 1) {
      ans[parEdges[i][0]] = '1';
    }
    else if(parEdges[i].size() > 1) {
      ambiguous.push_back(i);
    }
  }
}

void bfs(int s) {
  for(int i = 1; i <= n; i++) {
    dp[i] = 1e6;
  }
  dp[s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(pii outEdge: edges[curr]) {
      int out = outEdge.first;
      if(dp[out] > dp[curr] + 1) {
        dp[out] = dp[curr] + 1;
        q.push(out);
      }
    }
  }
}

void solve() {
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ans[i] = '0';
    edges[a].push_back({b, i});
    edges[b].push_back({a, i});
  }
  bfs(1);
  genEdges();
  dfs(0);
  cout << ret.size() << "\n";
  for(string out: ret) {
    cout << out << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}