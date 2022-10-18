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

const double EPS = 1e-10;

struct pt {
    double x, y;
    bool operator == (pt p) {
        return (abs(x - p.x) < EPS) && (abs(y - p.y) < EPS);
    }
    bool operator < (pt p) {
        if (*this == p) return false;
        return (abs(x - p.x) < EPS) ? (y < p.y) : (x < p.x);
    }
    pt operator + (pt p) {
        return {x + p.x, y + p.y};
    }
    pt operator - (pt p) {
        return {x - p.x, y - p.y};
    }
    pt operator * (double k) {
        return {x * k, y * k};
    }
    pt operator / (double k) {
        return {x / k, y / k};
    }
    friend ostream& operator << (ostream& os, const pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    friend istream& operator >> (istream &is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
};

pt perp(pt p) {return {-p.y, p.x};}

double sq(pt p) {return p.x*p.x + p.y*p.y;}

double mag(pt p) {return hypot(p.x, p.y);}

double sq(double x) {return x*x;}

const int MAXN = 3;

int n, r[MAXN], cntV, cntE, cntC;
pt o[MAXN];
vector<pt> P;
vector<int> g[MAXN];
bool visited[MAXN];

bool addInter(pt o1, double r1, pt o2, double r2) {
    pt d = o2-o1; double d2 = sq(d);
    if (d2 < EPS) return false;
    double pd = (d2 + sq(r1) - sq(r2))/2;
    double h2 = sq(r1) - sq(pd)/d2;
    if (h2 >= 0) {
        pt p = o1 + d*pd/d2, h = perp(d)*sqrt(h2/d2);
        P.pb(p-h); P.pb(p+h);
        return true;
    }
    return false;
}

bool onCircle(pt o, double r, pt p) {
    return (abs(mag(o-p) - r) < EPS);
}

void DFS(int u) {
    visited[u] = true;
    for(int v: g[u])
        if (!visited[v]) DFS(v);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) {
        cin >> o[i] >> r[i];
        pt d = {r[i], 0};
        P.pb(o[i] + d);
    }

    fto(i, 0, n-1) {
        fto(j, i+1, n-1) {
            if (!addInter(o[i], r[i], o[j], r[j]))
                continue;
            g[i].pb(j);
            g[j].pb(i);
        }
    }

    sort(P.begin(), P.end());
    P.resize(unique(P.begin(), P.end()) - P.begin());

//    puts("P:");
//    for(pt p: P) cout << p << endl;

    cntV = sz(P);
    fto(i, 0, n-1)
        for(pt p: P)
            if (onCircle(o[i], r[i], p)) ++cntE;

    fto(u, 0, n-1) {
        if (!visited[u]) {
            ++cntC;
            DFS(u);
        }
    }

    int ans = cntE - cntV + cntC + 1;
    printf("%d", ans);

    return 0;
}