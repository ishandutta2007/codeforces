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
#define MOD 1000
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

struct Element {
    ll x;
    int ind;
    bool inline operator < (const Element &rhs) const {
        return x < rhs.x;
    }
};

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

    Element query(int id, int l, int r, const int &i, const int &j) {
        if (l > j || r < i) return {-oo, -1};
        if (i <= l && r <= j) return t[id];
        int m = (l+r)/2;
        return max(query(2*id, l, m, i, j), query(2*id+1, m+1, r, i, j));
    }
public:
    void init(int n) {
        this->n = n;
        t.assign(4*n+1, {-oo, -1});
    }
    void update(int p, Element e) {update(1, 1, n, p, e);}
    Element query(int i, int j) {return query(1, 1, n, i, j);}
};

int n, q, h[2*maxN], s[2*maxN];
ll d[2*maxN], a[2*maxN], b[2*maxN];
IT t1, t2;

ll Solve(int l, int r) {
//    printf("%d %d\n", l, r);
    Element maxA = t1.query(l, r);
    Element maxB = t2.query(l, r);
    ll res;
    if (maxA.ind == maxB.ind) {
        t1.update(maxA.ind, {-oo, -1});
        t2.update(maxB.ind, {-oo, -1});
        ll xA = t1.query(l, r).x;
        ll xB = t2.query(l, r).x;
        t1.update(maxA.ind, maxA);
        t2.update(maxB.ind, maxB);
        res = max(xA + maxB.x, xB + maxA.x);
    } else
        res = maxA.x + maxB.x;
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, n) scanf("%d", &s[i]);
    fto(i, 1, n) scanf("%d", &h[i]);

    fto(i, 1, 2*n) {
        if (i > n) {
            s[i] = s[i-n];
            h[i] = h[i-n];
        }
        d[i] = d[i-1]+s[i];
        a[i] = 2*h[i]+d[i-1];
        b[i] = 2*h[i]-d[i-1];
    }

//    fto(i, 1, 2*n) printf("%lld %lld\n", a[i], b[i]);

    t1.init(2*n);
    t2.init(2*n);
    fto(i, 1, 2*n) t1.update(i, {a[i], i});
    fto(i, 1, 2*n) t2.update(i, {b[i], i});

    fto(i, 1, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l <= r)
            printf("%lld\n", Solve(r+1, l+n-1));
        else
            printf("%lld\n", Solve(r+1, l-1));
    }

    return 0;
}