#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int w, n, m, C[N], D[N], x, T[N];
char s[15];

namespace {
  int Trans(int x) {
    int cur = 1, res = 0;
    for(int i = 0; i < w; ++ i) {
      if((x >> i) & 1) res += cur;
      cur *= 3;
    }
    return res;
  }
}

int dfs(int x, int now, int T) {
  if(x == w) {
    return D[now];
  }
  if(s[x] == 'A') return dfs(x + 1, now, T * 3) +
		    dfs(x + 1, now + T, T * 3);
  if(s[x] == 'O') return dfs(x + 1, now, T * 3);
  if(s[x] == 'X') return dfs(x + 1, now, T * 3) +
		    dfs(x + 1, now + T * 2, T * 3);
  if(s[x] == 'a') return dfs(x + 1, now + T * 2, T * 3);
  if(s[x] == 'o') return dfs(x + 1, now + T, T * 3) +
		    dfs(x + 1, now + T * 2, T * 3);
  return dfs(x + 1, now + T, T * 3);
}

int main() {
  cin >> w >> n >> m;
  for(int i = 1; i <= n; ++ i)
    scanf("%d", &x), ++ C[x];
  for(int i = 0; i < (1 << w); ++ i) T[i] = Trans(i);
  //cerr << Trans(2) << endl;
  for(int i = 0; i < (1 << w); ++ i) {
    for(int j = 0; j < (1 << w); ++ j) {
      D[T[i] + T[j]] += C[i] * C[j];
    }
  }
  for(; m --;) {
    scanf("%s", s);
    reverse(s, s + w);
    printf("%d\n", dfs(0, 0, 1));
  }
}