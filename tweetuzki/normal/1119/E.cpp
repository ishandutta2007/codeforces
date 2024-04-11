#include <algorithm>
#include <cstdio>
#include <cstring>
 
const int MaxN = 300000 + 5;
 
int N;
int A[MaxN];
char Fl[1 << 26], *Lk = Fl;

inline int read() {
  int x = 0; char c;
  do c = *Lk++; while (c < '0' || c > '9');
  do x = x * 10 + c - '0', c = *Lk++; while (c >= '0' && c <= '9');
  return x;
}

void init() {
  fread(Fl, 1, 1 << 26, stdin);
  N = read();
  for (int i = 1; i <= N; ++i) A[i] = read();
}

void solve() {
  long long ans = 0;
  int one = 0;
  for (int i = 1; i <= N; ++i) {
    int p = A[i] / 2;
    p = std::min(p, one);
    one -= p;
    ans += p;
    A[i] -= p * 2;
    int tri = A[i] / 3;
    ans += tri;
    A[i] -= tri * 3;
    one += A[i];
  }
  printf("%lld\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}