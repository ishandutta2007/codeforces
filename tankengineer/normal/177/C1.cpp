//177C
#include<cstdio>
#include<algorithm>
using namespace std;

int n, k, m, ans, t1, t2, fa[4005], size[4005], siu[4005];
bool dik[4005];

int find(const int i) {return fa[i] == i ? i : fa[i] = find(fa[i]);}
void merge(const int i, const int j) {
  if (i == j) return;
  if (size[i] >= size[j]) {
    fa[j] = i;
    size[i] += size[j];
  } else {
    fa[i] = j;
    size[j] += size[i];
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    size[i] = 1;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d %d", &t1, &t2);
    merge(find(t1), find(t2));
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &t1, &t2);
    if (find(t1) == find(t2)) {
      dik[find(t1)] = true;
    }
  }
  for (int i = 1; i <= n; i++) siu[find(i)]++;
  for (int i = 1; i <= n; i++) {
    if (!dik[find(i)]) ans = ans > siu[find(i)] ? ans : siu[find(i)];
  }
  printf("%d\n", ans);
  return 0;
}