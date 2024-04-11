#include <bits/stdc++.h>
using namespace std;

bool query(int r1, int c1, int r2, int c2) {
  cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  string res;
  cin >> res;
  return res == "YES";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int r, c;
  string s, t;

  r = c = 1;
  for (int i = 0; i < n - 1; ++i) {
    if (query(r + 1, c, n, n)) {
      s += 'D', ++r;
    } else {
      s += 'R', ++c;
    }
  }

  r = c = n;
  for (int i = 0; i < n - 1; ++i) {
    if (query(1, 1, r, c - 1)) {
      t += 'R', --c;
    } else {
      t += 'D', --r;
    }
  }
  reverse(t.begin(), t.end());

  cout << "! " << s << t << endl;
}