#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  map<int, set<int>> row, col;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    row[x].insert(y);
    col[y].insert(x);
  }
  row[0].insert(0);
  col[0].insert(0);

  auto itr = row.begin(), itc = col.begin();
  map<int, array<int, 2>> segments;
  segments[0] = {0, 0};
  int r = 0, c = 0;

  while (itr != row.end() || itc != col.end()) {
    int length = min(
        (itr == row.end()) ? INT_MAX : itr->first - r,
        (itc == col.end()) ? INT_MAX : itc->first - c
    );

    if (length > 0) {
      segments[r] = {r + length - 1, r - c};
      r += length, c += length;
    }

    bool dr = (itr != row.end() && itr->first == r && *itr->second.begin() <= c);
    bool dc = (itc != col.end() && itc->first == c && *itc->second.begin() <= r);
    if (dr ^ dc) {
      ++(dr ? itr : itc);
    } else {
      if (itr->first == r) {
        ++itr;
      }
      if (itc->first == c) {
        ++itc;
      }
    }
    r += dr, c += dc;
  }

  segments[r] = {INT_MAX, r - c};

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    auto it = --segments.upper_bound(x);
    if ((x <= it->second[0] && x - y == it->second[1]) || row[x].count(y)) {
      cout << "LOSE\n";
    } else {
      cout << "WIN\n";
    }
  }
}