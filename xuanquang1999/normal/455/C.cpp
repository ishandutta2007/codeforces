//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 400005
#define oo 1000000007
#define EPS 10e-9

class UFDS {
private:
    vector<int> pset, lp;
public:
    UFDS(int n) {
        pset.resize(n);
        lp.resize(n);
        fto(i, 0, n-1) pset[i] = i;
    }
    int findSet(int i) {
        return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
    }
    bool isSameSet(int i, int j) {
        return (findSet(i) == findSet(j));
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            pset[x] = y;
            lp[y] = max(max(lp[x], lp[y]), (lp[x]+1)/2 + (lp[y]+1)/2 + 1);
        }
    }
    int query(int i) {
        return (lp[findSet(i)]);
    }
    void update(int i, int s) {
        lp[findSet(i)] = s;
    }
};

int n, m, q, d[maxN], parent[maxN], root;
vector<int> ke[maxN], tv;

void DFS(int u) {
    tv.pb(u);
    forit(it, ke[u]) {
        int v = *it;
        if (v == parent[u]) continue;
        parent[v] = u;
        d[v] = d[u] + 1;
        if (d[v] > d[root]) root = v;
        DFS(v);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    UFDS s(n);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v); --u, --v;
        ke[u].pb(v); ke[v].pb(u);
        s.unionSet(u, v);
    }
    fto(u, 0, n-1) parent[u] = -1;
    fto(u, 0, n-1) {
        if (parent[u] == -1) {
            root = u;
            fto(i, 1, 2) {
                if (i == 2) {
                    forit(it, tv) parent[*it] = -1;
                }
                tv.clear();
                parent[root] = root;
                d[root] = 0;
                DFS(root);
            }
            s.update(u, d[root]);
//            printf("%d %d\n", u, d[root]);
        }
    }
    fto(i, 1, q) {
        int t, u, v;
        scanf("%d%d", &t, &u); --u;
        if (t == 1) printf("%d\n", s.query(u));
        else {
            scanf("%d", &v); --v;
            s.unionSet(u, v);
        }
    }

    return 0;
}