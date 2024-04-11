/**
 *    author:  tourist
 *    created: 25.07.2021 17:38:52       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<bool> used(2 * n, false);
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) {
      cin >> a[i] >> b[i];
      --a[i]; --b[i];
      used[a[i]] = true;
      used[b[i]] = true;
    }
    vector<int> r;
    for (int i = 0; i < 2 * n; i++) {
      if (!used[i]) {
        r.push_back(i);
      }
    }
    int cnt = (int) r.size();
    for (int i = 0; i < cnt / 2; i++) {
      a.push_back(r[i]);
      b.push_back(r[i + cnt / 2]);
    }
    assert((int) a.size() == n);
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        swap(a[i], b[i]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i] < a[j] && a[j] < b[i] && b[i] < b[j]) {
          ans += 1;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}