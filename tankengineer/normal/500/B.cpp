#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 305;

int n, a[N], fa[N];

char g[N];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    if (u != v) {
        fa[u] = v;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        fa[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", g);
        for (int j = 0; j < n; ++j) {
            if (g[j] == '1') {
                merge(find(i), find(j));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (find(i) == find(j) && a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}