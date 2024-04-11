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
#define oo 2000000007
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

struct query {
    int l, r, id, bl;
};

bool cmpQ(const query &a, const query &b) {
    if (a.bl < b.bl) return true;
    if (a.bl > b.bl) return false;
    return (a.bl&1)^(a.r < b.r);
}

int n, q, k, gend[maxN], f[maxN], a[maxN];
int dfsCnt, d[maxN], in[maxN], out[maxN], b[20][maxN], T[2*maxN], cnt[maxN], cntT[maxN];
int qu[maxN], qv[maxN], p[maxN];
vector<int> g[maxN];
vector<query> Q;
ll res, ans[maxN];

void compress(int a[], int n) {
    set<int> s;
    map<int, int> m;
    fto(i, 1, n) s.insert(a[i]);
    for(int x: s) m[x] = m.size();
    fto(i, 1, n) a[i] = m[a[i]];
}

void DFS(int u, int p) {
    b[0][u] = p;
    in[u] = ++dfsCnt;
    T[dfsCnt] = u;
    for(int v: g[u]) {
        if (v == p) continue;
        d[v] = d[u]+1;
        DFS(v, u);
    }
    out[u] = ++dfsCnt;
    T[dfsCnt] = u;
}

int LCA(int u, int v) {
    if (d[u] > d[v]) swap(u, v);
    int t = d[v]-d[u];
    fto(i, 0, k) {
        if ((1<<i)&t) v = b[i][v];
    }

    fdto(i, k, 0) {
        if (b[i][u] != b[i][v]) {
            u = b[i][u];
            v = b[i][v];
        }
    }
    if (u == v) return u;
    fto(i, 0, k) {
        if (b[i][u] == b[i][v]) return b[i][u];
    }
}

void addQuery(int l, int r, int id) {
    Q.pb({l, r, id, l/sqrt(2*n)});
}

void add(int i) {
//    printf("add: %d\n", i);
    res += cnt[a[T[i]]];
    ++cnt[a[T[i]]];
}

void dec(int i) {
//    printf("dec: %d\n", i);
    --cnt[a[T[i]]];
    res -= cnt[a[T[i]]];
}

void addMO(int i) {
//    fto(i, 1, n) printf("%d ", cntT[i]);
//    puts("");
    if (a[T[i]] == 0) return;
    if (cntT[T[i]] == 1) dec(i);
    else add(i);
    ++cntT[T[i]];
}

void decMO(int i) {
//    fto(i, 1, n) printf("%d ", cntT[i]);
//    puts("");
    if (a[T[i]] == 0) return;
    if (cntT[T[i]] == 1) dec(i);
    else add(i);
    --cntT[T[i]];
}

void Solve(int sign) {
//    fto(i, 1, 2*n) printf("%d ", T[i]);
//    puts("");
//    fto(i, 1, n) printf("%d ", a[i]);
//    puts("");

    memset(cnt, 0, sizeof cnt);
    memset(cntT, 0, sizeof cntT);
    res = 0;

    int l = Q[0].l, r = Q[0].l-1;
    for(query q: Q) {
//        printf("%d %d %d\n", q.l, q.r, q.id);
        while (l > q.l) addMO(--l);
        while (r < q.r) addMO(++r);
        while (l < q.l) decMO(l++);
        while (r > q.r) decMO(r--);
//        printf("%lld\n", res);
        ans[q.id] += res*sign;
        if (qu[q.id] != p[q.id]) {
            ans[q.id] += cnt[a[p[q.id]]]*sign;
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &gend[i]);
    fto(i, 1, n) scanf("%d", &f[i]);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    scanf("%d", &q);
    fto(i, 1, q) scanf("%d%d", &qu[i], &qv[i]);

    compress(f, n);

    k = log2(n);
    DFS(1, 0);

    fto(i, 1, k) {
        fto(u, 1, n) b[i][u] = b[i-1][b[i-1][u]];
    }

    fto(i, 1, q) {
        if (in[qu[i]] > in[qv[i]]) swap(qu[i], qv[i]);
        p[i] = LCA(qu[i], qv[i]);
        if (p[i] == qu[i]) addQuery(in[qu[i]], in[qv[i]], i);
        else addQuery(out[qu[i]], in[qv[i]], i);
    }

    sort(Q.begin(), Q.end(), cmpQ);


    fto(mask, 1, 3) {
        int sign = (mask == 3) ? 1 : -1;
        fto(i, 1, n) {
            a[i] = ((1<<gend[i])&mask) ? f[i] : 0;
        }
        Solve(sign);
    }

//    puts("");
    fto(i, 1, q) printf("%lld\n", ans[i]);

    return 0;
}