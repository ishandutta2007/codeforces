#include<cstdio>
#include<algorithm>
using namespace std;

int n, tx, ty, ans, fa[2055];
bool vis[2055];

int find(const int i) {return fa[i] == i ? i : fa[i] = find(fa[i]);}
void merge(const int i, const int j) {fa[i] = j;}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2010; ++i) {
    fa[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &tx, &ty);
    ty += 1005;
    if (!vis[tx]) {
      ++ans;
      vis[tx] = true;
    }
    if (!vis[ty]) {
      ++ans;
      vis[ty] = true;
    }
    tx = find(tx); ty = find(ty);
    if (tx != ty) {
      --ans;
      merge(tx, ty);
    }
  }
  --ans;
  printf("%d\n", ans);
  return 0;
}