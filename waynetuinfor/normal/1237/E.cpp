#include <bits/stdc++.h>
using namespace std;

int Dfs(int l, int r, int f, int g) {
    if (l > r) return 1;
    if (l == r) {
        int p = (l ^ f) & 1;
        return g ^ p;
    }
    vector<int> cd = {(l + r) / 2};
    if ((r - l + 1) % 2 == 0) cd.push_back((l + r) / 2 + 1);
    int res = 0;
    for (int u : cd) {
        int p = (u ^ f) & 1;
        if (f != -1 && (g ^ p) == 0) continue;
        res += Dfs(l, u - 1, u, 0) * Dfs(u + 1, r, u, 1);
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    if (n == 1) printf("1\n");
    else printf("%d\n", Dfs(1, n, -1, -1));
}