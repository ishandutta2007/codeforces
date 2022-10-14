#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      if ((int) (s[i] - '0') % 2 == 1) {
        v.push_back((int) (s[i] - '0'));
      }
    }
    if ((int) v.size() < 2) {
      cout << -1 << '\n';
    } else {
      cout << v[0] << v[1] << '\n';
    }
  }
  return 0;
}