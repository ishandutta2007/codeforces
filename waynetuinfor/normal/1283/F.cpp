#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
int a[kN], dg[kN], g[kN];
bool used[kN];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &a[i]);
        a[i]--;
        dg[a[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; ++i) {
        g[i] = i;
        if (dg[i] == 0) pq.emplace(g[i], i);
    }
    int i = n - 2;
    vector<pair<int, int>> ans;
    while (i >= 0) {
        int x = pq.top().second; pq.pop();
        int u = a[i--];
        ans.emplace_back(x + 1, u + 1);
        g[u] = max(g[u], g[x]);
        if (--dg[u] == 0) pq.emplace(g[u], u);
    }
    printf("%d\n", a[0] + 1);
    while (!ans.empty()) {
        printf("%d %d\n", ans.back().first, ans.back().second);
        ans.pop_back();
    }
}