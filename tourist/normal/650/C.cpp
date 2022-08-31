#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

vector <int> eq[N], mr[N];
pair <int, int> b[N], c[N];
int a[N];
bool was[N];
int x[N];
int res[N];

int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  for (int i = 0; i < h * w; i++) {
    scanf("%d", a + i);
    eq[i].clear();
    mr[i].clear();
  }
  for (int row = 0; row < h; row++) {
    for (int j = 0; j < w; j++) {
      int id = row * w + j;
      b[j] = make_pair(a[id], id);
    }
    sort(b, b + w);
    for (int j = 1; j < w; j++) {
      int x = b[j].second;
      int y = b[j - 1].second;
      if (b[j].first == b[j - 1].first) {
        eq[x].push_back(y);
        eq[y].push_back(x);
      } else {
        mr[x].push_back(y);
      }
    }
  }
  for (int col = 0; col < w; col++) {
    for (int i = 0; i < h; i++) {
      int id = i * w + col;
      b[i] = make_pair(a[id], id);
    }
    sort(b, b + h);
    for (int j = 1; j < h; j++) {
      int x = b[j].second;
      int y = b[j - 1].second;
      if (b[j].first == b[j - 1].first) {
        eq[x].push_back(y);
        eq[y].push_back(x);
      } else {
        mr[x].push_back(y);
      }
    }
  }
  for (int i = 0; i < h * w; i++) {
    was[i] = false;
    c[i] = make_pair(a[i], i);
  }
  sort(c, c + h * w);
  for (int id = 0; id < h * w; id++) {
    int q = c[id].second;
    if (was[q]) {
      continue;
    }
    int b = 0, e = 0;
    x[0] = q;
    was[q] = true;
    while (b <= e) {
      int sz = eq[x[b]].size();
      for (int j = 0; j < sz; j++) {
        int u = eq[x[b]][j];
        if (!was[u]) {
          e++;
          x[e] = u;
          was[u] = true;
        }
      }
      b++;
    }
    e++;
    int put = 1;
    for (int jj = 0; jj < e; jj++) {
      int u = x[jj];
      int sz = mr[u].size();
      for (int j = 0; j < sz; j++) {
        int v = mr[u][j];
        put = max(put, res[v] + 1);
      }
    }
    for (int jj = 0; jj < e; jj++) {
      int u = x[jj];
      res[u] = put;
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j > 0) {
        putchar(' ');
      }
      printf("%d", res[i * w + j]);
    }
    printf("\n");
  }
  return 0;
}