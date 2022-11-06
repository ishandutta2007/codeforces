#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int c[maxn], a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ptr = 1, t = 0, ans = 0, bst = -1;
    for (int i = 1; i <= n; ++i) {
        if (c[a[i]] == 0) ++t;
        ++c[a[i]];
        while (t > k) {
            --c[a[ptr]];
            if (c[a[ptr]] == 0) --t;
            ++ptr;
        }
        if (i - ptr + 1 > ans) ans = i - ptr + 1, bst = ptr;
    }
    cout << bst << ' ' << ans + bst - 1 << endl;
    return 0;
}