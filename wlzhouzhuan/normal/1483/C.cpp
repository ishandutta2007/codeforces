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

const int N = 300005;
const ll inf = 1e15;
multiset<ll> s;
int n, h[N], b[N];
ll val[N], dp[N];
int stk[N], top;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        h[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        b[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        ll t = -inf;
        while (top && h[stk[top]] > h[i]) {
            t = max(t, val[top]);
            s.erase(s.find(val[top] + b[stk[top]]));
            val[top] = 0;
            top--;
        }
        t = max(t, dp[i - 1]);
        stk[++top] = i, val[top] = t, s.insert(t + b[i]); 
        dp[i] = *--s.end();
//        printf("dp[%d] = %d\n", i, dp[i]);
    }
    printf("%lld\n", dp[n]);
    return 0;
}