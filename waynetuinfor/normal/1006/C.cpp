#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int d[maxn];
long long s[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
    for (int i = n; i >= 1; --i) s[i] = s[i + 1] + d[i];
    set<pair<long long, int>> st;
    for (int i = 1; i <= n; ++i) st.insert(make_pair(s[i], i));
    long long ans = 0, p = 0;
    for (int i = 1; i <= n; ++i) {
        st.erase(make_pair(s[i], i));
        p += d[i];
        auto it = st.lower_bound(make_pair(p, -1));
        if (it != st.end() && it->first == p) ans = max(ans, p);
    }
    printf("%lld\n", ans);
}