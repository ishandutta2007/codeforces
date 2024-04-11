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

const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-10;

struct node {
  double x, y;
  void inp() {
    int a = read(), b = read(), c = read();
    x = a / 1.0 / (a + b + c);
    y = b / 1.0 / (a + b + c);
  }
  double ang() {
    double an = atan2(y, x);
    if (an < -eps) an += 2 * PI;
    return an;
  }
} O, a[N];
node operator - (node x, node y) {
  return node{x.x - y.x, x.y - y.y};
} 

int q, n;

struct cmp {
  bool operator () (const double x, const double y) {
    return x + eps < y;
  }
};
multiset<double, cmp> s;
int cnt1, cnt2;
void ins(node x) {
  if (fabs(x.x) < eps && fabs(x.y) < eps) {
    cnt1++; return ;
  }
  double ang = x.ang(), rot = ang + PI;
  if (rot >= 2 * PI - eps) rot -= 2 * PI;
  if (s.find(ang) == s.end() && s.find(rot) != s.end()) cnt2++;
  s.insert(ang);
}
void del(node x) {
  if (fabs(x.x) < eps && fabs(x.y) < eps) {
    cnt1--; return ;
  }
  double ang = x.ang(), rot = ang + PI;
  if (rot >= 2 * PI - eps) rot -= 2 * PI;
  s.erase(s.find(ang));
  if (s.find(ang) == s.end() && s.find(rot) != s.end()) cnt2--;
}

int main() {
  O.inp();
  q = read();
  while (q--) {
    char opt[5]; scanf("%s", opt);
    if (opt[0] == 'A') {
      ++n, a[n].inp();
      ins(a[n] - O);
    } else {
      int id = read();
      del(a[id] - O);
    }
    if (cnt1) { puts("1"); continue; }
    if (cnt2) { puts("2"); continue; }
    int ok = 1;
    if (s.size() <= 2) ok = 0;
    else {
      if (*--s.end() - *s.begin() <= PI) ok = 0;
      auto itr = s.lower_bound(PI), itl = itr;
      if (itr == s.begin() || itr == s.end()) ok = 0;
      else {
        itl--;
        if (*itr - *itl >= PI - eps) ok = 0;
      }
    }
    puts(ok ? "3" : "0");
  }
  return 0;
}