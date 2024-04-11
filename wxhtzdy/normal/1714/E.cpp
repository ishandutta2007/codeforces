/**
 *    author:  wxhtzdy
 *    created: 01.08.2022 16:55:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);             
  vector<vector<vector<vector<int>>>> was(10, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(10))));
  for (int d = 0; d < 10; d++) {
    for (int s = 0; s < 2; s++) {
      vector<int> que(1, d + s * 10);
      was[d][s][s][d] = 1;
      for (int b = 0; b < (int) que.size(); b++) {
        int nxt = (que[b] + que[b] % 10);
        int p = (nxt / 10) % 2;
        int q = (nxt % 10);
        if (!was[d][s][p][q]) {
          was[d][s][p][q] = 1;
          que.push_back(nxt);  
        }
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> have(10);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      have[a[i] % 10] += 1;
    }          
    if (have[5] + have[0] > 0) {
      if (have[5] + have[0] != n) {
        cout << "NO" << '\n';
        continue;
      }       
      for (int i = 0; i < n; i++) {
        while (a[i] % 10 != 0) {
          a[i] += (a[i] % 10);
        }
      }
      sort(a.begin(), a.end());
      cout << (a[0] != a[n - 1] ? "NO" : "YES") << '\n';   
      continue;
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      while ((a[i] % 10) % 2 != 0) {
        a[i] += (a[i] % 10);
      }
    }            
    vector<vector<int>> cnt(2, vector<int>(10));
    for (int i = 0; i < n; i++) {
      cnt[(a[i] / 10) % 2][a[i] % 10] += 1;
    }           
    for (int t = 0; t < 2; t++) {
      ok |= (cnt[t][2] + cnt[t][4] + cnt[t][8] + cnt[1 - t][6] == n);  
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}