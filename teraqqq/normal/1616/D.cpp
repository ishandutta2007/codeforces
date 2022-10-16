#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(const int n, const vector<int>& a, const int x) {
    vector<ll> ps(n+1);
    for (int i = 0; i < n; ++i) {
        ps[i+1] = ps[i] + a[i] - x;
    }

    vector<int> jmp(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        int j = i - 1;
        while (j >= 0 && ps[j] <= ps[i]) j = jmp[j];
        jmp[i] = j;
    }

    vector<int> left_bound(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        int j = ps[i-1] > ps[i] ? i - 2 : i - 1;
        while (j >= 0 && ps[j] <= ps[i]) j = jmp[j];
        left_bound[i] = j;
    }

    int last = -228;
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (left_bound[i] != -1 && last < left_bound[i]) {
            cnt++;
            last = i - 1;
        }
    }

    return n - cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); for (int& x : a) cin >> x;
        int x; cin >> x;
        int res = solve(n, a, x);
        cout << res << '\n';
    }
}