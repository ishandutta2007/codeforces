#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      mp[p[i]]++;
    }
    bool ok = true;
    for (auto& c : mp) {
      if (c.second == 1) {
        ok = false;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        int ptr = i;
        while (ptr + 1 < n && p[ptr + 1] == p[i]) {
          ptr += 1;
        }
        cout << ptr + 1 << " ";
        for (int j = i; j < ptr; j++) {
          cout << j + 1 << " ";
        }
        i = ptr;
      }
      cout << '\n';
    }
  }
  return 0;
}