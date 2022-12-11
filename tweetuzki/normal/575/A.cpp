#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>

const int MaxN = 50000, MaxM = 50000, MaxLog = 16;

int N, M, Mod; long long K;
int S[MaxN + 5];
std::pair<long long, int> V[MaxM + 5];

struct Matrix {
  int mat[2][2];

  Matrix() {
    memset(mat, 0, sizeof mat);
  }

  inline friend Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
        long long x = 0;
        for (int k = 0; k < 2; ++k)
          x += 1LL * a.mat[i][k] * b.mat[k][j];
        c.mat[i][j] = x % Mod;
      }
    return c;
  }

  inline friend Matrix operator ^ (Matrix low, long long high) {
    Matrix res;
    for (int i = 0; i < 2; ++i) res.mat[i][i] = 1;
    while (high) {
      if (high & 1) res = res * low;
      high >>= 1;
      low = low * low;
    }
    return res;
  }
};
Matrix Sm[MaxLog + 1][MaxN + 5], Pre[MaxN + 5], Suf[MaxN + 5], All;

inline Matrix get(int k1, int k2) {
  Matrix a;
  a.mat[1][0] = 1;
  a.mat[0][1] = k1;
  a.mat[1][1] = k2;
  return a;
}

void init() {
  scanf("%lld %d", &K, &Mod);
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &S[i]);
    S[i] %= Mod;
  }
  scanf("%d", &M);
  bool o = false;
  for (int i = 1; i <= M; ++i) {
    scanf("%lld %d", &V[i].first, &V[i].second);
    V[i].second %= Mod;
    if (V[i].first == K) o = true;
  }
  if (o == false) V[++M] = std::make_pair(K, S[K % N]);
  V[++M] = std::make_pair(0, S[0]);
  std::sort(V + 1, V + 1 + M);
}

inline Matrix calc(long long l, long long r) {
  // printf("calc(%lld, %lld)\n", l, r);
  Matrix a;
  for (int i = 0; i < 2; ++i) a.mat[i][i] = 1;
  if (l > r) return a;
  long long belL = l / N, belR = r / N;
  int idL = (int) (l - belL * N), idR = (int) (r - belR * N);
  // printf("%lld = %lld.%d, %lld = %lld.%d\n", l, belL, idL, r, belR, idR);
  if (belL == belR) {
    int len = idR - idL + 1;
    for (int i = MaxLog; i >= 0; --i)
      if (len & (1 << i)) {
        // printf("hihi(%d, %d)\n", idL, idL + (1 << i) - 1);
        // printf("((%d, %d), (%d, %d))\n", Sm[i][idL].mat[0][0], Sm[i][idL].mat[0][1], Sm[i][idL].mat[1][0], Sm[i][idL].mat[1][1]);
        a = a * Sm[i][idL];
        idL += (1 << i);
      }
  } else {
    a = a * Suf[idL];
    a = a * (All ^ (belR - belL - 1));
    a = a * Pre[idR];
  }
  return a;
}

void solve() {
  if (K == 0) {
    puts("0");
    return;
  }
  for (int i = 0; i < 2; ++i) All.mat[i][i] = 1;
  for (int i = 0; i < N; ++i) {
    Sm[0][i] = get(S[(i - 1 + N) % N], S[i]);
    All = All * Sm[0][i];
  }
  for (int i = 1; (1 << i) <= N; ++i)
    for (int j = 0; j + (1 << i) - 1 < N; ++j)
      Sm[i][j] = Sm[i - 1][j] * Sm[i - 1][j + (1 << (i - 1))];
  Pre[0] = get(S[N - 1], S[0]);
  for (int i = 1; i < N; ++i) Pre[i] = Pre[i - 1] * get(S[i - 1], S[i]);
  for (int i = 0; i < 2; ++i) Suf[N].mat[i][i] = 1;
  for (int i = N - 1; i >= 0; --i) Suf[i] = get(S[(i - 1 + N) % N], S[i]) * Suf[i + 1];
  Matrix F;
  F.mat[0][0] = 0, F.mat[0][1] = 1;
  long long pos = 0;
  for (int i = 2; i <= M; ++i) {
    // printf("i = %d, (%lld, %d)\n", i, V[i].first, V[i].second);
    if (V[i].first == V[i - 1].first + 1) {
      F = F * get(V[i - 1].second, V[i].second);
      pos++;
    } else {
      F = F * get(V[i - 1].second, S[(pos + 1) % N]);
      // printf("F = (%d, %d)\n", F.mat[0][0], F.mat[0][1]);
      F = F * calc(pos + 2, V[i].first - 1);
      // printf("F = (%d, %d)\n", F.mat[0][0], F.mat[0][1]);
      pos = V[i].first;
      F = F * get(S[(pos - 1 + N) % N], V[i].second);
    }
    if (V[i].first == K) break;
  }
  printf("%d\n", F.mat[0][0]);
}

int main() {
  init();
  solve();
  return 0;
}