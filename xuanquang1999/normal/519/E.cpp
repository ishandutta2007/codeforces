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
#define maxN 100005
#define maxD 25

int m, n, parent[maxN], d[maxN], svc[maxN], b[maxD][maxN];
vector<int> ke[maxN];

int DFS(int u) {
    int res = 0;
    forit(it, vector<int>, ke[u]) {
        int v = *it;
        if (!parent[v]) {
            d[v] = d[u]+1;
            parent[v] = u;
            res+=DFS(v)+1;
        }
    }
    svc[u] = res;
    return res;
}
//Ancestor
int Anc(int u, int n) {
    fto(k, 0, m)
        if ((n >> k) & 1) u = b[k][u];
    return u;
}

int LCA(int u, int v) {
//    debug(u);
//    debug(v);

    u = Anc(u, d[u]-d[v]);

//    debug(u);
//    debug(v);

    fdto(k, m, 0)
        if (b[k][u] != b[k][v]) {
            u = b[k][u];
            v = b[k][v];
        }

    if (u == v) return u;
    fto(k, 0, m)
        if (b[k][u] == b[k][v]) return b[k][u];
}

int Solve(int u, int v) {
    if (d[u] < d[v]) return Solve(v, u);

    if (u == v) return n;
    if ((d[u]+d[v])%2 == 1) return 0;

    int a = LCA(u, v), k = (d[u]+d[v]-2*d[a])/2;

//    debug(u);
//    debug(v);
//    debug(a);
//    debug(k);

    if (d[u] == d[v]) return n-svc[Anc(u, k-1)]-svc[Anc(v, k-1)]-2;
    else return svc[Anc(u, k)]-svc[Anc(u, k-1)];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    m = trunc(log2(n));
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v);
        ke[v].pb(u);
    }

    parent[1] = 1;
    d[1] = 0;
    DFS(1);

    b[0][0] = 0;
    fto(j, 1, n) b[0][j] = parent[j];
    fto(i, 1, m)
        fto(j, 0, n) b[i][j] = b[i-1][b[i-1][j]];

//    fto(i, 1, n) debug(d[i]);
//    fto(i, 1, n) debug(svc[i]);

    int q;
    scanf("%d", &q);
    fto(i, 1, q) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", Solve(u, v));
    }

    return 0;
}