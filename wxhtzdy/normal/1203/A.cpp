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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = false;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int i = 0; i < n; i++) {
      bool aa = true;
      for (int j = 0; j < n; j++) {
        if (a[(i + j) % n] != p[j]) aa = false;
      }
      if (aa) ok = true;
    }
    reverse(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
      bool aa = true;
      for (int j = 0; j < n; j++) {
        if (a[(i + j) % n] != p[j]) aa = false;
      }
      if (aa) ok = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}