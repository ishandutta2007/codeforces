#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n; scanf("%d%d", &n, &k);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &v[i].second, &v[i].first);
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        pq.push(v[i].second);
        sum += v[i].second;
        while (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        ans = max(ans, sum * v[i].first);
    }
    printf("%lld\n", ans);
}