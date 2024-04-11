/**
 *    author:  tourist
 *    created: 16.12.2018 17:53:20       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  const int MAX = 200010;
  vector<vector<int>> divs(MAX);
  for (int i = 1; i < MAX; i++) {
    for (int j = i; j < MAX; j += i) {
      divs[j].push_back(i);
    }
  }
  vector<long long> ans(1, 0);
  long long last = 0;
  for (int i = 0; i < n / 2; i++) {
    int x;
    cin >> x;
    long long best_y = -1, best_z = -1;
    for (int d : divs[x]) {
      // z + y = d, z - y = x / d
      long long z = d + x / d;
      long long y = d - x / d;
      if (z < 1 || y < 1 || z % 2 != 0 || y % 2 != 0 || y >= z) {
        continue;
      }
      z /= 2;
      y /= 2;
      if (y * y > last) {
        if (best_z == -1 || z < best_z) {
          best_z = z;
          best_y = y;
        }
      }
    }
    if (best_z == -1) {
      cout << "No" << '\n';
      return 0;
    }
    ans.push_back(best_y * best_y);
    ans.push_back(best_z * best_z);
    last = ans.back();
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i + 1] - ans[i];
  }
  cout << '\n';
  return 0;
}