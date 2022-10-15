// Author: wlzhouzhuan
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

const int N = 1005;
vector<pii> ans, ans1;
set<int> s[N];
int n;

int main() {
  n = read();
  for (int i = 1; i <= n - 3; i++) {
    int u = read(), v = read();
    if (u > v) swap(u, v);
    s[u].insert(v);
  }
  for (int i = 2; i <= n; i++) {
    while (s[i].size()) {
      int it1 = *--s[i].end(); s[i].erase(it1);
      int it2;
      if (s[i].empty()) it2 = i + 1;
      else {
        it2 = *--s[i].end();
      }
      ans.pb({i, it1});
      s[1].insert(it2);
    }
  }
  ans1 = ans, ans.clear();
  for (int i = 1; i <= n; i++) s[i].clear();
  for (int i = 1; i <= n - 3; i++) {
    int u = read(), v = read();
    if (u > v) swap(u, v);
    s[u].insert(v);
  }
  for (int i = 2; i <= n; i++) {
    while (s[i].size()) {
      int it1 = *--s[i].end(); s[i].erase(it1);
      int it2;
      if (s[i].empty()) it2 = i + 1;
      else {
        it2 = *--s[i].end();
      }
      ans.pb({1, it2});
      s[1].insert(it2);
    }
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", ans.size() + ans1.size());
  for (auto v: ans1) printf("%d %d\n", v.fir, v.sec);
  for (auto v: ans) printf("%d %d\n", v.fir, v.sec);
  return 0;
}