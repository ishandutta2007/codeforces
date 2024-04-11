//17B
#include<cstdio>
#include<algorithm>
using namespace std;

int n, q[1005], fa[1005], m, a[10005], b[10005], c[10005], srt[10005], ans, cnt;

int find(int i) {
  return (i == fa[i]) ? i : fa[i] = find(fa[i]);
}

void merges(int j, int i) {
  fa[i] = fa[j];
}

int cmp(int x, int y) {return c[x] < c[y];}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &q[i]);
    fa[i] = i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
    srt[i] = i;
  }
  sort(srt + 1, srt + m + 1, cmp);
  
  for (int i = 1; i <= m; i++) {
    if (find(a[srt[i]]) != find(b[srt[i]]) && fa[b[srt[i]]] == b[srt[i]]) {
      ans += c[srt[i]];
      merges(find(a[srt[i]]), find(b[srt[i]]));
      cnt++;
    }
  }
  if (cnt < n - 1) {
    puts("-1");
  } else {
    printf("%d\n", ans);
  }
  return 0;
}