#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;

ll a[N + 5];
int c[N + 5], l[N + 5], r[N + 5], L[N + 5], R[N + 5], cnt;
bool bl[N + 5], br[N + 5], bb[N + 5];
std::vector<int>vl[N + 5], vr[N + 5];

int fa[N + 5];
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void update(int Le, int Ri) {
  // printf("(%d %d)\n", Le, Ri);
  for (int x = find(Le); x <= Ri; x = find(Le)) {
    fa[x] = x + 1;
    for (auto p : vl[x]) {
      bl[p] = true;
      if (bl[p] && br[p] && !bb[p]) bb[p] = true, update(L[p], R[p]);
    }
    for (auto p : vr[x]) {
      br[p] = true;
      if (bl[p] && br[p] && !bb[p]) bb[p] = true, update(L[p], R[p]);
    }
  }
}
void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), a[i] += a[i - 1] - x;
  for (int i = 1; i <= m; i++) scanf("%d%d", &l[i], &r[i]), bl[i] = br[i] = bb[i] = false;
  if (a[n]) {puts("No"); return;}

  cnt = 0; for (int i = 0; i <= n; i++) if (!a[i]) c[++cnt] = i;
  for (int i = 1; i <= cnt + 1; i++) vl[i].clear(), vr[i].clear(), fa[i] = i;
  for (int i = 2; i <= cnt; i++) if (c[i] == c[i - 1] + 1) fa[i] = i + 1;
  for (int i = 1; i <= m; i++) {
    L[i] = std::lower_bound(c + 1, c + cnt + 1, l[i] - 1) - c + 1;
    R[i] = std::upper_bound(c + 1, c + cnt + 1, r[i]) - c - 1;
    vl[L[i] - 1].push_back(i), vr[R[i] + 1].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    bl[i] = (l[i] - 1 == c[L[i] - 1]) || (fa[L[i] - 1] != L[i] - 1);
    br[i] = (r[i] == c[R[i]]) || (fa[R[i] + 1] != R[i] + 1);
    if (bl[i] && br[i] && (!bb[i])) bb[i] = true, update(L[i], R[i]);
  }
  puts(find(2) == cnt + 1 ? "Yes" : "No");
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
}