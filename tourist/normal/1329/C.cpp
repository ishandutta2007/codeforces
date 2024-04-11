/**
 *    author:  tourist
 *    created: 03.04.2020 17:59:07       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int pn = 1 << n;
    int pm = 1 << m;
    vector<int> a(pn);
    for (int i = 1; i < pn; i++) {
      cin >> a[i];
    }
    vector<int> que(1, 1);
    vector<int> seq;
    vector<int> path;
    for (int b = 0; b < (int) que.size(); b++) {
      while (true) {
        path.clear();
        int x = que[b];
        if (x >= pn || a[x] == 0) {
          break;
        }
        path.push_back(x);
        while (2 * x < pn) {
          int w = (a[2 * x] > a[2 * x + 1] ? 2 * x : 2 * x + 1);
          x = w;
          path.push_back(x);
        }
        int zeros = 0;
        for (int i = (int) path.size() - 1; i >= 0; i--) {
          if (a[path[i]] == 0) {
            ++zeros;
          } else {
            break;
          }
        }
        if (zeros < n - m) {
          for (int i = 0; i < (int) path.size() - 1; i++) {
            a[path[i]] = a[path[i + 1]];
          }
          a[path.back()] = 0;
          seq.push_back(que[b]);
        } else {
          for (int i = 1; i < (int) path.size(); i++) {
            que.push_back((path[i] & 1) ? path[i] - 1 : path[i] + 1);
          }
          break;
        }
      }
    }
    long long ans = 0;
    for (int i = 1; i < pm; i++) {
      ans += a[i];
    }
    cout << ans << '\n';
    for (int i = 0; i < (int) seq.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << seq[i];
    }
    cout << '\n';
  }
  return 0;
}