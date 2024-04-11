#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  multiset<int> bal;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    bal.insert(i - a[i]);
  }

  int cnt = 0;
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += cnt - a[i];
    bal.erase(bal.find(i - a[i]));
    if (i - cnt == *bal.begin()) {
      ++cnt;
    }
  }
  cout << ans << "\n";
}