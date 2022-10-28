#include <bits/stdc++.h>
using namespace std;

const int A = 20;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;

    bool ok = true;
    vector<vector<int>> req(A);
    vector<vector<int>> pos(A);
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) {
        ok = false;
      } else if (a[i] < b[i]) {
        req[b[i] - 'a'].push_back(a[i] - 'a');
        pos[a[i] - 'a'].push_back(i);
      }
    }

    if (!ok) {
      cout << -1 << "\n";
      continue;
    }

    int ans = 0;
    for (int i = 0; i < A; ++i) {
      for (int j : req[i]) {
        if (!pos[j].empty()) {
          ++ans;
          for (int k : pos[j]) {
            a[k] = 'a' + i;
            if (a[k] < b[k]) {
              req[b[k] - 'a'].push_back(i);
            }
            pos[i].push_back(k);
          }
          pos[j].clear();
        }
      }
    }

    cout << ans << "\n";
  }
}