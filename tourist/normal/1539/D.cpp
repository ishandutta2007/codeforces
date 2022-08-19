/**
 *    author:  tourist
 *    created: 20.06.2021 13:59:10       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long total = accumulate(a.begin(), a.end(), 0LL);
  long long ans = 2 * total;
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return b[i] > b[j];
  });
  long long ptr = total;
  for (int i : order) {
    long long take = max(0LL, min(ptr - b[i], a[i]));
    ans -= take;
    ptr -= take;
  }
  cout << ans << '\n';
  return 0;
}