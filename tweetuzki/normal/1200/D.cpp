#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2000 + 5;

int N, K;
int A[MaxN][MaxN];
int Pre[MaxN][MaxN];
int Dif[MaxN][MaxN];

inline char geCh() {
  char c;
  do c = getchar();
  while (c != 'B' && c != 'W');
  return c;
}

void init() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
    A[i][j] = geCh() == 'B';
  for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
    Pre[i][j] = A[i][j] + Pre[i - 1][j] + Pre[i][j - 1] - Pre[i - 1][j - 1];
}

void solve() {
  int res = 0;
  for (int i = 1; i <= N; ++i) {
    int mn = 0, mx = 0;
    for (int j = 1; j <= N; ++j)
      if (A[i][j] == 1) {
        if (mn == 0) mn = j;
        mx = j;
      }
    if (mn == 0 && mx == 0) {
      res++;
    } else if (mx - mn + 1 <= K) {
      int x2 = i, y2 = mn;
      int x1 = max(1, i - K + 1), y1 = max(1, mx - K + 1);
//      printf("(%d, %d), (%d, %d)\n", x1, y1, x2, y2);
      Dif[x1][y1]++;
      Dif[x1][y2 + 1]--;
      Dif[x2 + 1][y1]--;
      Dif[x2 + 1][y2 + 1]++;
    }

    mn = mx = 0;
    for (int j = 1; j <= N; ++j)
      if (A[j][i] == 1) {
        if (mn == 0) mn = j;
        mx = j;
      }

    if (mn == 0 && mx == 0) {
      res++;
    } else if (mx - mn + 1 <= K) {
      int x2 = mn, y2 = i;
      int x1 = max(1, mx - K + 1), y1 = max(1, i - K + 1);
  
      Dif[x1][y1]++;
      Dif[x1][y2 + 1]--;
      Dif[x2 + 1][y1]--;
      Dif[x2 + 1][y2 + 1]++;
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) {
    Dif[i][j] = Dif[i][j] + Dif[i - 1][j] + Dif[i][j - 1] - Dif[i - 1][j - 1];
    ans = max(ans, Dif[i][j]);
  }
  cout << res + ans << endl;
}

int main() {
  init();
  solve();
  return 0;
}