#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int c[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    memset(c, -1, sizeof(c));
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        c[x] = i;
    }
    vector<int> v;
    for (int i = 0; i < maxn; ++i) if (~c[i]) v.push_back(c[i]);
    if (v.size() < k) return 0 * puts("NO");
    puts("YES");
    for (int i = 0; i < k; ++i) printf("%d ", v[i] + 1);
    puts("");
    return 0;
}