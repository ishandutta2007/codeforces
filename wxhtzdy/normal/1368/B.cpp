#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long m = 1;
  int len = 10;
  string s = "codeforces";
  vector<long long> cnt(len, 1);
  while (m < n) {
    for (int i = 0; i < len; i++) {
      m /= cnt[i];
      cnt[i]++;
      m *= cnt[i];
      if (m >= n) {
        break;
      }
    }
  }
  for (int i = 0; i < len; i++) {
    for (long long j = 0; j < cnt[i]; j++) {
      cout << s[i];
    }
  }
  cout << '\n';
  return 0;
}