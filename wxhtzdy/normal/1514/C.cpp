#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  long long p = 1;
  for (int i = 1; i < n - 1; i++) {
    if (__gcd(n, i) == 1) {
      ans.push_back(i);
      p *= i;
      p %= n;
    }
  }
  if (p == n - 1) {
    ans.push_back(n - 1);
  }
  cout << (int) ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  return 0;
}