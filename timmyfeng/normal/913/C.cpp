#include <bits/stdc++.h>
using namespace std;

const int L = 31;

long long c[L];

long long solve(int l) {
    if (l == 0) {
        return 0;
    }
    int b = __lg(l);
    return min(*min_element(c + b + 1, c + L), c[b] + solve(l - (1 << b)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    fill(c, c + L, LLONG_MAX);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 1; i < L; ++i) {
        c[i] = min(c[i], 2 * c[i - 1]);
    }

    cout << solve(l) << "\n";
}