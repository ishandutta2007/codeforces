#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int p[maxn];
bool v[maxn];
vector<int> cy[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    for (int i = 1; i <= n; ++i) if (p[i] == i) {
        puts("YES");
        for (int j = 1; j <= n; ++j) if (i != j) printf("%d %d\n", i, j);
        return 0;
    }
    int k = 0;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        ++k;
        for (int j = i; !v[j]; v[j] = true, j = p[j]) cy[k].push_back(j);
        if (cy[k].size() & 1) return 0 * puts("NO");
    }
    int r = -1;
    for (int i = 1; i <= k; ++i) {
        if (cy[i].size() == 2) r = i;
    }
    if (r == -1) return 0 * puts("NO");
    puts("YES");
    printf("%d %d\n", cy[r][0], cy[r][1]);
    for (int i = 1; i <= k; ++i) if (i != r) {
        for (int j = 0, p = 0; j < cy[i].size(); ++j, p ^= 1) printf("%d %d\n", cy[i][j], cy[r][p]);
    }
    return 0;
}