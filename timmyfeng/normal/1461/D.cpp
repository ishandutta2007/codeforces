#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

long long sum[N];
int a[N];

set<long long> pretty;

void dfs(int l, int r) {
  pretty.insert(sum[r + 1] - sum[l]);
  if (a[l] == a[r]) {
    return;
  }

  int m = (a[l] + a[r]) / 2;
  int i = upper_bound(a + l, a + r + 1, m) - a;
  dfs(l, i - 1);
  dfs(i, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + a[i];
    }

    pretty.clear();
    dfs(0, n - 1);

    while (q--) {
      int a;
      cin >> a;
      cout << (pretty.count(a) > 0 ? "Yes" : "No") << "\n";
    }
  }
}