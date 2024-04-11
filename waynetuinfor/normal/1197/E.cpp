#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int x[maxn], y[maxn], sp[maxn], dp[maxn];
bool used[maxn];

int main() {
    int n; scanf("%d", &n);
    int ky = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        ky = max(ky, y[i]);
    }

    vector<int> v(n), w(n);
    iota(v.begin(), v.end(), 0);
    iota(w.begin(), w.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) {
        return y[i] < y[j];
    });
    sort(w.begin(), w.end(), [&](int i, int j) {
        return x[i] < x[j];
    });

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    map<int, pair<int, int>> sq;

    for (int i = 0, j = 0; i < n; ++i) {
        // printf("i = %d\n", v[i]);
        while (j < n && x[w[j]] <= y[v[i]]) {
            while (!pq.empty()) {
                int a = pq.top().first;
                int k = pq.top().second;
                if (a <= y[w[j]]) {
                    // printf("pop j = %d\n", k);
                    (sq[sp[k] - x[k]].second += mod - dp[k]) %= mod;
                    sq[sp[k] - x[k]].first -= 1;
                    if (sq[sp[k] - x[k]].first == 0) sq.erase(sp[k] - x[k]);
                    pq.pop();
                } else {
                    break;
                }
            }
            pq.emplace(x[w[j]], w[j]);
            // printf("value = %d\n", sp[w[j]] - x[w[j]]);
            (sq[sp[w[j]] - x[w[j]]].second += dp[w[j]]) %= mod;
            (sq[sp[w[j]] - x[w[j]]].first += 1) %= mod;
            // printf("push j = %d\n", w[j]);
            ++j;
        }
        if (!sq.empty()) {
            auto it = sq.begin();
            // printf("it->first = %d\n", it->first);
            sp[v[i]] = it->first + y[v[i]];
            dp[v[i]] = it->second.second;
        } else {
            sp[v[i]] = y[v[i]];
            dp[v[i]] = 1;
        }
    }

    // for (int i = 0; i < n; ++i) printf("sp[%d] = %d, dp[%d] = %d\n", i, sp[i], i, dp[i]);

    int mcost = 2e9, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] > ky) {
            // printf("i = %d\n", i);
            if (sp[i] < mcost) mcost = sp[i], ans = dp[i];
            else if (sp[i] == mcost) (ans += dp[i]) %= mod;
        }
    }
    // printf("mcost = %d\n", mcost);
    printf("%d\n", ans);
    return 0;
}