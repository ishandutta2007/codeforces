/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 14:50:32
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }                                                                          
    vector<vector<int>> trie(1, vector<int>(2, -1));
    vector<vector<int>> val(1, vector<int>(2, -1));
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      int x = a[i] ^ i;
      int p = 0;
      for (int j = 29; j >= 0; j--) {
        int b = (x >> j) & 1;
        if (trie[p][b ^ 1] != -1) {
          dp[i] = max(dp[i], val[trie[p][b ^ 1]][i >> j & 1]);
        }            
        if (trie[p][b] == -1) {
          break;
        } else {
          p = trie[p][b];
        }
      }
      dp[i] += 1;
      p = 0;
      for (int j = 29; j >= 0; j--) {
        int b = (x >> j & 1);
        if (trie[p][b] == -1) {
          trie[p][b] = (int) trie.size();
          trie.push_back(vector<int>(2, -1));
          val.push_back(vector<int>(2, -1));  
        }
        p = trie[p][b];                                           
        val[p][a[i] >> j & 1] = max(val[p][a[i] >> j & 1], dp[i]);
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }                                                                    
  return 0;
}