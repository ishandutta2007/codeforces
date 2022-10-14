#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = n - i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j + 1 < n; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
    }
  }
  if (is_sorted(a.begin(), a.end())) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      cout << n - i << " ";
    }
  }                                                             
  return 0;
}