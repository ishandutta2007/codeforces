/**
 *    author:  tourist
 *    created: 29.12.2019 17:22:52       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MAX = 300;

int cnt[N * (MAX + 10)];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  long long ans = 0;
  for (int w = 0; w <= MAX; w++) {
    int c = n;
    cnt[c] += 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        c -= 1;
      } else {
        c += w;
      }
      ans += cnt[c]++;
    }
    c = n;
    cnt[c] -= 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        c -= 1;
      } else {
        c += w;
      }
      cnt[c]--;
    }
  }
  vector<int> ones;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      ones.push_back(i);
    }
  }
  int cnt = (int) ones.size();
  int i = 0;
  for (int p = 0; p < n; p++) {
    while (i < cnt && ones[i] < p) {
      ++i;
    }
    for (int j = i; j < cnt; j++) {
      if ((j - i + 1) * (MAX + 1) > n - cnt) {
        break;
      }
      int dist = ones[j] - ones[i];
      int inside = dist - (j - i);
      int L = ones[i] - p;
      int R = (j == cnt - 1 ? n - 1 - ones[j] : ones[j + 1] - ones[j] - 1);
      int from = max(MAX + 1, (inside + L + (j - i)) / (j - i + 1));
      int to = (inside + L + R) / (j - i + 1);
      if (from <= to) {
        ans += to - from + 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}