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
    string b;
    cin >> b;
    string a = "1";
    for (int i = 1; i < n; i++) {
      a += '1';
      if (a[i] + b[i] == a[i - 1] + b[i - 1]) {
        a[i] = '0';
      }
    }
    cout << a << '\n';
  }
  return 0;
}