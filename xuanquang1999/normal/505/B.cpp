#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define maxN 105

struct UFDS {
    int pset[maxN];
    void initSet(int n) {
        fto(i, 1, n) pset[i] = i;
    }
    int findSet(int u) {
        return (pset[u] == u) ? u : pset[u] = findSet(pset[u]);
    }
    void unionSet(int u, int v) {
        pset[findSet(u)] = findSet(v);
    }
    bool isSameSet(int u, int v) {
        return (findSet(u) == findSet(v));
    }
};

int n, m, q;
UFDS us[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(c, 1, m) us[c].initSet(n);
    fto(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        us[c].unionSet(u, v);
    }
    scanf("%d", &q);
    fto(i, 1, q) {
        int u, v, cnt = 0;
        scanf("%d%d", &u, &v);
        fto(c, 1, m) cnt+=us[c].isSameSet(u, v);
        printf("%d\n", cnt);
    }
}