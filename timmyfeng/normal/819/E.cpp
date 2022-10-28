#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void solve(int n) {
  if (n == 3) {
    ans.push_back({1, 2, 3});
    ans.push_back({1, 2, 3});
  } else if (n == 4) {
    ans.push_back({1, 2, 3});
    ans.push_back({2, 3, 4});
    ans.push_back({3, 4, 1});
    ans.push_back({4, 1, 2});
  } else {
    solve(n - 2);
    ans.push_back({n - 1, 1, n});
    for (int i = 1; i < n - 2; ++i) {
      ans.push_back({n - 1, i, n, i + 1});
    }
    ans.push_back({n - 1, n - 2, n});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  solve(n);

  cout << ans.size() << "\n";
  for (auto &i : ans) {
    cout << i.size() << " ";
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}