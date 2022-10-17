#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
inline ll read () {
    ll ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
int n; ll a[MAXN], b[MAXN], ans = 0;

void solve (int now, ll l, ll r, ll y) {
    int nex = lower_bound(b + 1, b + n + 1, -r) - b;
    // printf("solve %d %lld %lld %lld | %d\n", now, l, r, y, nex);
    if (nex > n) { ans = max(ans, y + r * n); return; }
    ll tmp = (r / a[nex]) * a[nex];
    // cout << tmp << endl;
    if (l >= tmp) {
        solve(nex, l % a[nex], r % a[nex], y + tmp * (nex - 1));
    }
    else {
        solve(nex, 0, r % a[nex], y + tmp * (nex - 1));
        if (r % a[nex] < a[nex] - 1) {
            if (r - l + 1 < a[nex]) 
                solve(nex, max(r % a[nex] + 1, l % a[nex]), a[nex] - 1, y + (tmp - a[nex]) * (nex - 1));
            else
                solve(nex, r % a[nex] + 1, a[nex] - 1, y + (tmp - a[nex]) * (nex - 1));            
        }
    }
}

int main () {
    // freopen("mxsum.in", "r", stdin);
    // freopen("mxsum.out", "w", stdout);
    n = read(); int i, j; a[0] = 1e18;
    for (i = 1; i <= n; i++) a[i] = read(), a[i] = min(a[i], a[i - 1]), b[i] = -a[i];
    solve(1, 0, a[1] - 1, 0);
    printf("%lld\n", ans);
    return 0;
}