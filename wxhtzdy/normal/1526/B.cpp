#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    bool ok = false;
    for (int i = 0; i < 10000; i++) {
        if (i * 111 <= x && (x - i * 111) % 11 == 0) {
            ok = true;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}