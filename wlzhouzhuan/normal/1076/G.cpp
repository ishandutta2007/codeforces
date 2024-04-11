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
const int B = 200;

int a[N], n, m, q;
int be[N], L[N / B + 5], R[N / B + 5];

struct BLOCKS {
  // podd[i]  i 
  // godd[i]  i  >=m+1  
  int podd[B + 5], peven[B + 5], tag;
  int godd[B + 5], geven[B + 5];
  int L, R;
  void init(int *a, int len) {
//    tag = 0;
    podd[0] = peven[0] = 0;
    for (int i = 1; i <= len; i++) {
      podd[i] = (a[i] & 1 ? i : podd[i - 1]);
      peven[i] = (~a[i] & 1 ? i : peven[i - 1]);
    }
    godd[0] = geven[0] = 0;
    for (int i = 1; i <= len; i++) {
      if (a[i] & 1) godd[i] = ((i - m - 1 >= 1 && podd[i - m - 1]) ? godd[podd[i - m - 1]] : i);
      else geven[i] = ((i - m - 1 >= 1 && peven[i - m - 1]) ? geven[peven[i - m - 1]] : i);
    }
  }
  bool test(int x) {
    return a[x] ^ tag;
  }
  int getOdd() { //  
    if (tag) return peven[R - L + 1] + L - 1;
    else return podd[R - L + 1] + L - 1;
  }
  int calc(int x) { //  x  godd  
    x -= L - 1;
    if (tag) x = peven[x];
    else x = podd[x];
    if (tag) x = geven[x];
    else x = godd[x];
    if (x <= 0) return 0;
    else return x + L - 1;
  }
} b[N / B + 5];

int main() {
  n = read(), m = read(), q = read();
  for (int i = 1; i <= n; i++) a[i] = read() & 1;
  for (int l = 1, r = B, id = 1; l <= n; l += B, r += B, id++) {
    r = min(r, n);
    L[id] = l, R[id] = r;
    b[id].L = l, b[id].R = r;
    b[id].init(a + (l - 1), r - l + 1);
    for (int i = l; i <= r; i++) be[i] = id;
  }
  while (q--) {
    int opt = read(), l = read(), r = read(), d;
    if (opt == 1) {
      d = read() & 1;
      if (!d) continue;
      int bL = be[l], bR = be[r];
//      printf("bL = %d, bR = %d\n", bL, bR);
      if (bL == bR) {
        for (int i = l; i <= r; i++) a[i] ^= 1;
        b[bL].init(a + (L[bL] - 1), R[bL] - L[bL] + 1);
      } else {
        for (int i = l; i <= R[bL]; i++) a[i] ^= 1;
        b[bL].init(a + (L[bL] - 1), R[bL] - L[bL] + 1);
        for (int i = L[bR]; i <= r; i++) a[i] ^= 1;
        b[bR].init(a + (L[bR] - 1), R[bR] - L[bR] + 1);
//        printf("                                                       %d\n", b[2].tag);
        for (int i = bL + 1; i <= bR - 1; i++) b[i].tag ^= 1;
//        printf("                                                      new %d\n", b[2].tag);
      }
//      printf("after modify %d\n", b[2].tag);
    } else { // opt = 2
      int bL = be[l], bR = be[r];
      if (!b[bL].test(l)) { puts("1"); continue; } // a[l] 
      
      int lst = 0;
      //  r  
      
//      printf("bl = %d, br = %d\n", bL, bR);
//      printf("test %d %d\n", a[6], b[bR].tag);
      
      for (int i = r; i >= L[bR]; i--) if (b[bR].test(i)) { lst = i; break; }
      if (lst == 0) {
        for (int i = bR - 1; i >= bL + 1; i--) {
//          printf("block(%d, L = %d, R = %d)\n", i, L[i], R[i]);
          lst = b[i].getOdd();
          if (lst >= L[i] && lst <= R[i]) break;
//          printf("lst = %d\n", lst);
//          if (lst != 0) break;
        }
      }
      if (lst == 0) {
        for (int i = R[bL]; i >= l; i--) if (b[bL].test(i)) { lst = i; break; }
      }
//      printf("lst = %d\n", lst);
      
      if (be[lst] != be[l]) {
        lst = b[be[lst]].calc(lst);
        for (int i = be[lst] - 1; i > bL; i--) {
          int who = min(R[i], lst - m - 1);
          int nxt = b[i].calc(who);
          if (nxt) {
            assert(nxt >= L[i] && nxt <= R[i]);
            lst = nxt;
//            printf("update %d\n", lst);
          } 
        }
      }
      
      for (int i = min(lst, R[bL]); i >= l; i--) {
//        printf("i = %d, chk = %d, %d\n", i, lst - m - 1 >= i, b[bL].test(i));
        if (lst - m - 1 >= i && b[bL].test(i)) {
          lst = i;
        }
      }
//      printf("final lst = %d\n", lst);
      puts(lst == l ? "2" : "1");
    }
  }
  return 0;
}