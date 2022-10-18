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

struct pt {
    ll x, y;
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (ll k) {return {x*k, y*k};}
    ll operator * (pt p) {return x*p.y - y*p.x;}
    ll operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream& is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream& os, const pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

ll sq(pt p) {return p.x*p.x + p.y*p.y;}

bool half(pt p) {
    return (p.y > 0 || (p.y == 0 && p.x < 0));
}

struct cmpPt {
    bool operator() (pt v, pt w) {
        return make_tuple(half(v), 0, sq(v)) < make_tuple(half(w), v*w, sq(w));
    }
};

set<pt, cmpPt> s;
pt piv;

set<pt>::iterator nextCir(set<pt>::iterator it, int k = 1) {
    for(int i = 0; i < k; ++i) {
        ++it;
        if (it == s.end())
            it = s.begin();
    }
    return it;
}

set<pt>::iterator prevCir(set<pt>::iterator it, int k = 1) {
    for(int i = 0; i < k; ++i) {
        if (it == s.begin())
            it = s.end();
        --it;
    }
    return it;
}

ll orient(pt a, pt b, pt c) {
    return (b-a)*(c-a);
}

bool half(pt a, pt p) {
    return a*p >= 0;
}

bool crossesRay(pt a, pt p, pt q) {
    return (half(a, q) - half(a, p))*orient(a, p, q) > 0;
}

bool onSegment(pt p, pt a, pt b) {
    return orient(p, a, b) == 0 && (a-p)%(b-p) <= 0;
}

bool isIn(pt a) {
    if (a.x == 0 && a.y == 0)
        return true;
    set<pt>::iterator it = s.lower_bound(a);
    if (it == s.end())
        it = s.begin();

    pt q = *it, p = *prevCir(it);

    return (onSegment(a, p, q) || crossesRay(a, p, q));
}

void insert(pt a) {
    if (isIn(a))
        return;

    set<pt>::iterator it = s.lower_bound(a);
    if (it == s.end())
        it = s.begin();

    while (sz(s) > 2 && orient(a, *it, *nextCir(it)) <= 0) {
        it = nextCir(it);
        s.erase(prevCir(it));
    }

    it = prevCir(it);
    while (sz(s) > 2 && orient(a, *it, *prevCir(it)) >= 0) {
        it = prevCir(it);
        s.erase(nextCir(it));
    }

    s.insert(a);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    pt p, a[3];
    int type;
    fto(i, 0, 2) {
        cin >> type >> a[i];
        piv = piv + a[i];
        a[i] = a[i]*3;
    }

    fto(i, 0, 2)
        s.insert(a[i] - piv);

    fto(i, 4, q) {
        cin >> type >> p;
        p = p*3 - piv;

        if (type == 2) {
            bool ans = isIn(p);
            cout << (ans ? "YES" : "NO") << endl;
        } else {
            insert(p);
        }
    }

    return 0;
}