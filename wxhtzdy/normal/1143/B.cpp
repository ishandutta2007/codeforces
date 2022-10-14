#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> d;
  long long p = 1;
  while (n) {
    p *= n % 10;
    d.push_back(n % 10);
    n /= 10;
  }
  reverse(d.begin(), d.end());
  auto Calc = [&](vector<int> x) {
    long long res = 1;
    for (int i = 0; i < (int) x.size(); i++) {
      res *= x[i];
    }
    return res;
  };
  int m = (int) d.size();
  long long ans = pow(9, m - 1);
  for (int i = 0; i < (1 << m); i++) {
    vector<int> a;
    int lst = m + 1;
    for (int j = 0; j < m; j++) {
      if (((1 << j) & i) != 0) {
        a.push_back(d[j] - 1);
        lst = j + 1;
      } else {
        a.push_back(d[j]);
      }
    }
    for (int j = lst; j < m; j++) {
      a[j] = 9;
    }
    ans = max(ans, Calc(a));
  }
  cout << ans << '\n';
  return 0;
}