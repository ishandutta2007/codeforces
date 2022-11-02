//28B
#include<cstdio>
#include<algorithm>
using namespace std;

int n, fa[105], size[105], t[105], dis[105], col[105];

int find(const int i) {return fa[i] == i ? i : fa[i] = find(fa[i]);}
void merge(int i, int j) {
    i = find(i); j = find(j);
    if (size[i] >= size[j]) {
        size[i] += size[j];
        fa[j] = i;
    } else {
        size[j] += size[i];
        fa[i] = j;
    }
}

int main() {
    scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dis[i]);
        if (i - dis[i] > 0 && find(i) != find(i - dis[i])) merge(i, i - dis[i]);
        if (i + dis[i] <= n && find(i) != find(i + dis[i])) merge(i, i + dis[i]);
    }
    for (int i = 1; i <= n; i++) col[i] = find(i);
    for (int i = 1; i <= n; i++) {
        if (col[t[i]] != find(i)) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}