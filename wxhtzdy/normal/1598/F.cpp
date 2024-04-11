/**
 *    author: m371
 *    created: 10.10.2021 11:24:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> final(n);
  //vector<vector<int>> suff(n);    
  vector<int> mn(n);
  vector<vector<int>> cnt(n);
  vector<vector<int>> pref(n);
  vector<vector<vector<int>>> pos(n);
  for (int i = 0; i < n; i++) {
    int m = s[i].size();
    vector<int> bal(m); 
    cnt[i].resize(2 * m + 5);
    pos[i].resize(2 * m + 5);
    for (int j = 0; j < m; j++) {
      if (j > 0) {
        bal[j] = bal[j - 1];
      }
      bal[j] += (s[i][j] == '(' ? +1 : -1);
      cnt[i][bal[j] + m]++;
      pos[i][bal[j] + m].push_back(j);
    }
    final[i] = bal[m - 1];
    mn[i] = *min_element(bal.begin(), bal.end());
    pref[i].resize(m);
    pref[i][0] = bal[0];
    for (int j = 1; j < m; j++) {
      pref[i][j] = min(pref[i][j - 1], bal[j]);
    }
  }
  const int inf = 1e9;
  vector<vector<int>> dp(1 << n, vector<int>(2, -inf));
  dp[0][0] = 0;
  dp[0][1] = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int total = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        total += final[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        continue;
      }
      int nmask = mask ^ (1 << i);
      dp[nmask][1] = max(dp[nmask][1], dp[mask][1]);
      int bal = total + mn[i];
      if (bal >= 0) {
        int sz = s[i].size();  
        if (total >= -sz && total <= sz) {
          int ft = -total + sz;
          dp[nmask][0] = max(dp[nmask][0], dp[mask][0] + cnt[i][ft]);
        }
        dp[nmask][0] = max(dp[nmask][0], dp[mask][0]);
      } else {        
        if (dp[mask][0] == -inf) {
          continue;
        }
        if (total < 0) {
          dp[nmask][1] = max(dp[nmask][1], dp[mask][0]);
          continue;
        }
        int balance = 0, bonus = 0;
        int sz = s[i].size();
        if (total >= -sz && total <= sz) {
          int ft = -total + sz;
          int low = 0, high = pos[i][ft].size() - 1;
          while (low <= high) {
            int mid = low + high >> 1;
            int ppos = pos[i][ft][mid];
            if (total + pref[i][ppos] >= 0) {
              bonus = mid + 1;
              low = mid + 1;
            } else {
              high = mid - 1;
            }
          }
        }
        dp[nmask][1] = max(dp[nmask][1], dp[mask][0] + bonus);
      }
    }
  }
  /*for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << ": " << dp[mask][0] << '\n';     
  }*/
  
  cout << max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]) << '\n';
  return 0;
}