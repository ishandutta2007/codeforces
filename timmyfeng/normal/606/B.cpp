#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int n, m, x, y;
  cin >> n >> m >> x >> y >> s;

  set<array<int, 2>> mines;
  set<int> blow_up;

  for (int i = 0; i < (int) s.size(); ++i) {
    if (mines.count({x, y}) == 0) {
      mines.insert({x, y});
      blow_up.insert(i);
    }

    if (s[i] == 'U') {
      x -= (x > 1);
    } else if (s[i] == 'D') {
      x += (x < n);
    } else if (s[i] == 'L') {
      y -= (y > 1);
    } else {
      y += (y < m);
    }
  }

  for (int i = 0; i < (int) s.size(); ++i) {
    cout << blow_up.count(i) << " ";
  }
  cout << n * m - blow_up.size() << "\n";
}