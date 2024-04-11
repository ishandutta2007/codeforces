#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size();
    bool ok = false;
    for (int i=0; i<n; i++) {
      string x = "";
      for (int j=i; j<n; j++) {
        x += s[j];
        if (x.size() > m) break;
        int k = j - 1;
        string y = x;
        while (k >= 0 && y.size() < m) {
          y += s[k];
          k--;
        }
        ok |= (y == t);
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}