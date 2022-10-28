#include <bits/stdc++.h>
using namespace std;

int ans[3], nxt[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  ans[0] = ans[1] = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    fill(nxt, nxt + 3, INT_MAX);
    for (int j = 0; j < 3; ++j) {
      if (ans[j] < INT_MAX) {
        for (int k = 0; k < 3; ++k) {
          if (k == 2 || ((a & (1 << k)) > 0 && j != k)) {
            nxt[k] = min(nxt[k], ans[j] + (k == 2));
          }
        }
      }
    }

    copy(nxt, nxt + 3, ans);
  }

  cout << *min_element(nxt, nxt + 3) << "\n";
}