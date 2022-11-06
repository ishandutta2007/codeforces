#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int a[maxn], ans[maxn];
vector<int> p[maxn];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        p[a[i]].push_back(i);
    }
    for (int i = 0; i < maxn; ++i) {
        if ((int)p[i].size() > k) {
            puts("NO");
            return 0;
        }
    }
    int c = 0;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < (int)p[i].size(); ++j) {
            ans[p[i][j]] = c;
            (++c) %= k;
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) printf("%d ", ans[i] + 1);
    puts("");
    return 0;
}