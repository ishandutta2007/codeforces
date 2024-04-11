#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(3, 0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int sum = 0;
    for (int j = 0; j < (int) s.size(); j++) {
      sum += (int) (s[j] - '0');
    }
    cnt[sum % 3] += 1;
  }
  cout << cnt[0] / 2 + min(cnt[1], cnt[2]) << '\n';
  return 0;
}