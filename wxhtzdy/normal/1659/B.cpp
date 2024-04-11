#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ans(n);
    int op = 0;
    for (int i = 0; i < n; i++) {
      if (op == k) {
        break;
      }
      int c = (int) (s[i] - '0');
      if ((c + k) % 2 == 0) {
        ans[i] = 1;
        op++;
      }
    }
    ans[n - 1] += k - op;
    for (int i = 0; i < n; i++) {
      int c = (int) (s[i] - '0');
      cout << (c + k - ans[i]) % 2;
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}