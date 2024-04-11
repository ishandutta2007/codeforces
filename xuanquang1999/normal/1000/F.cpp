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
#define maxN 500005
#define MOD 998244353
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

struct Element {
    int x, id;
};

struct Query {
    int r, id;
};

Element max(const Element &a, const Element &b) {
    return (a.x > b.x) ? a : b;
}

struct IT {
private:
    vector<Element> t; int n;

    void update(int id, int l, int r, const int &p, const Element &e) {
        if (l > p || r < p) return;
        if (l == p && r == p) {
            t[id] = e;
            return;
        }
        int m = (l+r)/2;
        update(2*id, l, m, p, e); update(2*id+1, m+1, r, p, e);
        t[id] = max(t[2*id], t[2*id+1]);
    }

    Element query(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return {-oo, -1};
        if (i <= l && r <= j) return t[id];
        int m = (l+r)/2;
        return max(query(2*id, l, m, i, j), query(2*id+1, m+1, r, i, j));
    }
public:
    IT(int n): n(n) {t.assign(4*n+1, {-oo, -1});}
    void update(int p, Element e) {update(1, 1, n, p, e);}
    Element query(int l, int r) {return query(1, 1, n, l, r);}
};

int n, q, a[maxN], nxt[maxN], last[maxN], ans[maxN];
vector<Query> Q[maxN];
bool avail[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, maxN-1) last[i] = n+1;
    fdto(i, n, 1) {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }

    scanf("%d", &q);
    fto(i, 1, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        Q[l].pb({r, i});
    }

    memset(avail, true, sizeof avail);

    IT t(n);
    fto(i, 1, n) {
        if (avail[i]) t.update(i, {nxt[i], a[i]});
        avail[nxt[i]] = false;
    }

    fto(i, 1, n) {
        for(Query q: Q[i]) {
            Element e = t.query(i, q.r);
            if (e.x > q.r)
                ans[q.id] = e.id;
            else
                ans[q.id] = 0;
        }
        t.update(i, {-oo, -1});
        int p = nxt[i];
        if (p <= n)
            t.update(p, {nxt[p], a[p]});
    }

    fto(i, 1, q) printf("%d\n", ans[i]);

    return 0;
}