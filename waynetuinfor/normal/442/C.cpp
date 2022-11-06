#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), prv(n, -1), nxt(n, -1);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    if (i > 0) prv[i] = i - 1;
    if (i + 1 < n) nxt[i] = i + 1;
  }

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

  int64_t res = 0;
  for (int i = 0; i < n - 2; ++i) {
    if (nxt[ord[i]] == -1) {
      res += a[ord[i]];
      nxt[prv[ord[i]]] = -1;
    } else if (prv[ord[i]] == -1) {
      res += a[ord[i]];
      prv[nxt[ord[i]]] = -1;
    } else {
      res += min(a[prv[ord[i]]], a[nxt[ord[i]]]);
      nxt[prv[ord[i]]] = nxt[ord[i]];
      prv[nxt[ord[i]]] = prv[ord[i]];
    }
  }
  cout << res << "\n";
}