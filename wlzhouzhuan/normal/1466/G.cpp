// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 1000005;
const int mod1 = 1000000007;
const int mod2 = 998244353; 
const int base = 137;

void add(int &x, int y) {
  x += y; if (x >= mod1) x -= mod1;
}

string s[N];
int bas1[N], bas2[N];
vector<int> hsh1[N], hsh2[N];
int thsh1[N], thsh2[N];
char tt[N], t[N];
int len[N], cur;
int n, m, q;

int zz[100005][26];
int pw[N], ipw[N];

int getHash1(int id, int l, int r) {
  if (l > r) return 0;
  return (hsh1[id][r] - 1ll * hsh1[id][l - 1] * bas1[r - l + 1] % mod1 + mod1) % mod1;
}
int getHash2(int id, int l, int r) {
  if (l > r) return 0;
  return (hsh2[id][r] - 1ll * hsh2[id][l - 1] * bas2[r - l + 1] % mod2 + mod2) % mod2;
}
int hsht1(int l, int r) {
  if (l > r) return 0;
  return (thsh1[r] - 1ll * thsh1[l - 1] * bas1[r - l + 1] % mod1 + mod1) % mod1;
}
int hsht2(int l, int r) {
  if (l > r) return 0;
  return (thsh2[r] - 1ll * thsh2[l - 1] * bas2[r - l + 1] % mod2 + mod2) % mod2;
}
int main() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = 2ll * pw[i - 1] % mod1;
  ipw[0] = 1;
  for (int i = 1; i < N; i++) ipw[i] = 1ll * (mod1 + 1) / 2 * ipw[i - 1] % mod1;
  bas1[0] = bas2[0] = 1;
  for (int i = 1; i < N; i++) {
    bas1[i] = 1ll * bas1[i - 1] * base % mod1;
    bas2[i] = 1ll * bas2[i - 1] * base % mod2;
  }
  scanf("%d%d", &n, &q);
  cin >> s[0];
  len[0] = s[0].size(), s[0] = ' ' + s[0];
  scanf("%s", tt + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) zz[i][j] = zz[i - 1][j];
    add(zz[i][tt[i] - 'a'], ipw[i]);
  }
  for (int i = 0; i <= n; i++) {
    if (i > 0) {
      cur = i;
      len[i] = 2 * len[i - 1] + 1;
      s[i].resize(len[i] + 1);
      for (int j = 1; j <= len[i - 1]; j++) s[i][j] = s[i - 1][j];
      s[i][len[i - 1] + 1] = tt[i];
      for (int j = 1; j <= len[i - 1]; j++) s[i][len[i - 1] + 1 + j] = s[i - 1][j];
    }
    //
//    printf("When i = %d, len = %d\n", i, len[i]);
//    for (int j = 1; j <= len[i]; j++) printf("%c", s[i][j]);
//    puts("");
    // 
    hsh1[i].resize(len[i] + 1), hsh2[i].resize(len[i] + 1);
    for (int j = 1; j <= len[i]; j++) {
      hsh1[i][j] = (1ll * hsh1[i][j - 1] * base + s[i][j]) % mod1;
      hsh2[i][j] = (1ll * hsh2[i][j - 1] * base + s[i][j]) % mod2;
    }
    if (len[i] >= 1000000) break;
  }
  while (q--) {
    int k;
    scanf("%d%s", &k, t + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= m; i++) {
      thsh1[i] = (1ll * thsh1[i - 1] * base + t[i]) % mod1;
      thsh2[i] = (1ll * thsh2[i - 1] * base + t[i]) % mod2;
    }
    int ans = 0;
    for (int i = 1; i <= len[0] - m + 1; i++) {
      if (getHash1(0, i, i + m - 1) == thsh1[m] && getHash2(0, i, i + m - 1) == thsh2[m]) {
        add(ans, pw[k]);
      }
    }
    if (k <= cur) {
      for (int i = 1; i <= k; i++) {
        int mid = (len[i] + 1) / 2;
        for (int j = max(1, mid - m + 1); j <= mid && j + m - 1 <= len[i]; j++) {
          if (getHash1(i, j, j + m - 1) == thsh1[m] && getHash2(i, j, j + m - 1) == thsh2[m]) {
            add(ans, pw[k - i]);
          }
        }
      }
    } else {
      for (int i = 1; i <= cur; i++) {
        int mid = (len[i] + 1) / 2;
        for (int j = max(1, mid - m + 1); j <= mid && j + m - 1 <= len[i]; j++) {
          if (getHash1(i, j, j + m - 1) == thsh1[m] && getHash2(i, j, j + m - 1) == thsh2[m]) {
            add(ans, pw[k - i]);
          }
        }
      }
      for (int i = 1; i <= m; i++) {
        int pre = i - 1, suf = m - i;
        if (getHash1(cur, len[cur] - pre + 1, len[cur]) == hsht1(1, pre) && getHash2(cur, len[cur] - pre + 1, len[cur]) == hsht2(1, pre) &&
            getHash1(cur, 1, suf) == hsht1(i + 1, m) && getHash2(cur, 1, suf) == hsht2(i + 1, m)) {
          int nums = (zz[k][t[i] - 'a'] - zz[cur][t[i] - 'a'] + mod1) % mod1;
          add(ans, 1ll * nums * pw[k] % mod1);
        }
      }
    }
    print(ans, '\n');
  }
}