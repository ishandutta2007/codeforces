#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int ans[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    ++a[l - 1];
    --a[r];
  }

  for (int i = 1; i < m; ++i) {
    a[i] += a[i - 1];
  }

  multiset<int> lis;
  for (int i = 0; i < m; ++i) {
    lis.insert(a[i]);
    auto it = lis.upper_bound(a[i]);
    if (it != lis.end()) {
      lis.erase(it);
    }
    ans[i + 1] += lis.size();
  }

  lis.clear();
  for (int i = m - 1; i >= 0; --i) {
    lis.insert(a[i]);
    auto it = lis.upper_bound(a[i]);
    if (it != lis.end()) {
      lis.erase(it);
    }
    ans[i] += lis.size();
  }

  cout << *max_element(ans, ans + m + 1) << "\n";
}