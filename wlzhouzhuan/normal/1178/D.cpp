%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
#define dd double
#define _i int
#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define range(i, l, r) rep(i, l, r - 1)
#define Be(s, t) memset(s, t, sizeof(s))
#define poly vector <int>
#define pii pair <int, int>
template <typename T> void read(T &x) { x = 0; int FF = 1; char op = getchar(); while (!isdigit(op)) { if (op == '-') FF = -1; op = getchar(); } while (isdigit(op)) { x = (x << 1) + (x << 3) + op - '0'; op = getchar(); } x *= FF; }
template <typename T> void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 1) return ; print(x / 10); putchar(x % 10 + '0'); }
template <typename T> void print(T x, char _tab) { print(x); putchar(_tab); }

const int N = 10005;
struct Bian {
  int x, y;
} edge[N << 1];
int n;

bool ispr(int k) {
  if (k < 2) return false;
  int _sq = sqrt(k);
  for (int i = 2; i <= _sq; i++) {
    if (k % i == 0) return false;
  }
  return true;
}

void gou() {
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    edge[++cnt] = Bian{i, i + 1};
  }
  edge[++cnt] = Bian{n, 1};
  
  //printf("%d\n", cnt);
  
  if (ispr(cnt)) {
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
      printf("%d %d\n", edge[i].x, edge[i].y);
    }
    return ;
  }

  for (int i = 1; i <= n; i++) {
    if (i % 4 == 3 || i % 4 == 0) continue;
    int p = i + 2;
    if (p == n + 1) p = 1;
    else if (p == n + 2) p = 2;
    edge[++cnt] = Bian{i, p};
    if (ispr(cnt)) break;
  }
  
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) {
    printf("%d %d\n", edge[i].x, edge[i].y);
  }
}

int main() {
  scanf("%d", &n);
  gou();
  return 0;
  
}