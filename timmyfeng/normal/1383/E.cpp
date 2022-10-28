#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;

int dp[N];
int cnt[N];
int link[N];
int nxt_cnt[N];

int add(int a, int b) {
  return (a += b) < MOD ? a : a - MOD;
}

int sub(int a, int b) {
  return (a -= b) < 0 ? a + MOD : a;
}

int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int ext_l = 0;
  while (ext_l < int(s.size()) && s[ext_l] == '0') {
    ++ext_l;
  }
  s = s.substr(ext_l);
  if (s.empty()) {
    cout << ext_l << "\n";
    exit(0);
  }

  int ext_r = 0;
  while (!s.empty() && s.back() == '0') {
    s.pop_back();
    ++ext_r;
  }

  int n = s.size();
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0') {
      cnt[i] = cnt[i - 1] + 1;
    }
  }

  fill(nxt_cnt, nxt_cnt + n, n);
  for (int i = n - 2; i >= 0; --i) {
    if (s[i] == '0') {
      link[i] = nxt_cnt[cnt[i] + 1];
      nxt_cnt[cnt[i]] = i;
    }
  }

  int nxt0 = 0;
  int nxt1 = 0;
  int ans = 0;
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    while (nxt0 < n && (nxt0 == i || s[nxt0] != '0')) {
      ++nxt0;
    }
    while (nxt1 < n && (nxt1 == i || s[nxt1] != '1')) {
      ++nxt1;
    }

    dp[nxt1] = add(dp[nxt1], dp[i]);
    if (s[i] == '0') {
      dp[link[i]] = add(dp[link[i]], dp[i]);
    } else {
      dp[nxt0] = add(dp[nxt0], dp[i]);
      ans = add(ans, dp[i]);
    }
  }

  cout << mul(ans, mul(ext_l + 1, ext_r + 1)) << "\n";
}