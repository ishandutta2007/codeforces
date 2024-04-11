#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
int main() {
  int t; cin >> t;

  while(t--) {
      string s; cin >> s;
      long long ans = 0LL;
      vector<int> dp(s.length() + 1);
      dp[0] = 0;
      int lst1 = -1, lst0 = -1;
      for(int i = 0; i < s.length(); i++) {
        if(s[i] == '?') {
            dp[i + 1] = dp[i] + 1;
        }
        else if(s[i] == '0') {
            if(lst0 == -1 && lst1 == -1)
                dp[i + 1] = dp[i] + 1;
            else if(lst1 > lst0) {
                if((i - lst1) % 2)
                    dp[i + 1] = dp[lst1 + 1] + i - lst1;
                else
                    dp[i + 1] = i - lst1;
            }
            else {
                if((i - lst0) % 2 == 0)
                    dp[i + 1] = dp[lst0 + 1] + i - lst0;
                else
                    dp[i + 1] = i - lst0;
            }
            lst0 = i;
        }
        else if(s[i] == '1') {
            if(lst0 == -1 && lst1 == -1)
                dp[i + 1] = dp[i] + 1;
            else if(lst1 > lst0) {
                if((i - lst1) % 2 == 0)
                    dp[i + 1] = dp[lst1 + 1] + i - lst1;
                else
                    dp[i + 1] = i - lst1;
            }
            else {
                if((i - lst0) % 2)
                    dp[i + 1] = dp[lst0 + 1] + i - lst0;
                else
                    dp[i + 1] = i - lst0;
            }
            lst1 = i;
        }
      }
      for(int i = 1; i <= s.length(); i++) {
          ans += dp[i];
      }
      cout << ans << "\n";
  }
}