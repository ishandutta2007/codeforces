#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

array<int, 2> sale[N];
int k[N], freq[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
    total += k[i];
  }

  for (int i = 0; i < m; ++i) {
    for (auto &j : sale[i]) {
      cin >> j;
      --j;
    }
  }
  sort(sale, sale + m);

  int lo = 0, hi = 2 * total;
  while (lo < hi) {
    int mid = (lo + hi) / 2;

    for (int i = 0; i < m && sale[i][0] < mid; ++i) {
      ++freq[sale[i][1]];
    }

    int burles = 0, saved = 0;
    for (int i = 0, j = 0; i < mid; ++i) {
      ++burles;
      for ( ; j < m && sale[j][0] <= i; ++j) {
        if (--freq[sale[j][1]] == 0) {
          saved += min(burles, k[sale[j][1]]);
          burles -= min(burles, k[sale[j][1]]);
        }
      }
    }

    if (burles >= (total - saved) * 2) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << "\n";
}