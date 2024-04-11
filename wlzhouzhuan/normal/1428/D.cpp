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
#define fir first
#define sec second

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

const int N = 100005;
vector<pair<int, int>> oup;
vector<int> one, two, three;
int to[N];
int a[N], n;
bool vis[N];

void NO() { puts("-1"); exit(0); }
 
int main() {
  n = read();
  for (int i = 0; i < n; i++) a[i] = read();
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0) continue;
    if (a[i] == 1) {
      one.push_back(i);
    } else if (a[i] == 2) {
      if (one.empty()) NO();
      to[i] = one.back(), one.pop_back();
      two.push_back(i);
    } else if (a[i] == 3) {
      if (!three.empty()) {
        to[i] = three.back(), three.pop_back();
      } else if (!two.empty()) {
        to[i] = two.back(), two.pop_back();
      } else if (!one.empty()) {
        to[i] = one.back(), one.pop_back();
      } else NO();
      three.push_back(i);
    }
  }
  int row = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 || vis[i]) continue;
    int col = i;
    while (true) {
      vis[col] = 1;
      if (a[col] == 1) {
        oup.emplace_back(row, col);
        row++;
        break;
      } else if (a[col] == 2) {
        oup.emplace_back(row, col);
        col = to[col];
      } else {
        oup.emplace_back(row, col);
        col = to[col];
        oup.emplace_back(row, col);
        row++; 
      }
    }
  }
  printf("%d\n", (int)oup.size());
  for(auto v: oup) printf("%d %d\n", v.first + 1, v.second + 1);
  return 0;
}