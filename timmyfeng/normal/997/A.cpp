#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x, y;
  string s;
  cin >> n >> x >> y >> s;

  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' && (i == 0 || s[i - 1] == '1')) {
      ++cnt;
    }
  }

  if (cnt == 0) {
    cout << 0 << "\n";
  } else if (x < y) {
    cout << (cnt - 1) * x + y << "\n";
  } else {
    cout << cnt * y << "\n";
  }
}