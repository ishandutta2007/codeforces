#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 500005;
int n;
int l[maxn], r[maxn];
int pa[maxn];
int root(int u) {
    if (pa[u] == u) return u;
    return pa[u] = root(pa[u]);
}
int kk = 0;
void unite(int u, int v) {
    kk++;
    if (kk == n) {
        printf("NO");
        exit(0);
    }
    pa[root(u)] = pa[root(v)];
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }
    for (int i = 0; i < n; i++) pa[i] = i;
    vi ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
         return l[i] < l[j];
    });
    vector<pi> ev;
    for (int i = 0; i < n; i++) {
        ev.pb({i, 0});
        ev.pb({i, 1});
    }
    sort(ev.begin(), ev.end(), [&](pi i, pi j) {
        int x = (i.se == 0 ? l[i.fi] : r[i.fi]);
        int y = (j.se == 0 ? l[j.fi] : r[j.fi]);
        return x < y;
    });
    set<pi> sg;
    for (auto x : ev) {
        if (x.se == 0) {
            for (auto y : sg) {
                if (y.fi > r[x.fi]) break;
                unite(x.fi, y.se);
            }
            sg.insert({r[x.fi], x.fi});
        } else {
            sg.erase({r[x.fi], x.fi});
        }
    }
    for (int i = 0; i < n; i++) {
        if (root(i) != root(0)) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}