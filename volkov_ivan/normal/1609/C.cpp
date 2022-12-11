#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7, M = 1e6 + 7;
bool is_pr[M];
int a[N];
int lft1[N], rght1[N];

void init() {
    is_pr[0] = is_pr[1] = 0;
    for (int i = 2; i < M; i++)
        is_pr[i] = 1;
    
    for (int i = 2; i < M; i++) {
        if (is_pr[i]) {
            for (int j = i * i; j < M; j += i)
                is_pr[j] = 0;
        }
    }
}

void solve() {
    int res = 0;
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        lft1[i] = 1;
        if (i - e >= 0 && a[i - e] == 1)
            lft1[i] += lft1[i - e];
    }
    for (int i = n - 1; i >= 0; i--) {
        rght1[i] = 1;
        if (i + e < n && a[i + e] == 1)
            rght1[i] += rght1[i + e];
        if (is_pr[a[i]])
            res += lft1[i] * rght1[i] - 1;
    }
    cout << res << "\n";
}

signed main() {
    init();
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}