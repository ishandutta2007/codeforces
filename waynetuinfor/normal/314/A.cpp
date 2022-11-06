#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long p = 0;
    int c = n, pos = 0;
    for (int i = 1; i <= n; ++i) {
        long long d = p - (c - pos - 1) * 1ll * a[i] * pos;
        // cout << "i = " << i << " d = " << d << endl;
        if (d < k) {
            cout << i << endl;
            --c;
            continue;
        }
        p += a[i] * 1ll * pos;
        ++pos;
    }
    return 0;
}