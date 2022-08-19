/**
 *    author:  tourist
 *    created: 03.03.2020 17:56:18       
**/
#include <bits/stdc++.h>

using namespace std;

int Get(int k) {
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    int from = i + 1;
    int to = k - i;
    if (from <= to) {
      ans += to - from + 1;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int k = 1;
  while (k <= n && Get(k) < m) {
    ++k;
  }
  if (k > n) {
    cout << -1 << '\n';
    return 0;
  }
  const int M = 100000;
  vector<int> a(n);
  for (int i = 0; i < n - k; i++) {
    a[i] = 3 * i + 1;
  }
  for (int i = n - k; i < n; i++) {
    a[i] = (i - (n - k) + 1) * M;
  }
  int cur = Get(k);
  while (cur > m) {
    a.back() += M;
    if (a.back() / M % 2 == 1) {
      a.back() += M;
    }
    cur -= 1;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << '\n';
  return 0;
}