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

const int N = 200005;

int a[N];
int n, q, s, d;

int ans[N];
set<pii> ban;

bool chk(int l, int r) {
  auto it = ban.lower_bound({l, -1});
  if (it != ban.end() && it->fir <= r) return 1;
  return 0;
}
void cdq(int L, int R, vector<int> qry) {
  if (L == R) {
    for (auto v: qry) ans[v] = L;
    return ;
  }
  int k = L + R >> 1; //  [d-k, d+k]  
//  printf("cdq L = %d, R = %d, k = %d, qry = ", L, R, k); for (auto v: qry) printf("%d, ", v); puts("");
  vector<int> qL, qR;
  set<pii> zz;
  queue<int> q;
  for (auto i: qry) {
    int L1 = a[i] - (d + k), R1 = a[i] - (d - k);
    int L2 = a[i] + (d - k), R2 = a[i] + (d + k);
    if (chk(L1, R1) || chk(L2, R2)) {
      q.push(i);
//      printf("pre inq %d\n", i);
    } else {
      zz.insert({a[i], i});
    }
  }
  while (!q.empty()) { // O(nlogn)
    int u = q.front(); q.pop();
    qL.pb(u); //  qL 
    int L1 = a[u] - (d + k), R1 = a[u] - (d - k);
    int L2 = a[u] + (d - k), R2 = a[u] + (d + k);
//    printf("node u = %d, [%d, %d] + [%d, %d]\n", u, L1, R1, L2, R2);
    auto it = zz.lower_bound({L1, -1});
    while (it != zz.end() && it->fir <= R1) {
      auto nxt = next(it);
      q.push(it->sec);
      zz.erase(it);
      it = nxt;
    }
    it = zz.lower_bound({L2, -1});
    while (it != zz.end() && it->fir <= R2) {
      auto nxt = next(it);
      q.push(it->sec);
      zz.erase(it);
      it = nxt;
    }
  }
  for (auto i: zz) qR.pb(i.sec); //  qR
  cdq(L, k, qL);
  for (auto i: qL) ban.insert({a[i], i});
  cdq(k + 1, R, qR); 
}

int main() {
  memset(ans, -1, sizeof(ans));
  n = read(), q = read(), s = read(), d = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  vector<int> qry;
  for (int i = 1; i <= n; i++) if (i != s) qry.pb(i);
  ban.insert({a[s], s}), ans[s] = 0;
  cdq(0, 1e6, qry);
//  for (int i = 1; i <= n; i++) printf("ans[%d] = %d\n", i, ans[i]);
  while (q--) {
    int x = read(), t = read();
    puts(ans[x] <= t ? "Yes" : "No");
  }
  return 0;
}