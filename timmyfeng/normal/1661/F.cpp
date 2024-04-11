#include <bits/stdc++.h>
using namespace std;

long long get_cost(long long len, long long segments) {
    return (len % segments) * (len / segments + 1) * (len / segments + 1) +
            (segments - len % segments) * (len / segments) * (len / segments);
}

long long get_count(long long len, long long delta) {
    long long low = 1, high = len;
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if (get_cost(len, mid - 1) - get_cost(len, mid) >= delta) low = mid;
        else high = mid - 1;
    }
    return high;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<long long> len(n);
    long long prv_a = 0;
    for (auto &i : len) {
        long long a; cin >> a;
        i = a - prv_a;
        prv_a = a;
    }

    long long m; cin >> m;

    long long low = 1, high = prv_a * prv_a;
    long long best_delta = -1, best_cost = -1, best_porters = -1;
    while (low <= high) {
        long long mid = (low + high) / 2;

        long long cost = 0, porters = 0;
        for (int i = 0; i < n; ++i) {
            long long segments = get_count(len[i], mid);
            cost += get_cost(len[i], segments);
            porters += segments - 1;
        }

        if (cost <= m) {
            best_delta = mid, best_cost = cost, best_porters = porters;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << max(0LL, best_porters - (m - best_cost) / best_delta) << "\n";
}