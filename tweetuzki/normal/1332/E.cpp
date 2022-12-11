#include <cstdio>
#include <cstring>
 
const int Mod = 998244353;
 
inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline int pw(int x, long long y) { int z = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) z = mul(z, x); return z; }
inline int inv(int x) { return pw(x, Mod - 2); }
inline int sep(int x, int y) { return mul(x, inv(y)); }
inline void inc(int &x, int y = 1) { x = add(x, y); }
inline void dec(int &x, int y = 1) { x = sub(x, y); }
 
struct Matrix {
  int a[2][2];
  Matrix() { memset(a, 0, sizeof a); }

  inline friend Matrix operator*(const Matrix &x, const Matrix &y) {
    Matrix z;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
        int val = 0;
        for (int k = 0; k < 2; ++k)
          inc(val, mul(x.a[i][k], y.a[k][j]));
        z.a[i][j] = val;
      }
    return z;
  }

  inline friend Matrix operator^(Matrix low, long long high) {
    Matrix res;
    res.a[0][0] = res.a[1][1] = 1;
    while (high) {
      if (high & 1) res = res * low;
      high >>= 1;
      low = low * low;
    }
    return res;
  }
};
 
int main() {
  int N, M, L, R;
  scanf("%d %d %d %d", &N, &M, &L, &R);
  long long V = 1LL * N * M;
  if (V % 2 == 1) {
    printf("%d\n", pw((R - L + 1) % Mod, V));
    return 0;
  } else {
    int oddNum = (R - L + 1) / 2, evenNum = (R - L + 1) / 2;
    if ((R - L) % 2 == 0) {
      if (L % 2 == 0) evenNum++;
      else oddNum++;
    }
    Matrix F, G;
    F.a[0][0] = 1;
    G.a[0][0] = evenNum % Mod, G.a[0][1] = oddNum % Mod, G.a[1][0] = oddNum % Mod, G.a[1][1] = evenNum % Mod;
    G = G ^ V;
    F = F * G;
    printf("%d\n", F.a[0][0]);
  }
  return 0;
}