// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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
const int mod = 1e9 + 7;

inline void add(int &x, int y) {
    x += y; if (x >= mod) x -= mod;    
}

char s[N];
int pre[N], lst[N], go1[N], go2[N], dp[N], n;
int start, ans;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) if (s[i] == '1') { start = i; break; }
    if (!start) return print(n, '\n'), 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = s[i] == '1' ? 0 : pre[i - 1] + 1;
    }
    for (int i = n; i >= 1; i--) {
        go1[i] = lst[pre[i] + 1];
        go2[i] = lst[0];
        lst[pre[i]] = i;
    }
    dp[start] = start;
    for (int i = start; i <= n; i++) {
        add(dp[go1[i]], dp[i]);
        add(dp[go2[i]], dp[i]);
        if (pre[i] <= pre[n]) add(ans, dp[i]);
    }
    print(ans, '\n');
    return 0;
}