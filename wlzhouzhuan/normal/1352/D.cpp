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

const int N = 1001;
int a[N], n;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }   
    int l = 1, r = n;
    int cur = 1, game = 0;
    int A = 0, B = 0;
    while (1) {
      game++;
      // Alice
      int res = 0;
      while (l <= r && res < cur) {
        res += a[l++];
      }
      A += res;
      if (l > r) break;
      //cout << "game = " << game << "l, r = " << l << ' ' << r << '\n';
      game++;
      // Bob
      cur = res + 1;
      res = 0;
      while (l <= r && res < cur) {
        res += a[r--];
      }
      B += res;
      if (l > r) break;
      cur = res + 1;
      //cout << "game = " << game << "l, r = " << l << ' ' << r << '\n';
    }
    cout << game << ' ' << A << ' ' << B << '\n';
  } 
}