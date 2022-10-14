#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 3005;
  vector<bool> pr(MAX, true);
  for (int i = 2; i < MAX; i++) {
    for (int j = i + i; j < MAX; j += i) {
      pr[j] = false;
    }
  }
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    int cnt = 0;
    for (int j = 2; j <= i; j++) {
      if (i % j == 0 && pr[j]) {
        cnt++;
      }
    }
    ans += cnt == 2;
  }
  cout << ans << '\n';
}