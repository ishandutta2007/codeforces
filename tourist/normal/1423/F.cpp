/**
 *    author:  tourist
 *    created: 05.10.2020 18:11:30       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  long long sum = 0;
  long long cnt = 0;
  for (int i = 0; i < k; i++) {
    long long a, b;
    cin >> a >> b;
    sum += (n - a + 1) * b % n;
    cnt += b;
  }
  if (cnt != n) {
    cout << (cnt < n ? 1 : -1) << '\n';
    return 0;
  }
  long long expected = (long long) n * (n + 1) / 2;
  cout << (sum % n == expected % n ? 1 : -1) << '\n';
  return 0;
}