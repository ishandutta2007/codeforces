#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
bool v[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d%d", &n, &m);
        int k = 3 * n;

        for (int i = 0; i < k; ++i) v[i] = false;

        vector<int> match;

        for (int i = 0; i < m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            --x, --y;
            if (!v[x] && !v[y]) {
                v[x] = true;
                v[y] = true;
                match.push_back(i);
            }
        }

        vector<int> indep;
        for (int i = 0; i < k; ++i) if (!v[i]) indep.push_back(i);

        if (match.size() >= n) {
            printf("Matching\n");
            for (int i = 0; i < n; ++i) printf("%d ", match[i] + 1);
            puts("");
        } else {
            assert(indep.size() >= n);
            printf("IndSet\n");
            for (int i = 0; i < n; ++i) printf("%d ", indep[i] + 1);
            puts("");
        }
    }
}