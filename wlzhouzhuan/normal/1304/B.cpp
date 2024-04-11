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

const int N = 10002;
vector <string> ans;
int vis[N];
string a[N];
int n, m;

int main() {
  cin >> n >> m;
  for (rint i = 1; i <= n; i++) {
    cin >> a[i];
  }  
  for (rint i = 1; i <= n; i++) {
    string b = a[i];
    reverse(b.begin(), b.end());
    for (rint j = i + 1; j <= n; j++) {
      if (a[j] == b) {
        ans.pb(a[i]);
        vis[i] = vis[j] = 1;
        break;
      }
    }
  }
  string ext = ""; int ok = 0;
  for (rint i = 1; i <= n; i++) {
    string b = a[i];
    reverse(b.begin(), b.end());
    if (!vis[i] && a[i] == b) {
      vis[i] = 1; ext = a[i];
      ok = 1; break;
    }
  }
  if (ok) {
    printf("%d\n", m * ans.size() * 2 + m);
    for (rint i = 0; i < ans.size(); i++) cout << ans[i];
    cout << ext;
    for (rint i = ans.size() - 1; i >= 0; i--) {
      string b = ans[i]; reverse(b.begin(), b.end());
      cout << b;
    }
  } else {
    printf("%d\n", m * ans.size() * 2);
    for (rint i = 0; i < ans.size(); i++) cout << ans[i];
    for (rint i = ans.size() - 1; i >= 0; i--) {
      string b = ans[i]; reverse(b.begin(), b.end());
      cout << b;
    }
  }
}