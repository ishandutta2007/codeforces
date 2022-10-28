#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string r, b;
    cin >> n >> r >> b;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (r[i] < b[i]) {
        ++ans;
      } else if (r[i] > b[i]) {
        --ans;
      }
    }
    if (ans == 0) {
      cout << "EQUAL\n";
    } else if (ans < 0) {
      cout << "RED\n";
    } else {
      cout << "BLUE\n";
    }
  }
}