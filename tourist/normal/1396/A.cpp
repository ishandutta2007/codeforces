/**
 *    author:  tourist
 *    created: 30.08.2020 17:34:53       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 1 << " " << 1 << '\n';
    cout << 0 << '\n';
    cout << 1 << " " << 1 << '\n';
    cout << 0 << '\n';
    cout << 1 << " " << 1 << '\n';
    cout << -a[0] << '\n';
    return 0;
  }
  cout << 1 << " " << 1 << '\n';
  cout << -a[0] << '\n';
  a[0] = 0;
  cout << 2 << " " << n << '\n';
  for (int i = 2; i <= n; i++) {
    if (i > 2) {
      cout << " ";
    }
    long long add = (long long) (a[i - 1] % n) * (n - 1);
    cout << add;
    a[i - 1] += add;
  }
  cout << '\n';
  cout << 1 << " " << n << '\n';
  for (int i = 1; i <= n; i++) {
    if (i > 1) {
      cout << " ";
    }
    assert(a[i - 1] % n == 0);
    cout << -a[i - 1];
  }
  cout << '\n';
  return 0;
}