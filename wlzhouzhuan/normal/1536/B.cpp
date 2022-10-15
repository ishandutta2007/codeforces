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

const int N = 1005;
char a[N];
int n;

void solve() {
  set<string> s;
  scanf("%d%s", &n, a + 1);
  for (int i = 1; i <= n; i++) {
    string t = "";
    for (int j = i; j <= n && j <= i + 2; j++) {
      t += a[j];
      s.insert(t);
    }
  }
  for (char a = 'a'; a <= 'z'; a++) {
    string t = "";
    t += a;
    if (!s.count(t)) {
      cout << t << '\n';
      return ;
    }
  }
  for (char a = 'a'; a <= 'z'; a++) {
    for (char b = 'a'; b <= 'z'; b++) {
      string t = "";
      t += a;
      t += b;
      if (!s.count(t)) {
        cout << t << '\n';
        return ;
      }
    }
  }
  for (char a = 'a'; a <= 'z'; a++) {
    for (char b = 'a'; b <= 'z'; b++) {
      for (char c = 'a'; c <= 'z'; c++) {
        string t = "";
        t += a;
        t += b;
        t += c;
        if (!s.count(t)) {
          cout << t << '\n';
          return ;
        }
      }
    }
  }
  return ;
}

int main() {
  int T;
  for (T = read(); T; T--) {
    solve();
  }
  return 0;
}