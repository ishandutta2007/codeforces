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
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>
 
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
 
const int N = 500005;
int a[N];
int n;
 
int main() {
  ios::sync_with_stdio(false), cin.tie(0); 
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int lst = n;
    while (lst > 1 && a[lst - 1] >= a[lst]) lst--;
    while (lst > 1 && a[lst - 1] <= a[lst]) lst--;
    lst--;
    cout << lst << '\n';
  }
  return 0;
}