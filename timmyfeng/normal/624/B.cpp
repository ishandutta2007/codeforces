#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.rbegin(), a.rend());

  int prv = INT_MAX;
  long long ans = 0;
  for (auto i : a) {
    i = min(max(0, prv - 1), i);
    ans += i;
    prv = i;
  }

  cout << ans << "\n";
}