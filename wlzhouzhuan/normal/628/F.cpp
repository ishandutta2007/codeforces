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
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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

const ll inf = 1e18;

struct event {
  ll x, y;
  friend bool operator < (const event &a, const event &b) {
    return a.x < b.x;
  }
} ev[1000005];

// f[l][r][x][y]  [l,r] ( l>r ,)  x  y  
//  [l,r]  mn  mn+1 
ll f[16][16][16][16], sp[16];
ll k, n, b, q;

int main() {
//  freopen("B4_6.in", "r", stdin);
  k = 5;
  cin >> n >> b >> q;
//  cerr << clock() << '\n';
  for (int i = 1; i <= q; i++) ev[i].x = read(), ev[i].y = read();
//  cerr << clock() << '\n';
  ev[++q].x = 0, ev[q].y = 0;
  ev[++q].x = b, ev[q].y = n;
  sort(ev + 1, ev + q + 1);
  
//  cerr << "1: " << clock() << '\n';

//  for (int i = 1; i <= q; i++) {
//    printf("%lld %lld\n", ev[i].x, ev[i].y);
//  }
//  system("pause");

  for (int i = 1; i <= q; i++) {
    ll dif_x = ev[i].x - ev[i - 1].x;
    ll dif_y = ev[i].y - ev[i - 1].y;
    if (dif_y > dif_x) {
      puts("unfair");
      exit(0);
    } 
  }
  for (int i = 1; i <= q; i++) {
    ll L = ev[i - 1].x + 1, R = ev[i].x, bj = ev[i].y - ev[i - 1].y;
    static ll num[16], mn, mx;
    mn = inf, mx = -inf;
    for (int j = 0; j < k; j++) {
      num[j] = (R + k - j) / k - (L + k - 1 - j) / k;
      ckmin(mn, num[j]);
      ckmax(mx, num[j]);
    }
    
//    printf("working on %d, range [%d, %d]\n", i, L, R);
//    for (int j = 0; j < k; j++) printf("%lld ", num[j]); puts("");
    
    if (mn == mx) { //  
//      printf("type 1\n");
      for (int j = 0; j <= k; j++) sp[j] += min(0ll, mn * j - bj); 
    } else if (num[0] == mn && num[k - 1] == mn) { //  (->)
//      printf("type 2\n");
      for (int j = k - 1; num[j] == mn; j--) L = j;
      for (int j = 0; num[j] == mn; j++) R = j;
//      printf("L = %d, R = %d\n", L, R);
      int len = k - L + R + 1;
      for (int t1 = 0; t1 <= len; t1++) {
        for (int t2 = 0; t2 <= k - len; t2++) {
          f[L][R][t1][t2] += min(0ll, -bj + mn * t1 + (mn + 1) * t2);
        }
      }
    } else { //  
//      printf("type 3\n");
      L = 0, R = k - 1;
      while (num[L] != mn) L++; while (num[R] != mn) R--;
//      printf("L = %d, R = %d\n", L, R);
      int len = R - L + 1;
      for (int t1 = 0; t1 <= len; t1++) {
        for (int t2 = 0; t2 <= k - len; t2++) {
          f[L][R][t1][t2] += min(0ll, -bj + mn * t1 + (mn + 1) * t2);
        }
      }
    }
  }
//  cerr << "2: " << clock() << '\n';

  for (int st = 0; st < 1 << k; st++) {
    ll coef = 0;
    static int pre[16];
    for (int i = 0; i < k; i++) {
      if (!i) pre[i] = (st >> i & 1);
      else pre[i] = pre[i - 1] + (st >> i & 1);
    }
    auto get = [&](int l, int r) {
      if (l > r) return 0;
      else return pre[r] - (l ? pre[l - 1] : 0);
    };
    for (int L = 0; L < k; L++) {
      for (int R = 0; R < k; R++) {
        if (L <= R) coef += f[L][R][get(L, R)][get(0, L - 1) + get(R + 1, k - 1)];
        else coef += f[L][R][get(L, k - 1) + get(0, R)][get(R + 1, L - 1)];
      }
    }
    coef += sp[__builtin_popcount(st)];
    coef += 2 * n - __builtin_popcount(st) * (n / k);
//    printf("st = %d, coef = %lld\n", st, coef);
//    printf("extra coef = %lld\n", 2 * n - __builtin_popcount(st) * (n / k));
    if (coef < n) {
      puts("unfair");
      exit(0);
    }
  }
  puts("fair");
  return 0;
}