#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long s;
  cin >> n >> s;

  long long ans = 1e9;
  vector<int> a(n);
  for (int& i : a) {
    cin >> i;
    ans = min(ans, 1LL * i);
  }

  for (int i : a) {
    s -= i - ans;
  }

  if (s > 0) {
    ans -= (s - 1) / n + 1;
  }

  cout << max(-1LL, ans) << "\n";
}