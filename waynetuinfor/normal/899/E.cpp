#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

struct segment {
    int a, l, len;
    int lid, rid;
    bool operator<(const segment &rhs) const { return len == rhs.len ? l < rhs.l : len > rhs.len; }
} pool[maxn];

struct cmp { bool operator()(const int &a, const int &b) { return pool[a] < pool[b]; } };

set<int, cmp> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int p = 0;
    for (int i = 1; i <= n; ) {
        int j = i;
        while (j <= n && a[i] == a[j]) ++j;
        pool[++p] = { a[i], i, j - i, 0, 0 };
        i = j;
    }
    for (int i = 1; i <= p; ++i) {
        pool[i].lid = i - 1;
        if (i + 1 <= p) pool[i].rid = i + 1;
        s.insert(i);
    }
    int ans = 0;
    while (s.size()) {
        ++ans;
        int now = *s.begin(); s.erase(s.begin());
        segment tol = pool[pool[now].lid], tor = pool[pool[now].rid];
        if (pool[now].lid && pool[now].rid && tol.a == tor.a) {
            s.erase(pool[now].lid); s.erase(pool[now].rid);
            pool[pool[now].lid] = { tol.a, tol.l, tol.len + tor.len, tol.lid, tor.rid };
            if (tor.rid) pool[tor.rid].lid = pool[now].lid;
            s.insert(pool[now].lid);
            continue;
        }
        if (pool[now].lid) pool[pool[now].lid].rid = pool[now].rid;
        if (pool[now].rid) pool[pool[now].rid].lid = pool[now].lid;
    }
    cout << ans << endl;
    return 0;
}