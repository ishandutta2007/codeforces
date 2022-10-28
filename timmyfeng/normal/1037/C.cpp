#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 1;

int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s, t;
  cin >> n >> s >> t;

  for (int i = 0; i < n; ++i) {
    ans[i + 1] = ans[i] + (s[i] != t[i]);
    if (i >= 1 && s[i] != t[i] && s[i - 1] != t[i - 1] && s[i] != s[i - 1]) {
      ans[i + 1] = min(ans[i + 1], ans[i - 1] + 1);
    }
  }

  cout << ans[n] << "\n";
}