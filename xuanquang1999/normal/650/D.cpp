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
#define maxN 400005
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

struct IT {
private: vector<int> t; int n;
    void update(int id, int l, int r, int p, int x) {
        if (l > p || r < p) return;
        if (l == p && r == p) {
            t[id] = max(t[id], x);
            return;
        }
        int m = (l+r)/2;
        update(2*id, l, m, p, x); update(2*id+1, m+1, r, p, x);
        t[id] = max(t[2*id], t[2*id+1]);
    }
    int query(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return 0;
        if (i <= l && r <= j) return t[id];
        int m = (l+r)/2;
        return max(query(2*id, l, m, i, j), query(2*id+1, m+1, r, i, j));
    }
public:
    IT(int n): n(n) {t.assign(4*n+1, 0);}
    void update(int p, int x) {update(1, 1, n, p, x);}
    int query(int l, int r) {return query(1, 1, n, l, r);}
};

struct Query {
    int p, x, id;
    bool inline operator < (const Query &rhs) const {
        return x < rhs.x;
    }
};

int n, m, k, a[maxN], fl[maxN], fr[maxN], xl[maxN], xr[maxN], ans[maxN];
bool isGood[maxN];
Query q[maxN];

//void compress() {
//    set<int> s;
//    map<int, int> ma;
//    fto(i, 1, n) s.insert(a[i]);
//    fto(i, 1, m) s.insert(q[i].x);
//    for(int x: s) ma[x] = ++k;
//
//    fto(i, 1, n) a[i] = ma[a[i]];
//    fto(i, 1, m) q[i].x = ma[q[i].x];
//}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, m) {
        scanf("%d%d", &q[i].p, &q[i].x);
        q[i].id = i;
    }

//    compress();

    vector<int> v;
    fto(i, 1, n) {
        int p = lower_bound(v.begin(), v.end(), a[i])-v.begin();
        fl[i] = p+1;
        if (p == sz(v)) v.pb(a[i]);
        else v[p] = a[i];
    }

    v.clear();
    fdto(i, n, 1) {
        int p = lower_bound(v.begin(), v.end(), -a[i])-v.begin();
        fr[i] = p+1;
        if (p == sz(v)) v.pb(-a[i]);
        else v[p] = -a[i];
    }

    int L = *max_element(fl+1, fl+n+1);
    vector<int> cnt(n+1, 0);
    fto(i, 1, n) {
        if (fl[i]+fr[i]-1 == L) ++cnt[fl[i]];
    }
    fto(i, 1, n) {
        isGood[i] = (fl[i]+fr[i]-1 != L || cnt[fl[i]] > 1);
    }

    sort(q+1, q+m+1);

    vector<ii> p(n+1);
    fto(i, 1, n) p[i] = mp(a[i], i);
    sort(p.begin()+1, p.end());

    IT tl(n), tr(n); int j;
    j = 1;
    fto(i, 1, m)  {
        while (j <= n && p[j].ff < q[i].x) {
            tl.update(p[j].ss, fl[p[j].ss]);
            ++j;
        }
        xl[i] = tl.query(1, q[i].p-1);
    }
    j = n;
    fdto(i, m, 1) {
        while (j >= 1 && p[j].ff > q[i].x) {
            tr.update(p[j].ss, fr[p[j].ss]);
            --j;
        }
        xr[i] = tr.query(q[i].p+1, n);
    }
//    fto(i, 1, n) printf("%d %d\n", fl[i], fr[i]);
//    puts("");
//    fto(i, 1, m) printf("%d %d\n", xl[i], xr[i]);

    fto(i, 1, m) {
        // LIS passing through q[i]
        int x1 = xl[i]+xr[i]+1;

        // LIS not passing through q[i]
        int x2 = (isGood[q[i].p]) ? L : L-1;

        ans[q[i].id] = max(x1, x2);
    }

    fto(i, 1, m) printf("%d\n", ans[i]);

    return 0;
}