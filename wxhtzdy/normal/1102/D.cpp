#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(3, 0);
  for (int i = 0; i < n; i++) {
    cnt[(int) (s[i] - '0')] += 1;
  }
  for (int i = 0; i < n; i++) {
    int ch = (int) (s[i] - '0');
    if (cnt[0] < n / 3 && ch > 0 && cnt[ch] > n / 3) {
      cnt[ch] -= 1;
      s[i] = '0';
      cnt[0] += 1;
    }
  }
  for (int i = 0; i < n; i++) {
    int ch = (int) (s[i] - '0');
    if (cnt[1] < n / 3 && ch > 1 && cnt[ch] > n / 3) {
      cnt[ch] -= 1;
      s[i] = '1';
      cnt[1] += 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    int ch = (int) (s[i] - '0');
    if (cnt[2] < n / 3 && ch < 2 && cnt[ch] > n / 3) {
      cnt[ch] -= 1;
      s[i] = '2';
      cnt[2] += 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    int ch = (int) (s[i] - '0');
    if (cnt[1] < n / 3 && ch < 1 && cnt[ch] > n / 3) {
      cnt[ch] -= 1;
      s[i] = '1';
      cnt[1] += 1;
    }
  }
  cout << s << '\n';
  return 0;
}