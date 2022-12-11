#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 1000000;
const int Mod = 1000000007;

int N;
int A[MaxN + 5];
int Pre[MaxN + 5], Par[MaxN + 5];
int F[MaxN + 5];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline void inc(int &x, int y = 1) { x = add(x, y); }

namespace PAM {

int cnt, last;
int ch[MaxN + 5][26], fail[MaxN + 5], len[MaxN + 5];
int diff[MaxN + 5];

void init() {
  cnt = last = 2;
  len[1] = -1;
  fail[1] = fail[2] = 1;
  Par[2] = 1;
}

inline int expand(int c, int id) {
  int p = last;
  while (A[id] != A[id - len[p] - 1]) p = fail[p];
  if (ch[p][c] != 0) {
    last = ch[p][c];
    return last;
  }
  ch[p][c] = ++cnt;
  last = cnt;
  len[cnt] = len[p] + 2;
  if (len[cnt] == 1) {
    fail[cnt] = 2;
  } else {
    do p = fail[p]; while (A[id] != A[id - len[p] - 1]);
    fail[cnt] = ch[p][c];
  }
  diff[cnt] = len[cnt] - len[fail[cnt]];
  if (diff[cnt] == diff[fail[cnt]]) Par[cnt] = Par[fail[cnt]];
  else Par[cnt] = fail[cnt];
  return last;
}

}

void init() {
  static char s[MaxN + 5];
  scanf("%s", s + 1);
  N = (int) strlen(s + 1);
  for (int i = 1; i <= N; ++i) {
    if (i & 1) A[i] = s[(i + 1) >> 1] - 'a' + 1;
    else A[i] = s[N - (i >> 1) + 1] - 'a' + 1;
  }
}

void solve() {
  PAM::init();
  F[0] = 1;
  for (int i = 1; i <= N; ++i) {
    int u = PAM::expand(A[i], i);
    for (int f = u; f != 0 && f != 2; f = Par[f]) {
      Pre[f] = F[i - (PAM::len[Par[f]] + PAM::diff[f])];
      if (PAM::fail[f] != Par[f]) inc(Pre[f], Pre[PAM::fail[f]]);
      if (i % 2 == 0) inc(F[i], Pre[f]);
    }
  }
  printf("%d\n", F[N]);
}

int main() {
  init();
  solve();
  return 0;
}