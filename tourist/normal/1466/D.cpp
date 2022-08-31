/**
 *    author:  tourist
 *    created: 30.12.2020 17:43:05       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> w(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> w[i];
      ans += w[i];
    }
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      deg[x] += 1;
      deg[y] += 1;
    }
    vector<int> seq;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < deg[i] - 1; j++) {
        seq.push_back(w[i]);
      }
    }
    sort(seq.rbegin(), seq.rend());
    cout << ans;
    for (int x : seq) {
      ans += x;
      cout << " " << ans;
    }
    cout << '\n';
  }
  return 0;
}