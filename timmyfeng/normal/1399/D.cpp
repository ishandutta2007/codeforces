#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    vector<int> one;
    vector<int> zero;
    vector<int> ndx(n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        if (zero.empty()) {
          zero.push_back(++ans);
        }
        one.push_back(zero.back());
        ndx[i] = zero.back();
        zero.pop_back();
      } else {
        if (one.empty()) {
          one.push_back(++ans);
        }
        zero.push_back(one.back());
        ndx[i] = one.back();
        one.pop_back();
      }
    }

    cout << ans << "\n";
    for (int i : ndx) {
      cout << i << " ";
    }
    cout << "\n";
  }
}