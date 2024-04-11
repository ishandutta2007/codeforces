#include <bits/stdc++.h>
using namespace std;

const int N = 12;

set<int> vals_a[N];
set<int> vals_b[N];
int a[N][2];
int b[N][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> a[i][0] >> a[i][1];
  }

  for (int i = 0; i < m; ++i) {
    cin >> b[i][0] >> b[i][1];
  }

  set<int> all;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      set<int> cur;
      for (int k = 0; k < 4; ++k) {
        if (a[i][k % 2] == b[j][k / 2]) {
          cur.insert(a[i][k % 2]);
        }
      }

      if (cur.size() == 1u) {
        all.insert(*cur.begin());
        vals_a[i].insert(*cur.begin());
        vals_b[j].insert(*cur.begin());
      }
    }
  }

  if (all.size() == 1u) {
    cout << *all.begin() << "\n";
  } else {
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, int(vals_a[i].size()));
    }
    for (int i = 0; i < m; ++i) {
      mx = max(mx, int(vals_b[i].size()));
    }
    cout << (mx == 1 ? 0 : -1) << "\n";
  }
}