#include <bits/stdc++.h>
using namespace std;


int main() {
  vector<pair<int, int>> vp;
  for (int i = 0; i < 3; ++i) {
    int x, y; cin >> x >> y;
    vp.emplace_back(x, y);
  }

  sort(vp.begin(), vp.end());

  vector<tuple<int, int, int, int>> vs;

  vs.emplace_back(vp[0].first, vp[0].second, vp[1].first, vp[0].second);
  vs.emplace_back(vp[2].first, vp[2].second, vp[1].first, vp[2].second);

  int ymin = INT_MAX;
  int ymax = INT_MIN;

  for (auto [x, y] : vp) {
    ymin = min(ymin, y);
    ymax = max(ymax, y);
  }

  int atx = vp[1].first;

  vs.emplace_back(atx, ymin, atx, ymax);

  vector<tuple<int, int, int, int>> vs2;
  
  for (auto [a, b, c, d] : vs) {
    if (a == c and b == d) continue;
    assert(a == c || b == d);
    vs2.emplace_back(a, b, c, d);
  }

  cout << vs2.size() << endl;
  for (auto [a, b, c, d] : vs2) {
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  }

}