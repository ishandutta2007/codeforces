#include <bits/stdc++.h>
using namespace std;

void inc(int &a, int n) {
  a = (a + 1 == n) ? 0 : a + 1;
}

void dec(int &a, int n) {
  a = (a == 0) ? n - 1 : a - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> points;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int k;
        cin >> k;
        points.push_back({i, j, k - 1});
      }
    }

    string s;
    cin >> s;

    vector<int> offset(3), axis(3);
    iota(axis.begin(), axis.end(), 0);

    for (auto c : s) {
      if (c == 'R') {
        inc(offset[axis[1]], n);
      } else if (c == 'L') {
        dec(offset[axis[1]], n);
      } else if (c == 'D') {
        inc(offset[axis[0]], n);
      } else if (c == 'U') {
        dec(offset[axis[0]], n);
      } else if (c == 'I') {
        swap(axis[1], axis[2]);
      } else if (c == 'C') {
        swap(axis[0], axis[2]);
      }
    }

    vector<vector<int>> ans(n, vector<int>(n));
    for (auto p : points) {
      array<int, 3> q;
      for (int i = 0; i < 3; ++i) {
        q[i] = (p[axis[i]] + offset[axis[i]]) % n;
      }
      ans[q[0]][q[1]] = q[2];
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << ans[i][j] + 1 << " ";
      }
      cout << "\n";
    }
  }
}