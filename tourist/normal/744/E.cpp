#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

char foo[42][N];
int z[N];
char s[N];

void build_z(int n) {
  int l = 0, r = 0;
  z[0] = n;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}

vector < pair <int, int> > edges[N];
vector <int> g[N], gr[N];

void add(int x, int y, int z) {
//  cerr << "adding " << x << " " << y << " " << z << endl;
  edges[x].push_back(make_pair(y, z));
}

bool was[N];
int w[N], kw;

void dfs1(int v) {
  was[v] = true;
  for (int j = 0; j < (int) g[v].size(); j++) {
    int u = g[v][j];
    if (!was[u]) {
      dfs1(u);
    }
  }
  w[kw++] = v;
}

int c[N];
int of_c[N];

void dfs2(int v) {
  for (int j = 0; j < (int) gr[v].size(); j++) {
    int u = gr[v][j];
    if (c[u] == -1) {
      c[u] = c[v];
      of_c[c[u]]++;
      dfs2(u);
    }
  }
}

bool loop[N];
int start[N], finish[N];
int flen[N];
int vers;

bool test(int from, int to) {
  if (from > to) {
    return true;
  }
  for (int i = 0; i < vers; i++) {
    g[i].clear();
    gr[i].clear();
  }
  for (int i = 0; i < vers; i++) {
    was[i] = true;
    loop[i] = false;
  }
  was[0] = false;
  for (int j = 0; j < (int) edges[0].size(); j++) {
    g[0].push_back(edges[0][j].first);
    gr[edges[0][j].first].push_back(0);
  }
  for (int id = from; id <= to; id++) {
    for (int i = start[id]; i < finish[id]; i++) {
      was[i] = false;
      for (int j = 0; j < (int) edges[i].size(); j++) {
        int helper = edges[i][j].second;
        if (helper < from || helper > to) {
          continue;
        }
        if (i == edges[i][j].first) {
          loop[i] = true;
        }
        g[i].push_back(edges[i][j].first);
        gr[edges[i][j].first].push_back(i);
      }
    }
  }
  kw = 0;
  for (int i = 0; i < vers; i++) {
    if (was[i]) {
      continue;
    }
    dfs1(i);
  }
  for (int i = 0; i < vers; i++) {
    c[i] = -1;
  }
  int nc = 0;
  for (int id = kw - 1; id >= 0; id--) {
    int i = w[id];
    if (c[i] == -1) {
      of_c[nc] = 1;
      c[i] = nc++;
      dfs2(i);
    }
  }
  for (int id = from; id <= to; id++) {
    for (int i = start[id] + 1; i < finish[id]; i++) {
      if (of_c[c[i]] > 1 || loop[i]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int cnt;
  scanf("%d", &cnt);
  vers = 1;
  for (int i = 0; i < cnt; i++) {
    scanf("%s", foo[i]);
    flen[i] = strlen(foo[i]);
    start[i] = vers;
    vers += flen[i];
    finish[i] = vers;
    add(0, start[i], -1);
  }
  for (int i = 0; i < cnt; i++) {
    int n = 0;
    for (int j = 0; j < flen[i]; j++) {
      s[n++] = foo[i][j];
    }
    s[n++] = '#';
    int from = n;
    for (int q = 0; q < cnt; q++) {
      n = from;
      for (int j = 0; j < flen[q]; j++) {
        s[n++] = foo[q][j];
      }
      build_z(n);
      for (int j = 0; j < flen[q]; j++) {
        int x = flen[i];
        int y = flen[q] - j;
        if (z[from + j] != min(x, y)) {
          continue;
        }
//        cerr << "hi! " << i << " " << q << " " << j << " " << x << " " << y << " " << z[from + j] << endl;
        if (x == y) {
          add(start[q] + j, 0, i);
        } else {
          if (x < y) {
            add(start[q] + j, start[q] + j + x, i);
          } else {
            add(start[q] + j, start[i] + y, i);
          }
        }
      }
    }
  }
  int j = -1;
  int ans = 0;
  for (int i = 0; i < cnt; i++) {
    while (j + 1 < cnt) {
      if (!test(i, j + 1)) {
        break;
      }
      j++;
    }
    if (i <= j) {
      ans += j - i + 1;
    }
//    cerr << i << " -> " << j << endl;
  }
  printf("%d\n", ans);
  return 0;
}