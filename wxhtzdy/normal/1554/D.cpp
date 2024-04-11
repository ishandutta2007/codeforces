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
    for (int i = 0; i < n / 2; i++) cout << 'a';
    cout << 'n';
    if (n % 2 == 1 && n > 1) cout << 'j';
    for (int i = 0; i < n / 2 - 1; i++) cout << 'a';
    cout << "\n";
  }
  return 0;
}