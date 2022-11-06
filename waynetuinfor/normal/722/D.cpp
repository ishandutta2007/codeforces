#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10, inf = 1e9 + 1;
int y[maxn], x[maxn], n;

bool check(int maxv) {
    set<int> st;
    vector<int> nx(maxn);
    for (int i = 0; i < n; ++i) {
        int now = y[i];
        while (now > 0 && (now > maxv || st.count(now))) now >>= 1;
        if (now == 0) return false;
        nx[i] = now; st.insert(now);
    }
    for (int i = 0; i < n; ++i) x[i] = nx[i];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> y[i];
    sort(y, y + n); reverse(y, y + n);
    int d = 1, ans = inf; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    for (int i = 0; i < n; ++i) cout << x[i] << ' '; cout << endl;
    return 0;
}