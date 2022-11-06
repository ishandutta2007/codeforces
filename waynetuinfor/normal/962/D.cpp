#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
map<long long, set<int>> pos;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i), pos[a[i]].insert(i);
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; ++i) pq.push(a[i]);
    while (pq.size()) {
        long long z = pq.top(); pq.pop();
        if (pos[z].size() < 2) continue;
        // printf("z = %d\n", z);
        while (pos[z].size() >= 2) {
            int a = *pos[z].begin(), b = *next(pos[z].begin());
            // printf("a = %d b = %d\n", a, b);
            pos[z].erase(a); pos[z].erase(b);
            pos[z + z].insert(b);
            pq.push(z + z);
        }
    }
    vector<pair<int, long long>> ans;
    for (auto it : pos) if (it.second.size() > 0) ans.emplace_back(*(it.second.begin()), it.first);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%" PRId64 " ", ans[i].second); puts("");
    return 0;
}