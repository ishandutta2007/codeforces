#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> ans(k);
    iota(ans.begin(), ans.end(), 1);
    reverse(ans.begin() + 2 * k - n - 1, ans.end());

    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  }
}