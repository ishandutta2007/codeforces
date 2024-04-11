//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 100005
#define oo 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct Node {
    int m;
    Node *l, *r;
    Node() {}
    Node(int m, Node *l, Node *r): m(m), l(l), r(r) {}
};

Node *init(int l, int r) {
    if (l == r) return new Node(oo, NULL, NULL);
    int m = (l+r)/2;
    return new Node(oo, init(l, m), init(m+1, r));
}

Node *update(Node *root, int l, int r, int p, int x) {
    if (p < l || p > r) return root;
    if (p == l && p == r) return new Node(min(root->m, x), NULL, NULL);
    int m = (l+r)/2;
    return new Node(min(root->m, x), update(root->l, l, m, p, x), update(root->r, m+1, r, p, x));
}

int query(Node *root, int l, int r, int i, int j) {
    if (i > r || j < l) return oo;
    if (i <= l && r <= j) return root->m;
    int m = (l+r)/2;
    return min(query(root->l, l, m, i, j), query(root->r, m+1, r, i, j));
}

int n, r, ans, d[maxN], a[maxN], dfsCnt, in[maxN], out[maxN], qpos[maxN];
vector<int> vtx[maxN], g[maxN];
Node *t[maxN];

void DFS(int u) {
    in[u] = ++dfsCnt;
    vtx[d[u]].pb(u);
    for(int v: g[u]) {
        if (!in[v]) {
            d[v] = d[u]+1;
            DFS(v);
        }
    }
    out[u] = dfsCnt;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &r);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    DFS(r);

    int q = 0;
    t[0] = init(1, n);
    fto(x, 0, n) {
        for(int u: vtx[x]) {
//            debug(u);
            ++q;
            t[q] = update(t[q-1], 1, n, in[u], a[u]);
        }
        qpos[x] = q;
    }

    scanf("%d", &q);
    fto(i, 1, q) {
        int x, y; scanf("%d%d", &x, &y);
        int u = (x+ans)%n+1, k = (y+ans)%n, D = min(d[u]+k, n);

        ans = query(t[qpos[D]], 1, n, in[u], out[u]);
        printf("%d\n", ans);
    }


    return 0;
}