#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
int x[kN], y[kN];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        s.insert(x[i]);
        pq.emplace(1, x[i] - 1);
        pq.emplace(1, x[i] + 1);
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        while (!pq.empty() && s.count(pq.top().second)) pq.pop();
        assert(!pq.empty());
        auto p = pq.top();
        pq.pop();
        ans += p.first;
        y[i] = p.second;
        s.insert(y[i]);
        pq.emplace(p.first + 1, p.second - 1);
        pq.emplace(p.first + 1, p.second + 1);
    }
    printf("%lld\n", ans);
    for (int i = 0; i < m; ++i) printf("%d ", y[i]);
    puts("");
}