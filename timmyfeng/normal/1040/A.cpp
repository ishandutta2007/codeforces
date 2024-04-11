#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int c[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  int ans = 0;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    int j = n - 1 - i;
    if (c[i] == 2) {
      if (c[j] == 0) {
        ans += a;
      } else if (c[j] == 1) {
        ans += b;
      } else {
        ans += min(a, b);
      }
    } else {
      ok &= (c[i] == c[j] || c[j] == 2);
    } 
  }

  cout << (ok ? ans : -1) << "\n";
}