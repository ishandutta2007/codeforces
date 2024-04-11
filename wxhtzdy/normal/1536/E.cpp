#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int md = 1e9 + 7;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '#') {
          cnt++;
        }
      }
    }
    int x = 0;
    if (n * m == cnt) {
      x = 1;
    }
    long long ans = 1;
    while (cnt--) {
      ans *= 2;
      ans %= md;
    }
    cout << ans - x << '\n';
  }
}