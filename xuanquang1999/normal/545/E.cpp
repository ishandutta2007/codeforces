using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 300005
#define mod 1000000009
#define maxD 10000000000000009
#define maxW 1000000009

int n, m, s, minW[maxN], minE[maxN];
vector<iii> ke[maxN];
ll d[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        ke[u].pb(mp(w, mp(v, i)));
        ke[v].pb(mp(w, mp(u, i)));
    }
    scanf("%d", &s);

    fto(u, 1, n) {
        d[u] = maxD;
        minW[u] = maxW;
    }
    d[s] = 0; minW[s] = 0;
    set<pair<long long, int> > q;
    q.insert(mp((ll)0, s));

    while (!q.empty()) {
        pair<long long, int> top = *q.begin(); q.erase(top);
        int u = top.se;
        forit(it, vector<iii>, ke[u]) {
            int w = (*it).fi, v = (*it).se.fi, i = (*it).se.se;
            if (d[v] > d[u]+w) {
                q.erase(mp(d[v], v));
                minW[v] = w; minE[v] = i;
                d[v] = d[u]+w;
                q.insert(mp(d[v], v));
            }
            else if (d[v] == d[u]+w && minW[v] > w) {
                minW[v] = w;
                minE[v] = i;
            }
        }
    }

    ll ans = 0;
    fto(u, 1, n) ans+=minW[u];
    printf("%I64d\n", ans);
    fto(u, 1, n)
        if (minW[u] != 0) printf("%d ", minE[u]);

    return 0;
}