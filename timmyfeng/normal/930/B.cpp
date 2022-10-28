#include <bits/stdc++.h>
using namespace std;

const int A = 26;

vector<int> ndx[A];
int cnt[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  for (int i = 0; i < n; ++i) {
    ndx[s[i] - 'a'].push_back(i);
  }

  int ans = 0;
  for (int k = 0; k < A; ++k) {
    int res = 0;
    for (int i = 1; i < n; ++i) {
      memset(cnt, 0, sizeof cnt);
      for (int j : ndx[k]) {
        ++cnt[s[(j + i) % n] - 'a'];
      }
      int cur = 0;
      for (int j = 0; j < A; ++j) {
        cur += (cnt[j] == 1);
      }
      res = max(res, cur);
    }
    ans += res;
  }

  cout << fixed << setprecision(12) << 1.0 * ans / n << "\n";
}