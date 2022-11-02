#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 205;

int n, m, fa[N], size[N], t1, t2, t3, a, b, c, d, col[N];

int find(const int i) {return i == fa[i] ? i : fa[i] = find(fa[i]);}
void merge(const int i, const int j) {
  //printf("Merge %d %d\n", i, j);
  if (i == j) return ;
  if (size[i] >= size[j]) {
    size[i] += size[j];
    fa[j] = i;
  } else {
    size[j] += size[i];
    fa[i] = j;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    fa[i] = i; fa[i + n] = i + n;
    size[i] = size[i + n] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &t1, &t2, &t3);
    int a = find(t1), b = find(t2), c = find(t1 + n), d = find(t2 + n);
    if (t3) {
      merge(a, b);
      merge(c, d);
    } else {
      merge(a, d);
      merge(b, c);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (find(i) == find(i + n)) {
      //printf("%d\n", i);
      puts("Impossible");
      return 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!col[i]) {
      col[i] = 1;
      for (int j = 1; j <= 2 * n; ++j) {
        if (find(j) == find(i)) {
          col[j] = 1;
        } else if (find(j) == find(i + n)) {
          col[j] = -1;
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) cnt += col[i] == 1;
  printf("%d\n", cnt);
  for (int i = 1; i <= n; ++i) {
    if (col[i] == 1) {
      printf("%d", i);
      if (!(--cnt)) printf("\n"); else printf(" ");
    }
  }
  return 0;
}