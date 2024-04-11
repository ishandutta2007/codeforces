#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#define LL long long
using namespace std;

const LL Q = 300100, N = 100100;
LL res[Q], a[N], x[Q];
vector <LL> g[N], h[N];
map <LL, LL> mp;

LL gcd (LL n, LL m) {
    while (n && m) if (n > m) n %= m; else m %= n;
    return n + m;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    LL n;
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        scanf ("%I64d", &a[i]);
    }
    LL q, id = 0;
    cin >> q;
    for (LL i = 1; i <= q; i++) {
        scanf ("%I64d", &x[i]);
        if (mp.find (x[i]) == mp.end()) mp[x[i]] = ++id;
    }
    for (LL i = 1; i <= n; i++) {
        LL sz = g[i - 1].size (), f = a[i], cnt = 1;
        for (LL j = 0; j < sz; j++) {
            LL t = gcd (f, g[i - 1][j]);
            if (t == f) cnt += h[i - 1][j];
            else {
                g[i].push_back (f);
                h[i].push_back (cnt);
                if (mp.find (f) != mp.end()) res[mp[f]] += cnt;
                cnt = h[i - 1][j];
                f = t;
            }
        }
        g[i].push_back (f);
        h[i].push_back (cnt);
        if (mp.find (f) != mp.end()) res[mp[f]] += cnt;
    }
//    for (LL i = 1; i <= n; i++) {
//
//        for ()
//    }
    for (LL i = 1; i <= q; i++) {
        printf ("%I64d\n", res[mp[x[i]]]);
    }
}