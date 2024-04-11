/**
 *    author: m371
 *    created: 08.10.2021 17:50:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int sum = 0;
  long long pos = 0;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    pos += (long long) b * a;
    sum += b;
  }
  if (sum != n) {
    cout << (sum < n ? 1 : -1) << '\n';
    return 0;
  }
  long long x = (long long) n * (n + 1) / 2;
  cout << (x % n == pos % n ? 1 : -1) << '\n';
  return 0;
}