#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      sum += a[i];
    } else {
      v.push_back(a[i]);
    }
  }
  sort(v.rbegin(), v.rend());
  if ((int) v.size() == 0) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < (int) v.size() -  1 + (int) v.size() % 2; i++) {
    sum += v[i];
  }
  cout << sum << '\n';
  return 0;
}