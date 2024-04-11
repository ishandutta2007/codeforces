#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

int a[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] -= i;
  }

  bool ok = true;
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    --b[i];
    if (i > 0) {
      ok &= a[b[i]] >= a[b[i - 1]];
    }
  }

  if (!ok) {
    cout << -1 << "\n";
    exit(0);
  }

  int ans = n - m;
  multiset<int> lis; 
  int min_a = INT_MIN;
  for (int i = 0, j = 0; i < n; ++i) {
    if (j < m && i == b[j]) {
      while (!lis.empty() && *(--lis.end()) > a[i]) {
        lis.erase(--lis.end());
      }
      ans -= lis.size();
      min_a = a[i];
      lis.clear();
      ++j;
    } else if (a[i] >= min_a) {
      auto it = lis.upper_bound(a[i]);
      if (it != lis.end()) {
        lis.erase(it);
      }
      lis.insert(a[i]);
    }
  }
  ans -= lis.size();

  cout << ans << "\n";
}