#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    const int N = n * k, lim = (n + k - 2) / (k - 1);
    vector<int> c(N), prv(n, -1), last(N);
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
        --c[i];
        last[i] = prv[c[i]];
        prv[c[i]] = i;
    }
    vector<bool> taken(n);
    vector<int> cnt(N), a(n), b(n);
    for (int it = 0; it < n; ++it) {
        int l = -1;
        for (int i = 0; i < N; ++i) {
            if (cnt[i] == lim) {
                l = i;
            }
            else if (not taken[c[i]] && last[i] > l) {
                taken[c[i]] = true;
                a[c[i]] = last[i], b[c[i]] = i;
                for (int j = last[i]; j <= i; ++j) {
                    ++cnt[j];
                }
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
    }
    exit(0);
}