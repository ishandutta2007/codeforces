#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<int> ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  int k = n - 2 * count(s.begin(), s.end(), '1');
  if (k < 0) {
    cout << -1 << "\n";
    exit(0);
  }

  vector<int> zero;
  vector<int> one(k);
  iota(one.begin(), one.end(), 0);

  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      swap(one, zero);
    }

    if (one.empty()) {
      cout << -1 << "\n";
      exit(0);
    }
    ans[one.back()].push_back(i);
    zero.push_back(one.back());
    one.pop_back();

    if (s[i] == '1') {
      swap(one, zero);
    }
  }

  cout << k << "\n";
  for (int i = 0; i < k; ++i) {
    cout << ans[i].size() << " ";
    for (auto j : ans[i]) {
      cout << j + 1 << " ";
    }
    cout << "\n";
  }
}