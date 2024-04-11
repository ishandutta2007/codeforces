#include <bits/stdc++.h>

using namespace std;

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        int n, m;
        scanf("%d%d", &n, &m);

        int curT = 0, minT = m, maxT = m;

        bool ok = true;

        for(int i = 0; i < n; ++i) {
            int t, l, r;
            scanf("%d%d%d", &t, &l, &r);

            int d = t - curT;
            minT = max(minT - d, l);
            maxT = min(maxT + d, r);
            if (minT > maxT)
                ok = false;

            curT = t;
        }

        puts(ok ? "YES" : "NO");
    }

    return 0;
}