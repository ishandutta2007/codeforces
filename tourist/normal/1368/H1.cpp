/**
 *    author:  tourist
 *    created: 18.06.2020 20:01:54       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, tt;
  cin >> h >> w >> tt;
  string left;
  string right;
  string top;
  string bottom;
  cin >> left >> right >> top >> bottom;
  int ans = (int) 1e9;
  for (int rot = 0; rot < 2; rot++) {
    // B = 0, R = 1
    string let = "BR";
    vector<int> dp(2);
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < 2; j++) {
        dp[j] += (top[i] == let[1 - j]);
      }
    }
    for (int j = 0; j < 2; j++) {
      dp[j] += (left[0] == let[1 - j]);
      dp[j] += (right[0] == let[1 - j]);
    }
    for (int i = 1; i < h; i++) {
      vector<int> new_dp(2);
      for (int j = 0; j < 2; j++) {
        new_dp[j] = (int) 1e9;
        for (int k = 0; k < 2; k++) {
          new_dp[j] = min(new_dp[j], dp[k] + (j == k ? 0 : w));
        }
        new_dp[j] += (left[i] == let[1 - j]);
        new_dp[j] += (right[i] == let[1 - j]);
      }
      swap(dp, new_dp);
    }
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < 2; j++) {
        dp[j] += (bottom[i] == let[1 - j]);
      }
    }
    ans = min(ans, min(dp[0], dp[1]));
    swap(h, w);
    swap(top, left);
    swap(bottom, right);
  }
  cout << ans << '\n';
  return 0;
}