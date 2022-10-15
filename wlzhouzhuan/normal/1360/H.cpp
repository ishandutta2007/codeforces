// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

string a[105];
ll n, m;
ll pw[66];

ll Rank(string s) {
  ll rk = 1;
  for (int i = 0; i < m; i++) {
    if (s[i] == '1') {
      rk += pw[m - 1 - i];
    }
  }
  for (rint i = 1; i <= n; i++) {
    if (a[i] < s) {
      rk--;
    }
  }
  return rk;
}
string pre(string s) {
  int tail = m - 1;
  while (tail >= 0 && s[tail] == '0') tail--;
  if (tail == -1) return "-1"; 
  s[tail] = '0';
  tail++;
  while (tail < m) s[tail++] = '1';
  return s;
}
string nxt(string s) {
  int tail = m - 1;
  while (s[tail] == '1') tail--;
  s[tail] = '1';
  tail++;
  while (tail < m) s[tail++] = '0';
  return s;
}
bool inc(string s) {
  for (int i = 1; i <= n; i++) {
    if (a[i] == s) {
      return 1;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i <= 63; i++) pw[i] = pw[i - 1] * 2ll;  
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    ll rank = ((1ll << m) - n + 1) / 2;
    string ans = "1";
    for (int i = 1; i < m; i++) ans += "0";
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    //cout << Rank(ans) << '\n';
    if (Rank(ans) > rank) {
      while (Rank(ans) > rank) ans = pre(ans);
    } else {
      while (Rank(ans) < rank) ans = nxt(ans);
    } 
    while (1) {
      string ans2 = pre(ans);
      if (ans2 != "-1" && Rank(ans2) == rank) {
        ans = ans2;
      } else {
        break;
      }
    }
    while (inc(ans)) ans = nxt(ans);
    cout << ans << '\n';
  }
}