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
    int x = (int) s.size();
    int y = (int) t.size();
    while (x >= 0 && y >= 0) {
      if (s[x] == t[y]) x--, y--;
      else x -= 2;
    }
    cout << (y == -1 ? "YES\n" : "NO\n");
  }
}