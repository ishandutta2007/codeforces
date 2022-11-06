#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];
pair<int, int> b[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d%d", &b[i].first, &b[i].second);

    sort(b, b + m);
    for (int i = 1; i < m; ++i) b[i].second += b[i - 1].second;

    for (int i = 0; i < n; ++i) {
        int j = upper_bound(b, b + m, make_pair(a[i], 2000000000)) - b;
        if (j - 1 >= 0) printf("%d ", b[j - 1].second);
        else printf("0 ");
    }
    puts("");
}