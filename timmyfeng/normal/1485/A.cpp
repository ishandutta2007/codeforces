#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b) {
  if (b == 1) {
    return INT_MAX;
  } else if (a == 0) {
    return 0;
  }
  return 1 + calc(a / b, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;

    int ans = INT_MAX;
    for (int i = 0; i < 32; ++i) {
      ans = min(ans, calc(a, b + i) + i);
    }

    cout << ans << "\n";
  }
}