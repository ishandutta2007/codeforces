#include <bits/stdc++.h>
using namespace std;

const int kN = 1'000'000 + 5;
int a[kN], g[kN], d[kN], v[kN];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) d[i] = v[i] = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            g[i] = i - a[i];
            ++d[g[i]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int x = q.front(); q.pop();
            v[x] = true;
            if (--d[g[x]] == 0) q.push(g[x]);
        }
        vector<int> ans;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                ans.push_back(i);
                sum += a[i];
            }
        }
        assert(sum == 0);
        printf("%d\n", (int)ans.size());
        for (int u : ans) printf("%d ", u + 1);
        puts("");
    }
    return 0;
}