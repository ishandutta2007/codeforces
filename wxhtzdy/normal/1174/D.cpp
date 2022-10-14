/**
 *  author: milos
 *  created: 04.01.2021 03:43:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> ans;
  ans.push_back(0);
  map<int, int> was;
  was[0] = 1;
  for (int i = 1; i < (1 << n); i++) {
    int j = x ^ i;
    if (!was[j]) {
      was[i] = true;
      ans.push_back(i);
    }
  }
  cout << (int) ans.size() - 1 << '\n';
  for (int i = 1; i < (int) ans.size(); i++) {
    cout << (ans[i] ^ ans[i - 1]) << " ";
  }
  return 0;
}