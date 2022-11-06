#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

const int SIGMA = 26, maxn = 100 + 5;
vector<int> G[SIGMA];
string s[maxn];
stack<int> topo;
bool v[SIGMA];
int N, len;

void DFS(int);
bool dfs(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> s[i], len = max(len, (int)s[i].length());
  for (int i = 1; i < N; ++i) {
    bool p = false;
    for (int j = 0; j < min(s[i].length(), s[i - 1].length()); ++j) {
      if (s[i][j] != s[i - 1][j]) { G[s[i - 1][j] - 'a'].push_back(s[i][j] - 'a'); p = true; break; }
    }
    if (!p) if (s[i - 1].length() > s[i].length()) { cout << "Impossible\n"; return 0; }
  }
  for (int i = 0; i < SIGMA; ++i) {
    memset(v, false, sizeof(v));
    if (!dfs(i, i)) { cout << "Impossible\n"; return 0; }
  }
  memset(v, false, sizeof(v));
  for (int i = 0; i < SIGMA; ++i) if (!v[i]) DFS(i);
  memset(v, false, sizeof(v));
  while (topo.size()) cout << (char)(topo.top() + 'a'), v[topo.top()] = true, topo.pop();
  for (int i = 0; i < SIGMA; ++i) if (!v[i]) cout << (char)(i + 'a');
  cout << '\n';
  return 0;
}

void DFS(int x) {
  v[x] = true;
  for (int u : G[x]) if (!v[u]) DFS(u);
  topo.push(x);
}

bool dfs(int x, int i) {
  v[x] = true;
  bool ret = true;
  for (int u : G[x]) {
    if (u == i) return false;
    if (!v[u]) ret &= dfs(u, i);
  }
  return ret;
}