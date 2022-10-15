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
 
const int N = 140005;
const int inf = 1e9;
string s;
int cnt[N][26];
int n, ans;
 
void dfs(int l, int r, int let, int step) {
  //cerr << l << ' ' << r << ' ' << let << ' ' << step << '\n';
  if (l == r) {
    step += (cnt[r][let] - cnt[l - 1][let] == 0);
    ans = min(ans, step);
    return ;
  }
  int mid = l + r >> 1;
  int dlt = cnt[mid][let] - cnt[l - 1][let];
  dfs(mid + 1, r, let + 1, step + (mid - l + 1) - dlt);
  dlt = cnt[r][let] - cnt[mid][let]; 
  dfs(l, mid, let + 1, step + (r - mid) - dlt);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0); 
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        cnt[i][j] = cnt[i - 1][j];
      }
      s[i] -= 'a';
      cnt[i][s[i]]++;
    }
    ans = inf;
    dfs(1, n, 0, 0);
    cout << ans << '\n';
  }
  return 0;
}