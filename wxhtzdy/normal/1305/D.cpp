#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;

const int maxn=10005;
int deg[maxn];
vector<int> g[maxn];
bool was[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        deg[i] = g[i].size();
    }
    set<int> l;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            l.insert(i);
            was[i] = true;
        }
    }
    while ((int) l.size() > 1) {
        int u = *l.begin();
        l.erase(l.begin());
        int v = *l.begin();
        l.erase(l.begin());
        printf("? %d %d\n", u, v);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if (x == u || x == v) {
            printf("! %d", x);
            fflush(stdout);
            return 0;
        }
        set<int> adj;
        for (int i : g[u]) deg[i]--;
        for (int i : g[v]) deg[i]--;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1 && !was[i]) {
                l.insert(i);
                was[i] = true;
            }
        }
    }
    if (l.size() == 1) {
        printf("! %d", *l.begin());
        fflush(stdout);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!was[i]) {
            printf("! %d", i);
            fflush(stdout);
            return 0;
        }
    }
    return 0;
}