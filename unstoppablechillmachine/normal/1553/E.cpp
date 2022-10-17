#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), cnt(n);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[(i - a[i] + n) % n]++;
    }
    vector<int> answer;
    for (int i = 0; i < n; i++) {
      if (cnt[i] + 2 * m < n) {
        continue;
      }
      vector<int> to(n + 1);
      for (int j = 1; j <= n; j++) {
        to[j] = a[j] + i;
        if (to[j] > n) {
          to[j] -= n;
        } 
      }
      vector<bool> used(n + 1);
      int cnt_cycles = 0, bad = n;
      for (int j = 1; j <= n; j++) {
        if (!used[j]) {
          if (to[j] == j) {
            used[j] = true;
            bad--;
            continue;
          }
          cnt_cycles++;
          used[j] = true;
          int cur = to[j];
          while (cur != j) {
            used[cur] = true;
            cur = to[cur];
          }
        }
      }
      if (bad - cnt_cycles <= m) {
        answer.pb(i);
      }
    }
    cout << SZ(answer) << ' ';
    for (auto it : answer) {
      cout << it << ' ';
    }
    cout << '\n';
  }
}