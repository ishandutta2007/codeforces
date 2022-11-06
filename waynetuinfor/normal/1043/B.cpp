#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[maxn], b[maxn];
bool v[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    vector<int> ans;
    for (int k = 1; k <= n; ++k) {
        memset(v, false, sizeof(v));
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            int x = a[i] - a[i - 1];
            if (v[(i - 1) % k] && b[(i - 1) % k] != x) ok = false;
            v[(i - 1) % k] = true;
            b[(i - 1) % k] = x;
        } 
        if (ok) ans.push_back(k);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i]);
    puts("");
    return 0;
}