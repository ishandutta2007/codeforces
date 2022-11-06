#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
long long a[maxn], s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) s[i] = abs(a[i] - a[i + 1]);
    long long p1 = 0, p2 = 0;
    long long ans = LLONG_MIN;
    set<long long> st1, st2;
    st1.insert(0); st2.insert(0);
    for (int i = 1; i < n; ++i) {
        p1 += (i % 2 == 0 ? 1LL : -1LL) * s[i];
        p2 += (i % 2 == 1 ? 1LL : -1LL) * s[i];
        ans = max({ ans, p1 - *st1.begin(), p2 - *st2.begin() });
        st1.insert(p1), st2.insert(p2);
    }
    cout << ans << '\n';
    return 0;
}