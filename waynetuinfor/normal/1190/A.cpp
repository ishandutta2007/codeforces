#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
long long p[maxn];

int main() {
    long long n; scanf("%lld", &n);
    int m; scanf("%d", &m);
    long long k; scanf("%lld", &k);
    for (int i = 0; i < m; ++i) {
        scanf("%lld", &p[i]);
        --p[i];
    }

    set<long long> st;
    for (int i = 0; i < m; ++i) st.insert(p[i]);

    int ans = 0;
    long long off = 0;
    while (!st.empty()) {
        long long x = *st.begin();
        st.erase(x);
        ++ans;
        int e = 1;
        while (!st.empty()) {
            long long y = *st.begin();
            if ((x - off) / k == (y - off) / k) {
                st.erase(y);
                ++e;
            } else {
                break;
            }
        }
        off += e;
    }
    printf("%d\n", ans);
    return 0;
}