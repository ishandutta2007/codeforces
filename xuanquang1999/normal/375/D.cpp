//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define oo 1000000007
#define Base 316

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct query {int l, r, k, id;};
bool cmp(const query &a, const query &b) {
    if (a.l/Base < b.l/Base) return true;
    if (a.l/Base > b.l/Base) return false;
    return ((a.l/Base)&1) ? (a.r < b.r) : (a.r > b.r);
}

int n, m, dfsCnt, c[maxN], a[maxN], in[maxN], out[maxN], cnt[maxN], f[maxN], ans[maxN];
vector<int> ke[maxN];
query q[maxN];

void DFS(int u, int p) {
    in[u] = ++dfsCnt;
    a[dfsCnt] = c[u];
    forit(it, ke[u]) {
        int v = *it;
        if (v != p) DFS(v, u);
    }
    out[u] = dfsCnt;
}

void add(int x) {++cnt[x]; ++f[cnt[x]];}
void del(int x) {--f[cnt[x]]; --cnt[x];}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &c[i]);
    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    DFS(1, -1);

    fto(i, 1, m) {
        int u, k; scanf("%d%d", &u, &k);
        q[i] = {in[u], out[u], k, i};
    }

    sort(q+1, q+m+1, cmp);

    int l = 1, r = 0;
    fto(i, 1, m) {
        while (l < q[i].l) del(a[l++]);
        while (l > q[i].l) add(a[--l]);
        while (r < q[i].r) add(a[++r]);
        while (r > q[i].r) del(a[r--]);
        ans[q[i].id] = f[q[i].k];
    }

    fto(i, 1, m) printf("%d\n", ans[i]);

    return 0;
}