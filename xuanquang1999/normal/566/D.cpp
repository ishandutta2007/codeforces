using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
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
#define maxN 200005

int n, q, pset[maxN];
set<int> s;

int findSet(int u) {
    if (pset[u] == u) return u;
    pset[u] = findSet(pset[u]);
    return pset[u];
}

bool isSameSet(int u, int v) {
    return (findSet(u) == findSet(v));
}

void Union(int u, int v) {
    if (isSameSet(u, v)) return;
    pset[findSet(u)] = pset[v];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, n) pset[i] = i;
    fto(i, 1, n+1) s.insert(i);

    fto(i, 1, q) {
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        if (t == 1) Union(u, v);
        else if (t == 3) printf((isSameSet(u, v)) ? "YES\n" : "NO\n");
        else {
            set<int>::iterator itL = s.upper_bound(u), itR = itL;
            for(; (*itR) <= v; itR++) Union(*itR, u);
            s.erase(itL, itR);
        }
    }

    return 0;
}