#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10, inf = 1e9;
int a[maxn], b[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) b[i] = s[i - 1] - '0';
    int lb = -inf, rb = inf;
    for (int i = 5; i <= n; ++i) {
        bool all1 = true, all0 = true;
        for (int j = i - 1; j >= i - 4; --j) {
            if (b[j] == 0) all1 = false; if (b[j] == 1) all0 = false;
        }
        if (b[i] == b[i - 1]) continue;
        if (b[i] == 0 && !all1) continue;
        if (b[i] == 1 && !all0) continue;
        if (b[i] == 0) {
            int mn = inf;
            for (int j = i; j >= i - 4; --j) mn = min(mn, a[j]);
            rb = min(rb, mn - 1);
        } else {
            int mx = -inf;
            for (int j = i; j >= i - 4; --j) mx = max(mx, a[j]);
            lb = max(lb, mx + 1);
        }
    }
    cout << lb << ' ' << rb << endl;
    return 0;
}