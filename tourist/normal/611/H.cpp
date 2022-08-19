#include <bits/stdc++.h>

using namespace std;

vector <int> all[42];
int a[42][42];
int sz[42];
int mx;

bool check() {
  int kd, d[42];
  for (int t = 1; t < (1 << mx); t++) {
    kd = 0;
    for (int i = 0; i < mx; i++) {
      if (t & (1 << i)) {
        d[kd++] = i;
      }
    }
    int vers = 0;
    int edges = 0;
    for (int i = 0; i < kd; i++) {
      vers += sz[d[i]];
    }
    for (int i = 0; i < kd; i++) {
      for (int j = 0; j < kd; j++) {
        edges += a[d[i]][d[j]];
      }
    }
    if (edges >= vers) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 42; i++) {
    all[i].clear();
  }
  mx = -1;
  for (int i = 1; i <= n; i++) {
    int len = 0;
    int tmp = i;
    while (tmp > 0) {
      len++;
      tmp /= 10;
    }
    all[len - 1].push_back(i);
    if (len > mx) mx = len;
  }
  for (int i = 0; i < mx; i++) {
    sz[i] = all[i].size();
  }
  for (int i = 0; i < mx; i++) {
    for (int j = 0; j < mx; j++) {
      a[i][j] = 0;
    }
  }
  char foo[42], bar[42];
  for (int i = 0; i < n - 1; i++) {
    scanf("%s %s", foo, bar);
    int x = strlen(foo);
    int y = strlen(bar);
    x--; y--;
    a[x][y]++;
  }
  if (!check()) {
    printf("%d\n", -1);
    return 0;
  }
  while (true) {
    bool found = false;
    for (int i = 0; i < mx; i++) {
      for (int j = 0; j < mx; j++) {
        if (a[i][j] == 0) {
          continue;
        }
        if (sz[i] > 1) {
          a[i][j]--;
          sz[i]--;
          if (check()) {
            printf("%d %d\n", all[i].back(), all[j][0]);
            all[i].pop_back();
            found = true;
            break;
          }
          sz[i]++;
          a[i][j]++;
        }
        if (sz[j] > 1) {
          a[i][j]--;
          sz[j]--;
          if (check()) {
            printf("%d %d\n", all[i][0], all[j].back());
            all[j].pop_back();
            found = true;
            break;
          }
          sz[j]++;
          a[i][j]++;
        }
      }
      if (found) {
        break;
      }
    }
    if (!found) {
      break;
    }
  }
  for (int i = 0; i < mx; i++) {
    assert(sz[i] == 1);
  }
  for (int i = 0; i < mx; i++) {
    for (int j = 0; j < mx; j++) {
      if (a[i][j] > 0) {
        printf("%d %d\n", all[i].back(), all[j].back());
      }
    }
  }
  return 0;
}