#include <bits/stdc++.h>
using namespace std;

const int L = 60;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t sum = 0;
  multiset<int64_t> b;
  for (int i = 0; i < n; ++i) {
    int64_t a;
    cin >> a;
    b.insert(a);
    sum ^= a;
  }

  vector<int64_t> ans;
  while (!b.empty()) {
    int pre = b.size();

    for (int i = 0; i < L; ++i) {
      if (sum & (1LL << i)) {
        auto it = b.lower_bound(1LL << i);
        if (it != b.end() && *it < (2LL << i)) {
          ans.push_back(*it);
          sum ^= *it;
          b.erase(it);
          break;
        }
      }
    }

    if (int(b.size()) == pre) {
      cout << "No\n";
      exit(0);
    }
  }

  cout << "Yes\n";
  reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}