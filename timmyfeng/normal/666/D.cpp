#include <bits/stdc++.h>
using namespace std;

int dist(int x1, int y1, int x2, int y2) {
  if (x1 != x2 && y1 != y2) {
    return INT_MAX;
  } else {
    return abs(x2 - x1) + abs(y2 - y1);
  }
}

int x[4], y[4], p[4], v[4];
int ans, xa[4], ya[4];

void calc(int x1, int x2, int y1, int y2) {
  iota(p, p + 4, 0);
  do {
    int res = max({
      dist(x[p[0]], y[p[0]], x1, y1),
      dist(x[p[1]], y[p[1]], x1, y2),
      dist(x[p[2]], y[p[2]], x2, y1),
      dist(x[p[3]], y[p[3]], x2, y2)
    });

    if (res < ans) {
      ans = res;
      xa[p[0]] = x1, ya[p[0]] = y1;
      xa[p[1]] = x1, ya[p[1]] = y2;
      xa[p[2]] = x2, ya[p[2]] = y1;
      xa[p[3]] = x2, ya[p[3]] = y2;
    }
  } while (next_permutation(p, p + 4));
}

void solve() {
  for (int i = 0; i < 4; ++i) {
    cin >> x[i] >> y[i];
  }

  ans = INT_MAX;

  for (int a1 = 0; a1 < 4; ++a1) {
    for (int a2 = a1 + 1; a2 < 4; ++a2) {
      int b1 = 0, b2 = 0;
      for ( ; b1 == a1 || b1 == a2; ++b1);
      for ( ; b2 == a1 || b2 == a2 || b2 == b1; ++b2);

      if (x[a1] == x[a2] && x[b1] == x[b2] && x[a1] < x[b1]) {
        int s = x[b1] - x[a1];
        v[0] = min(y[a1], y[a2]);
        v[1] = max(y[a1], y[a2]) - s;
        v[2] = min(y[b1], y[b2]);
        v[3] = max(y[b1], y[b2]) - s;
        sort(v, v + 4);
        int m = (v[3] + v[0]) / 2;
        calc(x[a1], x[b1], m, m + s);
      }

      if (y[a1] == y[a2] && y[b1] == y[b2] && y[a1] < y[b1]) {
        int s = y[b1] - y[a1];
        v[0] = min(x[a1], x[a2]);
        v[1] = max(x[a1], x[a2]) - s;
        v[2] = min(x[b1], x[b2]);
        v[3] = max(x[b1], x[b2]) - s;
        sort(v, v + 4);
        int m = (v[3] + v[0]) / 2;
        calc(m, m + s, y[a1], y[b1]);
      }
    }
  }

  for (int i = 0; i < (1 << 4); ++i) {
    int x1 = INT_MAX, x2 = INT_MIN;
    int y1 = INT_MAX, y2 = INT_MIN;
    for (int j = 0; j < 4; ++j) {
      if ((i & (1 << j)) == 0) {
        x1 = min(x1, x[j]);
        x2 = max(x2, x[j]);
      } else {
        y1 = min(y1, y[j]);
        y2 = max(y2, y[j]);
      }
    }

    if (y1 > y2 || x1 > x2 || (x1 == x2 && y1 == y2)) {
      continue;
    }

    if (x1 < x2 && y1 < y2 && x2 - x1 != y2 - y1) {
      continue;
    }

    int s = (x2 - x1) | (y2 - y1);
    if (x1 == x2) {
      calc(x1 - s, x2, y1, y2);
      calc(x1, x2 + s, y1, y2);
    } else if (y1 == y2) {
      calc(x1, x2, y1 - s, y2);
      calc(x1, x2, y1, y2 + s);
    } else {
      calc(x1, x2, y1, y2);
    }
  }

  if (ans == INT_MAX) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
    for (int i = 0; i < 4; ++i) {
      cout << xa[i] << " " << ya[i] << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}