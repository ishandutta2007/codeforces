#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int n, a[maxn], b[maxn], cnta[6], cntb[6], ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i], cnta[a[i]]++;
  for (int i = 0; i < n; ++i) cin >> b[i], cntb[b[i]]++;
  for (int i = 1; i <= 5; ++i) {
    if ((cnta[i] + cntb[i]) & 1) return cout << "-1\n", 0;
    ans += (max(cnta[i], cntb[i]) - min(cnta[i], cntb[i])) / 2;
  }
  cout << ans / 2 << '\n';
  return 0;
}