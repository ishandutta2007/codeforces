//25D
#include<cstdio>

const int N = 1005;

int n, fa[N], size[N], ans, t1, t2, l[N], r[N], top, s[N];
bool use[N];

int find(const int i) {return fa[i] == i ? i : fa[i] = find(fa[i]);}

void merge(const int i, const int j) {
  if (size[i] >= size[j]) {
      fa[j] = i;
        size[i] += size[j];
    } else {
        fa[i] = j;
        size[j] += size[i];
    }
}

int main() {
  scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    ans = n - 1;
    for (int i = 1; i < n; i++) {
    scanf("%d %d", &t1, &t2);
        use[i] = find(t1) != find(t2);
        if (use[i]) ans--;
        merge(find(t1), find(t2));
        l[i] = t1; r[i] = t2;
    }
    for (int i = 1; i <= n; i++) {
      if (fa[i] == i) {
      top++;
            s[top] = i;
        }
    }
    printf("%d\n", ans);
    t1 = 1;
    while (use[t1] && ans) t1++;
    for (int i = 1; i < top; i++) {
    printf("%d %d %d %d\n", l[t1], r[t1], s[i], s[i + 1]);
        t1++;
        while (use[t1] && t1 < n) t1++;
    }
    return 0;
}