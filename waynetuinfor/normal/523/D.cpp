#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
pair<int, int> p[maxn];
long long ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < k; ++i) pq.push(0);
    for (int i = 0; i < n; ++i) {
        long long sv = pq.top(); pq.pop();
        ans[i] = max(sv, (long long)p[i].first) + p[i].second;
        pq.push(ans[i]);
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << endl;
    return 0;
}