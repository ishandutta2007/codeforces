#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    int g = 0;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        g = __gcd(g, x);
    }
    g = __gcd(g, k);
    vector<int> ans;
    for (int i = 0; i < k; i += g) ans.push_back(i);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
    puts("");
    return 0;
}