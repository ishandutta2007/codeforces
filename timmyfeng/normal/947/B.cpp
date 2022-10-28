#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  long long offset = 0;
  multiset<long long> piles;
  for (int i = 0; i < n; ++i) {
    piles.insert(v[i] + offset);
    offset += t[i];
    long long ans = 1LL * int(piles.size()) * t[i];
    while (!piles.empty() && *piles.begin() <= offset) {
      ans -= offset - *piles.begin();
      piles.erase(piles.begin());
    }
    cout << ans << " ";
  }
  cout << "\n";
}