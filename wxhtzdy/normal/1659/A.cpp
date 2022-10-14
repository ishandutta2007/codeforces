#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, r, b;
    cin >> n >> r >> b;
    int x = r / (b + 1);
    vector<int> sz;
    int rem = r - x * (b + 1);
    for (int i = 0; i < b + 1; i++) {
      sz.push_back(x + (rem > 0));
      rem -= 1;
    }
    string ans = "";
    for (int i = 0; i < b + 1; i++) {
      if (i > 0) {
        ans += 'B';
      }
      for (int j = 0; j < sz[i]; j++) {
        ans += 'R';
      }
    }
    cout << ans << '\n';
  }
  return 0;
}