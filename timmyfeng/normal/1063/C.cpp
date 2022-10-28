#include <bits/stdc++.h>
using namespace std;

bool query(int x, int y) {
  cout << x << " " << y << endl;
  string res;
  cin >> res;
  return res == "white";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  bool init = query(0, 0);
  int cur = 0;
  if (n > 1) {
    int base = 1 << (n - 2);

    for (int i = 1; i < n; ++i) {
      int res = query(cur + base, 0);
      if (res == init) {
        cur += base;
      }
      base /= 2;
    }
  }

  cout << cur + 2 << " " << 3 << " " << cur + 1 << " " << 1 << endl;
}