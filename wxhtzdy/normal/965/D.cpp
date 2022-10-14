#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  int sum = 0;
  vector<int> v;
  for (int i = 0; i < n - 1; i++) {
    sum += a[i];
    if (i >= k) {
      sum -= a[i - k];
    }
    if (i >= k - 1) {
      v.push_back(sum);
    }
  }
  sort(v.begin(), v.end());
  cout << v[0] << '\n';
  return 0;
}