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
    string s, t;
    cin >> s >> t;
    vector<int> a(26, 0), b(26, 0);
    for (int i = 0; i < n; i++) {
      a[(int) (s[i] - 'a')] += 1;
    }
    for (int i = 0; i < n; i++) {
      b[(int) (t[i] - 'a')] += 1;
    }
    vector<int> diff;
    for (int i = 0; i < 26; i++) {
      diff.push_back(a[i] - b[i]);
    }
    bool ok = true;
    int bal = 0;
    for (int i = 0; i < (int) diff.size(); i++) {
      if (diff[i] % k != 0) {
        ok = false;
      }
      bal += diff[i] / k;
      if (bal < 0) {
        ok = false;
      }
    }
    if (ok && bal == 0) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}