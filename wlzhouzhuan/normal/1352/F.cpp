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
 
int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
void print(int x) {
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
 
int n0, n1, n2;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n0 >> n1 >> n2;
    string ans = "";
    if (n2) {
      for (int i = 1; i <= n2 + 1; i++) {
        ans = ans + "1";
      }
      for (int i = 1; i <= n1; i++) {
        if (i & 1) ans = ans + "0"; 
        else ans = ans + "1";
      }
      if (n1 & 1) {
        for (int i = 1; i <= n0; i++) {
          ans = ans + "0";
        }
      } else {
        ans = ans.substr(0, ans.size() - 1);
        for (int i = 1; i <= n0; i++) {
          ans = ans + "0";
        }
        ans = ans + "1";
      }
      cout << ans << '\n'; 
    } else {
      for (int i = 1; i <= n1 + 1; i++) {
        if (i & 1) ans = ans + "0";
        else ans = ans + "1";
      }
      if (n1 & 1) {
        ans = ans.substr(0, ans.size() - 1);
        for (int i = 1; i <= n0; i++) {
          ans = ans + "0";
        }
        ans = ans + "1";
      } else {
        for (int i = 1; i <= n0; i++) {
          ans = ans + "0";
        }
      }
      cout << ans << '\n';
    }
  }
}