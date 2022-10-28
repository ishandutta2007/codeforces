#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int A = 32;

int sum[N], prefix[N][A], suffix[N][A];
int prv[N][A], nxt[N][A];

int solve(int, int);

int get_suffix(int i, int c) {
  if (suffix[i][c] == -1) {
    suffix[i][c] = solve(prv[i][c] + 1, i);
  }
  return suffix[i][c];
}

int get_prefix(int i, int c) {
  if (prefix[i][c] == -1) {
    prefix[i][c] = solve(i, nxt[i][c] - 1);
  }
  return prefix[i][c];
}

int solve(int l, int r) {
  if (l > r) {
    return 0;
  }

  unsigned int mask = 0;
  for (int i = 0; i < A; ++i) {
    if (nxt[l][i] <= r) {
      int grundy = sum[nxt[l][i]] ^ sum[prv[r][i]];
      grundy ^= get_prefix(l, i) ^ get_suffix(r, i);
      mask |= 1u << grundy;
    }
  }

  int mex = 0;
  while (mask % 2 == 1) {
    mask /= 2;
    ++mex;
  }
  return mex;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < A; ++j) {
      prv[i][j] = (i == 0) ? -1 : prv[i - 1][j];
      prefix[i][j] = -1;
    }
    prv[i][s[i] - 'a'] = i;
  }

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < A; ++j) {
      nxt[i][j] = (i == n - 1) ? n : nxt[i + 1][j];
      suffix[i][j] = -1;
    }
    nxt[i][s[i] - 'a'] = i;
  }

  for (int i = 1; i < n; ++i) {
    int j = prv[i - 1][s[i] - 'a'];
    if (j >= 0) {
      sum[i] = sum[j] ^ solve(j + 1, i - 1);
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << (solve(l - 1, r - 1) > 0 ? "Alice" : "Bob") << "\n";
  }
}