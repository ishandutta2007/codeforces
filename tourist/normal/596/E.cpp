#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

vector <int> rev[N];
char foo[N];
int on_cycle[N];
int digit[N], to[N];

bool found;

void dfs(int v, int pos) {
  if (pos < 0) {
    found = true;
  }
  if (found) {
    return;
  }
  int sz = rev[v].size();
  for (int j = 0; j < sz; j++) {
    int u = rev[v][j];
    if (on_cycle[u] != -1) {
      continue;
    }
    dfs(u, pos - (digit[u] == foo[pos] - '0'));
  }
}

int dx[42], dy[42];
int last[42];
bool vis[N];

const int NNN = 444;

char s[NNN][NNN];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int d = 0; d <= 9; d++) {
    scanf("%d %d", dx + d, dy + d);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int d = s[i][j] - '0';
      int x = i + dx[d];
      int y = j + dy[d];
      if (x < 0 || y < 0 || x >= n || y >= m) {
        x = i;
        y = j;
      }
      digit[i * m + j] = d;
      to[i * m + j] = x * m + y;
    }
  }
  n = n * m;
  for (int i = 0; i < n; i++) {
    vis[i] = false;
    rev[i].clear();
    on_cycle[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    rev[to[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
    int p = i;
    vector <int> cycle;
    while (!vis[p]) {
      cycle.push_back(p);
      vis[p] = true;
      p = to[p];
    }
    int id = -1;
    for (int i = 0; i < (int)cycle.size(); i++) {
      if (cycle[i] == p) {
        id = i;
        break;
      }
    }
    if (id == -1) {
      continue;
    }
    int mask = 0;
    for (int i = id; i < (int)cycle.size(); i++) {
      mask |= (1 << digit[cycle[i]]);
    }
    for (int i = id; i < (int)cycle.size(); i++) {
      on_cycle[cycle[i]] = mask;
    }
  }
  while (q--) {
    scanf("%s", foo);
    int len = strlen(foo);
    for (int d = 0; d <= 9; d++) {
      last[d] = -1;
    }
    for (int i = 0; i < len; i++) {
      last[foo[i] - '0'] = i;
    }
    found = false;
    for (int start = 0; start < n; start++) {
      if (on_cycle[start] == -1) {
        continue;
      }
      int pos = -1;
      for (int d = 0; d <= 9; d++) {
        if (on_cycle[start] & (1 << d)) {
          continue;
        }
        pos = max(pos, last[d]);
      }
      dfs(start, pos);
    }
    puts(found ? "YES" : "NO");
  }
  return 0;
}