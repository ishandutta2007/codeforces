#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 0, r = n - 1;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (a[l] > a[r]) {
      if (i % 2 == 0) x += a[l++];
      else y += a[l++];
    } else {
      if (i % 2 == 0) x += a[r--];
      else y += a[r--];
    }
  }
  cout << x << " " << y << '\n';
  return 0;
}