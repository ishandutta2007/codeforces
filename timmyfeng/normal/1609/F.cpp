#include <bits/stdc++.h>
using namespace std;

#define popcount(x) __builtin_popcountll(x)

const int LOG_A = 64;

long long solve(vector<long long> a) {
    if (a.empty()) return 0;

    int n = a.size(), m = n / 2;
    long long ans = 0;

    vector<long long> a_min(n), a_max(n);
    a_min[m] = a_max[m] = a[m];

    for (int i = m - 1; i >= 0; --i) {
        a_min[i] = min(a[i], a_min[i + 1]);
        a_max[i] = max(a[i], a_max[i + 1]);
    }

    for (int i = m + 1; i < n; ++i) {
        a_min[i] = min(a[i], a_min[i - 1]);
        a_max[i] = max(a[i], a_max[i - 1]);
    }

    vector<int> tally(LOG_A);
    int l = m, r = m - 1;

    // maximum is to the left of or at m
    for (int i = m; i >= 0; --i) {
        while (r + 1 < n && a_max[r + 1] <= a_max[i]) {
            ++tally[popcount(a_min[++r])];
        }

        while (l <= r && a_min[l] > a_min[i]) {
            --tally[popcount(a_min[l++])];
        }

        if (popcount(a_max[i]) == popcount(a_min[i])) {
            ans += l - m;
        }
        ans += tally[popcount(a_max[i])];
    }

    fill(tally.begin(), tally.end(), 0);
    r = m, l = m + 1;

    // maximum is to the right of m
    for (int i = m; i < n; ++i) {
        while (l > 0 && a_max[l - 1] < a_max[i]) {
            ++tally[popcount(a_min[--l])];
        }

        while (r >= l && a_min[r] > a_min[i]) {
            --tally[popcount(a_min[r--])];
        }

        if (popcount(a_max[i]) == popcount(a_min[i])) {
            ans += m - r;
        }
        ans += tally[popcount(a_max[i])];
    }

    return ans + solve(vector<long long>(a.begin(), a.begin() + m)) +
        solve(vector<long long>(a.begin() + m + 1, a.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    cout << solve(a) << "\n";
}