#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &l[i], &r[i]);
    int k; scanf("%d", &k);
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (r[i] < k)
            --ans;
    }
    printf("%d\n", ans);
}