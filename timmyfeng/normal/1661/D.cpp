#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vector<long long> b(n);
    for (auto &i : b) cin >> i;
    ranges::reverse(b);

    vector<long long> endpoints(n);
    long long sum = 0, segments = 0;
    for (int i = 0; i < n; ++i) {
        b[i] = max(0LL, b[i] - sum);

        k = min(k, n - i);
        long long new_segments = (b[i] + k - 1) / k;
        segments += new_segments;
        sum += new_segments * k;
        endpoints[i + k - 1] += new_segments;

        sum -= segments;
        segments -= endpoints[i];
    }

    cout << accumulate(endpoints.begin(), endpoints.end(), 0LL) << "\n";
}