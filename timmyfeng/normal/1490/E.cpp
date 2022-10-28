#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<long long> a(n);
  map<long long, long long> sum;
  for (auto &i : a)
    cin >> i, sum[i] += i;

  for (auto it = ++sum.begin(); it != sum.end(); ++it) {
    auto prv = it;
    --prv;
    it->second += prv->second;
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    auto it = sum.find(a[i]);
    while (true) {
      auto nxt = --sum.upper_bound(it->second);
      if (it == nxt)
        break;
      it = nxt;
    }
    if (it == --sum.end())
      ans.push_back(i);
  }

  cout << ans.size() << "\n";
  for (auto i : ans)
    cout << i + 1 << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();
}