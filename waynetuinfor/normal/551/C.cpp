#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e15 + 1;
long long a[maxn];
int n, m;

bool check(long long t) {
    vector<long long> na(a, a + n);
    int ind = 0;
    while (ind < n && na[ind] == 0) ++ind;
    int rind = n - 1;
    while (rind >= 0 && na[rind] == 0) --rind;
    for (int i = 0; i < m; ++i) {
        long long tl = t - ind - 1;
        while (ind < n && tl > 0) {
            long long tk = min(na[ind], tl);
            na[ind] -= tk; tl -= tk;
            if (na[ind] == 0) ++ind, --tl;
        }
    } 
    return ind > rind;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long d = 1, ans = inf; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans - d >= 1) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}