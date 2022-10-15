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

const int N = 1000005;

struct ele {
  int val, pos;
  friend bool operator < (const ele &a, const ele &b) {
    return a.pos < b.pos;
  }
} a[N];
long long ans;
int n;

int main() {
  n = read();
  for (rint i = 1; i <= n; i++) {
    a[i].val = read();
    a[i].pos = a[i].val - i;
  }
  sort(a + 1, a + n + 1);
  for (rint i = 1; i <= n; i++) {
    int j = i;
    while (j < n&& a[j+1].pos==a[i].pos){j++;
    }
    long long val = 0;
    for (rint k = i; k <= j; k++)val+=a[k].val;
    ans=max(ans,val);
    i=j;
  }
  cout<<ans;
}