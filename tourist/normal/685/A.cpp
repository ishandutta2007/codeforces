#include <bits/stdc++.h>

using namespace std;

const int BASE = 7;

int calc(int x) {
  x--;
  int res = 0;
  if (x == 0) {
    res++;
  }
  while (x > 0) {
    x /= 7;
    res++;
  }
  return res;
}

bool was[BASE];
int n, m;
int dn, dm;
int ans;

void dfs(int ni, int mi, int na, int ma) {
  if (ni < dn) {
    for (int j = 0; j < BASE; j++) {
      if (!was[j]) {
        was[j] = true;
        dfs(ni + 1, mi, na * BASE + j, ma);
        was[j] = false;
      }
    }
    return;
  }
  if (mi < dm) {
    for (int j = 0; j < BASE; j++) {
      if (!was[j]) {
        was[j] = true;
        dfs(ni, mi + 1, na, ma * BASE + j);
        was[j] = false;
      }
    }
    return;
  }
  if (na < n && ma < m) {
    ans++;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  dn = calc(n);
  dm = calc(m);
  if (dn + dm > BASE) {
    printf("%d\n", 0);
    return 0;
  }
  for (int i = 0; i < BASE; i++) {
    was[i] = false;
  }
  ans = 0;
  dfs(0, 0, 0, 0);
  printf("%d\n", ans);
  return 0;
}