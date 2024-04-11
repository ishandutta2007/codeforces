#include <iostream>

using namespace std;

const long long M = 10000000000000LL;
const int md = 100000000;
const int per = md*3/2;
const int nd = 30000000;

long long f[nd+10];
long long xa[500010], xb[500010], xc[500010];
long long x, ans;
int q, a, b, it, c, i, itt;

inline long long mul(long long a, long long b) {
  long long a1 = a/10000000, a2 = a-a1*10000000;
  long long b1 = b/10000000, b2 = b-b1*10000000;
  long long res = a2*b2;
  res += (a1*b2+b1*a2) % 1000000 * 10000000;
  return res % M;
}

void check(long long z) {
  if (ans != -1 && z >= ans) return;
  long long q = z/nd, w = z % nd, res;
  if (w == 0) res = xb[q];
  else res = (mul(xb[q],f[w-1])+mul(xc[q],f[w])) % M;
  if (res == x) ans = z;
}

long long aa, bb, cc;

void check2(long long z) {
//  if (ans != -1 && z >= ans) return;
  long long a = 1, b = 0, c = 1, na, nb, u;
  long long step = 1LL << 50;
  while (step > z) step >>= 1;
  while (step) {
    u = mul(b,b);
    na = mul(a,a)+u;
    if (na >= M) na -= M;
    b = mul(b,a+c);
    c = u+mul(c,c);
    if (c >= M) c -= M;
    a = na;
    if (step & z) {
      na = b;
      nb = a+b;
      if (nb >= M) nb -= M;
      c = b+c;
      if (c >= M) c -= M;
      a = na; b = nb;
    }
    step >>= 1;
  }
  aa = a; bb = b; cc = c;
}

int main() {
  f[0] = 0; f[1] = 1;
  for (i=2;i<nd;i++) {
    f[i] = f[i-1]+f[i-2];
    if (f[i] >= M) f[i] -= M;
  }
  check2(nd);
  xa[0] = 1; xb[0] = 0; xc[0] = 1;
  xa[1] = aa; xb[1] = bb; xc[1] = cc;
  for (i=2;i<(M*3/2)/nd;i++) {
    xa[i] = mul(xa[i-1],xa[1])+mul(xb[i-1],xb[1]);
    if (xa[i] >= M) xa[i] -= M;
    xb[i] = mul(xa[i-1],xb[1])+mul(xb[i-1],xc[1]);
    if (xb[i] >= M) xb[i] -= M;
    xc[i] = mul(xb[i-1],xb[1])+mul(xc[i-1],xc[1]);
    if (xc[i] >= M) xc[i] -= M;
  }
  cin >> x;
  q = x % md;
  a = 0; b = 1; it = 0;
  ans = -1;
  do {
    if (a == q)
      for (i=0;i<100000;i++) check((long long)i*per+it);
    c = a+b;
    if (c >= md) c -= md;
    a = b; b = c;
    it++;
  } while (a != 0 || b != 1);
  cout << ans << endl;
  return 0;
}