#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, Z;
    cin >> N >> Z;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      ans = max(ans, x | Z);
    }
    cout << ans << "\n";
  }
}