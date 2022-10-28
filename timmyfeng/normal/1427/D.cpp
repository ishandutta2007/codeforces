#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int low_a = (n + 1) / 2 + 1;
  int high_a = (n - 1) / 2 + 1;

  vector<vector<int>> ans;

  for (int i = 0; i < n; ++i) {
    vector<int> ans_i;
    if (i % 2 == 0) {
      int nxt = find(a.begin(), a.end(), --low_a) - a.begin() + 1;
      ans_i = {i, nxt - i, n - nxt};
    } else {
      int nxt = find(a.begin(), a.end(), ++high_a) - a.begin();
      ans_i = {nxt, n - i - nxt, i};
    }
    ans_i.erase(remove(ans_i.begin(), ans_i.end(), 0), ans_i.end());

    int cur = 0;
    vector<int> a_new;
    for (auto i : ans_i) {
      a_new.insert(a_new.begin(), a.begin() + cur, a.begin() + cur + i);
      cur += i;
    }
    swap(a, a_new);

    /*
    for (auto i : a) {
      cout << i << " ";
    }
    cout << "\n";
    */

    if (ans_i.size() > 1u) {
      ans.push_back(ans_i);
    }
  }

  cout << ans.size() << "\n";
  for (auto &i : ans) {
    cout << i.size() << " ";
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}