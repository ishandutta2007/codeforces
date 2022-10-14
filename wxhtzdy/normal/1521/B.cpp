#include <bits/stdc++.h>
 
using namespace std;
 
void run_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mn = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < a[mn]) {
      mn = i;
    }
  }
  cout << n - 1 << '\n';
  for (int i = 0; i < n; i++) {
    if (i == mn) {
      continue;
    }
    cout << i + 1 << " " << mn + 1 << " ";
    if (i % 2 != mn % 2) {
      cout << a[mn] + 1 << " " << a[mn] << '\n';
    } else {
      cout << a[mn] << " " << a[mn] << '\n';
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    run_case();
  }
  return 0;
}