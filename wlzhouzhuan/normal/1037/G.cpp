// Author: wlzhouzhuan
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

const int N = 100005;

char s[N];
int pre[N][26], suf[N][26], n, q;
int f[N][26], g[N][26], id[26];

unordered_map<int, int> SG[N];
int game(int l, int r) {
  if (l > r) return 0;
  if (l == r) return 1;
  if (SG[l].count(r)) return SG[l][r];
  int tot = 0;
  for (int i = 0; i < 26; i++) {
    if (pre[r][i] < l) continue; 
    int a = suf[l][i], b = pre[r][i];
    tot |= 1 << (g[a][i] ^ g[b][i] ^ f[l][i] ^ game(b + 1, r));
  }
  for (int i = 0; i <= 26; i++) {
    if (!(tot >> i & 1)) {
      return SG[l][r] = i;
    }
  }
}

int main() {
  scanf("%s", s + 1), n = strlen(s + 1);
  for (int i = 1; i <= n; i++) s[i] -= 'a';
  for (int i = 1; i <= n; i++) {
    mcpy(pre[i], pre[i - 1]);
    pre[i][s[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    mcpy(suf[i], suf[i + 1]);
    suf[i][s[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    mcpy(g[i], g[i + 1]);
    iota(id, id + 26, 0);
    sort(id, id + 26, [&](int x, int y) {
      return suf[i][x] < suf[i][y];
    });
    for (int j = 0; j < 26; j++) {
      int x = id[j];
      if (suf[i][x] > i) f[i][x] = game(i, suf[i][x] - 1);
      if (suf[i][x] == i) g[i][x] ^= f[i + 1][x];
    }
  }
  q = read();
  while (q--) {
    int l = read(), r = read();
    puts(game(l, r) ? "Alice" : "Bob");
  }
  return 0;
}