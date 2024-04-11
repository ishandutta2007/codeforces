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
#define oo 1000000000000000007LL
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

int mode = 1;
//mode 0: query mode
//mode 1: update mode

struct line {
    mutable ll x, a, b;
    bool inline operator < (const line &rhs) const {
        return mode ? (a > rhs.a || (a == rhs.a && b < rhs.b)) : (x < rhs.x);
    }
    void print() {
        printf("(%lld, %lld, %lld)\n", x, a, b);
    }
};

void print(line l) {
    printf("(%lld, %lld, %lld)\n", l.x, l.a, l.b);
}

ll query(set<line> &s, const int &x) {
//    printf("query %d\n", x);
//    for(line l: s) l.print();
//    puts("");
    mode = 0;
    line l = *(--s.lower_bound({x, 0, 0}));
    mode = 1;
    return l.a*x+l.b;
}

double intersect(const line &l1, const line &l2) {
    return 1.0*(l1.b-l2.b)/(l2.a-l1.a);
}

bool isBad(const line &l1, const line &l2) {
    return (l1.a == l2.a && (l1.b <= l2.b));
}

bool isBad(const line &l1, const line &l2, const line &l3) {
    return intersect(l3, l2) < intersect(l2, l1);
}

void update(set<line> &s, line l) {
//    printf("update ");
//    l.print();
//    puts("before: ");
//    for(line l: s) l.print();
    set<line>::iterator it = s.lower_bound(l);
//    puts("it:");
//    printf("%lld %lld %lld\n", it->x, it->a, it->b);
    if (it != s.begin()) {
        if (isBad(*prev(it), l)) return;
    }
    if (it != s.end()) {
        if (isBad(l, *it)) {
            ++it;
            s.erase(prev(it));
        }
    }
    if (it != s.begin() && it != s.end()) {
        if (isBad(*prev(it), l, *it)) return;
    }

    if (it != s.begin()) {
        while (prev(it) != s.begin() && isBad(*prev(it, 2), *prev(it), l))
            s.erase(prev(it));
    }
    if (it != s.end()) {
        while (next(it) != s.end() && isBad(l, *it, *next(it))) {
            ++it;
            s.erase(prev(it));
        }
    }

    l.x = (it == s.begin()) ? -oo : static_cast<ll>(floor(intersect(*prev(it), l)));
    if (it != s.end()) it->x = static_cast<ll>(floor(intersect(l, *it)));
    s.insert(l);
//    puts("after: ");
//    for(line l: s) l.print();
//    puts("");
}

int n, a[maxN], b[maxN];
ll dp[maxN];
vector<int> g[maxN];

void DFS(int u, int p, set<line> &s) {
    dp[u] = (p != -1 && sz(g[u]) == 1) ? 0 : oo;
//    debug(u);
    for(int v: g[u]) {
        if (v == p) continue;

        set<line> cur;
        DFS(v, u, cur);
//        puts("cur");

        if (sz(cur) > sz(s)) s.swap(cur);
        for(line l: cur) update(s, l);
    }
    dp[u] = (p != -1 && sz(g[u]) == 1) ? 0 : dp[u] = query(s, a[u]);

    update(s, {0, b[u], dp[u]});
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n) scanf("%d", &b[i]);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    set<line> s;
    DFS(1, -1, s);

    fto(i, 1, n) printf("%lld ", dp[i]);

    return 0;
}