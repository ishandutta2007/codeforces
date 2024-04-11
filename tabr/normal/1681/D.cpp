#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto Mul = [&](long long x, long long y) {
        if (1.0L * x * y > 9.1e18) {
            return -1LL;
        }
        return x * y;
    };
    int n;
    long long x;
    cin >> n >> x;
    map<long long, int> d;
    d[x] = 0;
    int ans = -1;
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
    pq.emplace(0, x);
    while (!pq.empty()) {
        auto [dd, z] = pq.top();
        pq.pop();
        if (d[z] != dd) {
            continue;
        }
        if ((int) to_string(z).size() == n) {
            ans = dd;
            break;
        }
        string t = to_string(z);
        sort(t.begin(), t.end());
        t.resize(unique(t.begin(), t.end()) - t.begin());
        for (char c : t) {
            int a = c - '0';
            if (!a) {
                continue;
            }
            long long w = Mul(z, a);
            if (w < 0) {
                continue;
            }
            if ((int) to_string(w).size() > n) {
                continue;
            }
            if (!d.count(w) || d[w] > d[z] + 1) {
                d[w] = d[z] + 1;
                pq.emplace(d[w], w);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}