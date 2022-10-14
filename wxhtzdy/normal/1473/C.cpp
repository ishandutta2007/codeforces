/**
 *  author: milos
 *  created: 14.01.2021 15:58:40
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
    vector<int> a;
    for (int i = 1; i <= k; i++) {
      a.push_back(i);
    }          
    for (int i = 0; i < n - k; i++) {
      a.push_back(k - i - 1);
    }
    vector<int> ans;
    // 1 2 3 4 5 4 3 2
    // p1 p2 p3 p4 p5 p4 p3 p2
    // 1 2 3 4 5 4 3 2      1 + 2 + 3 + 2 + 1
    // 1 2 3 5 4 5 3 2      3 + 2 + 2 + 1
    // 1 2 5 3 4 4 5 2      4 + 1 +  
    // 1, 2, 3, 4, ..., n - k
    // we will have n - k - 1 -- n
    // 1 2 3 4 5 4 3 2
    // 
    //for (int i : a) cout << i << '\n';
    vector<int> was(n + 1, false);
    for (int i = n; i >= 1; i--) {
      if (!was[a[i - 1]]) {
        ans.push_back(a[i - 1]);
        was[a[i - 1]] = true;
      }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < k; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}