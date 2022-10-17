#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
const int MAXN = 200200, lim = 2e5;
int n, a[MAXN], pos[MAXN];

struct event { int pos, r, val; bool operator < (const event &other) const { return pos < other.pos; } } e[MAXN * 3];
int top;

struct seg {
    int l, r, val;
    bool operator < (const seg &other) const { return (l == other.l) ? (val < other.val) : (l < other.l); }
}; set <seg> s;

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read(), pos[a[i]] = i;
    for (i = 1; i <= lim; i++) {
        int mn1 = 0, mn2 = 0, mx1 = 0, mx2 = 0;
        for (j = i; j <= lim; j += i) if (pos[j]) {
            if (!mn1 || pos[j] < mn1) mn2 = mn1, mn1 = pos[j];
            else if (!mn2 || pos[j] < mn2) mn2 = pos[j];
            if (!mx1 || pos[j] > mx1) mx2 = mx1, mx1 = pos[j];
            else if (!mx2 || pos[j] > mx2) mx2 = pos[j];
        }
        if (mx1 - mn1 >= 2) e[++top] = {mn1 + 1, mx1 - 1, i};
        if (mn2) e[++top] = {mn2 + 1, n, i};
        if (mx2 > 1) e[++top] = {1, mx2 - 1, i};
    }
    sort(e + 1, e + top + 1);
    ll ans = 0, sum = 0; s.insert({0, n, 0});
    for (i = 1, j = 1; i <= n; i++) {
        auto now = *(s.begin()); sum -= now.val;
        auto to = now; ++to.l; s.erase(s.begin());
        if (to.l <= to.r) s.insert(to);

        while (e[j].pos == i) {
            auto it = s.upper_bound({e[j].r + 1, -1, -1}); --it;
            if ((*it).r > e[j].r) {
                auto u = *it, v = *it;
                u.r = e[j].r, v.l = e[j].r + 1;
                s.erase(it); s.insert(u), s.insert(v);
                it = s.upper_bound({e[j].r + 1, -1, -1}); --it;
            }
            if ((*it).val >= e[j].val) { ++j; continue; }
            while ((*it).val < e[j].val) {
                if (it == s.begin()) {
                    sum -= 1ll * (*it).val * ((*it).r - (*it).l + 1);
                    s.erase(it); break;
                }
                else {
                    auto nex = it; --nex;
                    sum -= 1ll * (*it).val * ((*it).r - (*it).l + 1);
                    s.erase(it);
                    it = nex;
                }
            }
            if (s.empty() || (*s.begin()).l > e[j].r) sum += 1ll * e[j].val * (e[j].r - i + 1), s.insert({i, e[j].r, e[j].val});
            else sum += 1ll * e[j].val * (e[j].r - (*it).r), s.insert({(*it).r + 1, e[j].r, e[j].val});
            ++j;
        }
        ans += sum;
    }
    printf("%lld\n", ans);
    return 0;
}