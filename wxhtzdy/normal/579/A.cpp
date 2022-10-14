#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  int cnt = 0;
  for (int i = 0; i < 32; i++) {
    if (x & (1 << i)) {
      cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}