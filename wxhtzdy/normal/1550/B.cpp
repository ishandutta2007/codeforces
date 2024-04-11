#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
      if (i == 0 || s[i] != s[i - 1]) {
        cnt[s[i] - '0']++;
      }
    }
    if (b < 0) {
      cout << n * a + (1 + min(cnt[0], cnt[1])) * b << '\n'; 
    } else {
      cout << n * (a + b) << '\n';
    }
  }
  return 0;
}