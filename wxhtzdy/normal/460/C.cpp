#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, m, w;
int a[N], b[N], x[N];

bool can(int z) {
        for (int i = 0; i < n; i++)
                b[i] = max(0, z - a[i]);
        long long bal = 0, need = 0;
        for (int i = 0; i < n; i++) {
                if (i >= w)
                        bal -= x[i - w];
                x[i] = max(0LL, b[i] - bal);
                need += max(0, x[i]);
                bal = max(bal, (long long) b[i]);
        }
        return need <= m;
}

int main() {
        scanf("%d%d%d", &n, &m, &w);
        for (int i = 0; i < n; i++)
                scanf("%d", &a[i]);
        int l = 0, r = 1e9 + 2e5;
        while (r - l > 1) {
                int z = l + r >> 1;
                if (can(z))
                        l = z;
                else
                        r = z;
        }
        printf("%d", l);
        return 0;
}