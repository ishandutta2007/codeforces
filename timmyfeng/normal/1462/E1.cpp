#include <bits/stdc++.h>
using namespace std;

long long choose(int n, int k) {
  if (k > n) {
    return 0;
  }

  long long res = 1;
  for (int i = 0; i < k; ++i) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t-- ){
    int n, m = 3, k = 2;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      while (j < n && a[j] - a[i] <= k) {
        ++j;
      }
      ans += choose(j - i - 1, m - 1);
    }

    cout << ans << "\n";
  }
}