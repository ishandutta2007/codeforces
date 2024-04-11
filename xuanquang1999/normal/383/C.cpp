//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, q, a[maxN], DFScnt, parent[maxN], in[maxN], out[maxN], order[maxN], d[maxN];
int FT[maxN];
vector<int> ke[maxN];

void update(int p, int x) {
    for(; p <= n; p += p & (-p)) FT[p] += x;
}

int query(int p) {
    int sum = 0;
    for(; p >= 1; p -= p & (-p)) sum += FT[p];
    return sum;
}

void DFS(int u) {
    in[u] = ++DFScnt;
    order[DFScnt] = u;

    forit(it, ke[u]) {
        int v = *it;
        if (v != parent[u]) {
            d[v] = d[u] + 1;
            parent[v] = u;
            DFS(v);
        }
    }

    out[u] = DFScnt;
}


int main () {
    scanf("%d%d", &n, &q);
    fto(u, 1, n) scanf("%d", &a[u]);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    DFS(1);
//    fto(u, 1, n) printf("%d %d %d %d\n", u, d[u], in[u], out[u]);
    fto(i, 1, q) {
        int t, u, x;
        scanf("%d%d", &t, &u);
        if (t == 1) {
            scanf("%d", &x);
            if (d[u]&1) {
                update(in[u], -x);
                update(out[u]+1, x);
            }
            else {
                update(in[u], x);
                update(out[u]+1, -x);
            }
        }
        else {
            if (d[u]&1) printf("%d\n", a[u]-query(in[u]));
            else printf("%d\n", a[u]+query(in[u]));
        }
    }

    return 0;
}