/**
 *    author:  tourist
 *    created: 05.01.2021 18:25:48       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, c, q;
    cin >> n >> c >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
    }
    vector<vector<long long>> ways(n + 1, vector<long long>(c + 1));
    for (int j = 0; j <= c; j++) {
      ways[n][j] = 1;
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j <= c; j++) {
        ways[i][j] = ways[i + 1][j];
        for (int k = 1; k <= j; k++) {
          if (i + k < n) {
            ways[i][j] += ways[i + k + 1][j - k];
          }
        }
      }
    }
    vector<vector<long long>> sumL(c + 1, vector<long long>(n + 1));
    vector<vector<long long>> sumR(c + 1, vector<long long>(n + 1));
    for (int rm = 0; rm <= c; rm++) {
      for (int i = 0; i < n; i++) {
        sumL[rm][i + 1] = sumL[rm][i];
        sumR[rm][i + 1] = sumR[rm][i];
        for (int k = 1; k <= rm; k++) {
          if (i + k < n) {
            if (p[i] < p[i + k]) {
              sumR[rm][i + 1] += ways[i + k + 1][rm - k];
            } else {
              sumL[rm][i + 1] += ways[i + k + 1][rm - k];
            }
          }
        }
      }
    }
    vector<int> order;
    while (q--) {
      int pos;
      long long id;
      cin >> pos >> id;
      --pos; --id;
      if (id >= ways[0][c]) {
        cout << -1 << '\n';
        continue;
      }
      int ans = -1;
      int i = 0;
      int rm = c;
      while (i < n) {
        assert(id < ways[i][rm]);
        int low = i, high = n;
        while (low < high) {
          int mid = (low + high + 1) >> 1;
          if (sumL[rm][mid] - sumL[rm][i] > id || sumR[rm][mid] - sumR[rm][i] > ways[i][rm] - 1 - id) {
            high = mid - 1;
          } else {
            low = mid;
          }
        }
        if (pos < low) {
          ans = p[pos];
          break;
        }
        id -= sumL[rm][low] - sumL[rm][i];
        assert(id >= 0 && id < ways[low][rm]);
        i = low;
        order.clear();
        for (int k = 0; k <= rm; k++) {
          if (i + k < n) {
            order.push_back(k);
          }
        }
        sort(order.begin(), order.end(), [&](int x, int y) {
          return p[i + x] < p[i + y];
        });
        int shift = -1;
        for (int v : order) {
          long long cur = ways[i + v + 1][rm - v];
          if (id < cur) {
            shift = v;
            break;
          }
          id -= cur;
        }
        assert(shift != -1);
        assert(shift != 0);
        if (pos <= i + shift) {
          ans = p[i + (i + shift) - pos];
          break;
        }
        i += shift + 1;
        rm -= shift;
      }
      assert(ans != -1);
      cout << ans + 1 << '\n';
    }
  }
  return 0;
}