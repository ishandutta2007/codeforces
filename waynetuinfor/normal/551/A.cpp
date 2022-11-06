#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
int n, a[maxn], b[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (a[j] > a[i]) ++ans;
    }
    cout << ans + 1 << ' ';
  }
  cout << '\n';
  return 0;
}