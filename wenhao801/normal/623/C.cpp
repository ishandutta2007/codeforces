#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
#define pii pair <ll, ll>
#define fr first
#define se second

const int MAXN = 100100;
const ll inf = 1e18;
pii a[MAXN]; int n;

ll sq (ll x) { return x * x; }
void upd (pii &u, ll v) { u.fr = min(u.fr, v), u.se = max(u.se, v); }

pii pre[MAXN], suf[MAXN];
bool check (ll lim) {
    int i, j, j1, j2;
    pii tmp = {inf, -inf}, tmp2 = {inf, -inf};
    for (i = 1; i <= n; i++) {
        if (a[i].fr) upd(tmp, a[i].se);
        else upd(tmp2, a[i].se); 
    }
    if (tmp2.fr != inf) {
        pii u = {min(tmp.fr, 0ll), max(tmp.se, 0ll)};
        pii v = {min(tmp.fr, tmp2.fr), max(tmp.se, tmp2.se)};
        if (sq(u.fr - u.se) < sq(v.fr - v.se)) tmp = u; else tmp = v;
    }
    if (tmp.fr == inf || sq(tmp.fr - tmp.se) <= lim) return 1;

    pre[0] = suf[n + 1] = {inf, -inf};
    for (i = 1; i <= n; i++) pre[i] = pre[i - 1], upd(pre[i], a[i].se);
    for (i = n; i >= 1; i--) suf[i] = suf[i + 1], upd(suf[i], a[i].se);
    for (i = 1, j1 = 1, j2 = n + 1; i <= n && a[i].fr < 0; i++) {
        while (j1 < n && sq(a[j1 + 1].fr - a[i].fr) <= lim) j1++;
        while (j2 > i && a[j2 - 1].fr > -a[i].fr) j2--;
        j = min(j1, j2 - 1);
        pii tmp = pre[i - 1]; if (j != n) upd(tmp, suf[j + 1].fr), upd(tmp, suf[j + 1].se);
        if (tmp.fr == inf || (sq(tmp.se - tmp.fr) <= lim && max(sq(tmp.fr), sq(tmp.se)) + sq(a[i].fr) <= lim)) return 1;
    }

    for (i = 1; i <= n; i++) a[i].fr *= -1;
    reverse(a + 1, a + n + 1);
    // for (i = 1; i <= n; i++) printf("%lld %lld\n", a[i].fr, a[i].se);
    // putchar('\n');

    pre[0] = suf[n + 1] = {inf, -inf};
    for (i = 1; i <= n; i++) pre[i] = pre[i - 1], upd(pre[i], a[i].se);
    for (i = n; i >= 1; i--) suf[i] = suf[i + 1], upd(suf[i], a[i].se);
    for (i = 1, j1 = 1, j2 = n + 1; i <= n && a[i].fr < 0; i++) {
        while (j1 < n && sq(a[j1 + 1].fr - a[i].fr) <= lim) j1++;
        while (j2 > i && a[j2 - 1].fr > -a[i].fr) j2--;
        j = min(j1, j2 - 1);
        pii tmp = pre[i - 1]; if (j != n) upd(tmp, suf[j + 1].fr), upd(tmp, suf[j + 1].se);
        if (tmp.fr == inf || (sq(tmp.se - tmp.fr) <= lim && max(sq(tmp.fr), sq(tmp.se)) + sq(a[i].fr) <= lim)) return 1;
    }
    return 0;
}

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i].fr = read(), a[i].se = read();
    sort(a + 1, a + n + 1);
    ll L = 0, R = 1e18, ans = -1;
    
    while (L <= R) {
        ll mid = (L + R) >> 1;
        if (check(mid)) ans = mid, R = mid - 1; else L = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}