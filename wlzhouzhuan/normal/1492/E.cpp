// Author: wlzhouzhuan
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

const int N = 250005;
vector<int> a[N];
int n, m;

int check(vector<int> a, vector<int> b) {
  int cnt = 0;
  for (int j = 0; j < m; j++) cnt += (a[j] != b[j]);
  return cnt;
}
bool check(vector<int> tmp) {
  for (int i = 0; i < n; i++) {
    if (check(tmp, a[i]) > 2) return 0; 
  }
  return 1;
}
bool maintain(vector<int> &tmp, int pos) {
  tmp[pos] = 0;
  for (int i = 0; i < n; i++) {
    int zz = check(tmp, a[i]);
    if (zz <= 2) continue;
    if (zz > 3) return 0;
    if (tmp[pos] != a[i][pos]) {
      if (!tmp[pos]) tmp[pos] = a[i][pos];
      else if (tmp[pos] != a[i][pos]) return 0;
    } else {
      return 0;
    }
  }
  if (!tmp[pos]) tmp[pos] = 1;
  return 1;
}
void out(vector<int> a) {
  puts("Yes");
  for (int j = 0; j < m; j++) print(a[j], " \n"[j == m - 1]);
  exit(0);
}
int main() {
  n = read(), m = read();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = read();
      a[i].pb(x);
    }
  }
  int dif = 0;
  for (int i = 1; i < n; i++) {
    dif = max(dif, check(a[0], a[i]));
  }
  if (dif <= 2) out(a[0]);
  if (dif > 4) return puts("No"), 0;
  for (int i = 1; i < n; i++) {
    int t = check(a[0], a[i]);
    if (t <= 2) continue;
    if (t == 3) {
      vector<int> pos;
      for (int j = 0; j < m; j++) {
        if (a[0][j] != a[i][j]) pos.pb(j);
      } 
      for (int rot1 = 0; rot1 < 3; rot1++) {
        for (int rot2 = 0; rot2 < 3; rot2++) if (rot1 != rot2) {
          vector<int> tmp = a[0];
          tmp[pos[rot1]] = a[i][pos[rot1]];
          if (maintain(tmp, pos[rot2])) {
            out(tmp);
          }
        }
      }
      return puts("No"), 0;
    } else { // t = 4
      vector<int> pos;
      for (int j = 0; j < m; j++) {
        if (a[0][j] != a[i][j]) pos.pb(j);
      } 
      for (int rot1 = 0; rot1 < 4; rot1++) {
        for (int rot2 = rot1 + 1; rot2 < 4; rot2++) {
          vector<int> tmp = a[0];
          tmp[pos[rot1]] = a[i][pos[rot1]];
          tmp[pos[rot2]] = a[i][pos[rot2]];
          if (check(tmp)) {
            out(tmp);
          }
        }
      }
      return puts("No"), 0;
    }
  }
  return 0;
}