#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
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

const double EPS = 1e-9;

struct pt {
    double x, y;
    bool operator == (pt p) {
        return abs(x-p.x) < EPS && abs(y-p.y) < EPS;
    }
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (double k) {return {x*k, y*k};}
    pt operator / (double k) {return {x/k, y/k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    double operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream &is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream &os, pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

struct Edge {
    int u, v;
    double w;
};

double mag(pt v) {
    return hypot(v.x, v.y);
}

double dist(pt a, pt b) {
    return mag(b-a);
}

double orient(pt a, pt b, pt c) {
    return (b-a)*(c-a);
}

int sign(double x) {
    return (x > EPS) - (x < -EPS);
}

bool onSegment(pt a, pt b, pt p) {
    return (sign(orient(a, b, p)) == 0 && (a-p)%(b-p) < 0);
}

bool properInter(pt a, pt b, pt c, pt d, pt &out) {
    double oa = orient(c, d, a), ob = orient(c, d, b);
    double oc = orient(a, b, c), od = orient(a, b, d);
    if (sign(oa)*sign(ob) < 0 && sign(oc)*sign(od) < 0) {
        out = (a*ob - b*oa)/(ob - oa);
        return true;
    }
    return false;
}

vector<pt> inter(pt a, pt b, pt c, pt d) {
    pt out;
    if (properInter(a, b, c, d, out))
        return {out};
    vector<pt> res;
    if (onSegment(c, d, a)) res.pb(a);
    if (onSegment(c, d, b)) res.pb(b);
    if (onSegment(a, b, c)) res.pb(c);
    if (onSegment(a, b, d)) res.pb(d);
    return res;
}

bool cmpProj(pt a, pt b, pt p, pt q) {
    pt v = b-a;
    return v%p < v%q;
}

const int MAXN = 105;
const double INF = 1e9;

double shortestPath(vector<Edge> &e, int s, int t) {
    int n = max(s, t) + 1;
    fto(i, 0, sz(e)-1) n = max(n, max(e[i].u, e[i].v) + 1);

    vector<vector<int> > g(n, vector<int>());
    fto(i, 0, sz(e)-1) {
        g[e[i].u].pb(i);
        g[e[i].v].pb(i);
    }

    vector<double> d(n, INF);
    d[s] = 0;

    vector<bool> avail(n, true);

    priority_queue<pdi, vector<pdi>, greater<pdi> > pq;
    pq.push(mp(d[s], s));

    while (!pq.empty()) {
        int u = pq.top().ss; pq.pop();
        avail[u] = false;
        for(int i: g[u]) {
            int v = e[i].u + e[i].v - u;
            double w = e[i].w;
            if (avail[v] && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(mp(d[v], v));
            }
        }
    }

    return d[t];
}


pt a, b, po[MAXN];
int n;
vector<Edge> e;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cout << setprecision(50);

    cin >> a >> b;
    cin >> n;
    fto(i, 0, n-1) cin >> po[i];

    int id = n;
    fto(i, 0, n-1) {
        vector<pt> p = inter(a, b, po[i], po[(i+1)%n]);
        if (sz(p) == 1) {
            bool dup = false;
            fto(j, n, id-1)
                if (po[j] == p[0]) dup = true;
            if (dup) continue;

            po[id] = p[0];
            e.pb({i, id, dist(po[id], po[i])});
            e.pb({(i+1)%n, id, dist(po[id], po[(i+1)%n])});
            ++id;
        }
    }

//    fto(i, 0, id-1) cout << po[i] << endl;
    if (id < n+2) {
        cout << dist(a, b);
        return 0;
    }

    fto(i, 0, n-1)
        e.pb({i, (i+1)%n, dist(po[(i+1)%n], po[i])});

    e.pb({n, n+1, 2*dist(po[n], po[n+1])});

    if (cmpProj(a, b, po[n], po[n+1])) {
        e.pb({n, n+2, dist(a, po[n])});
        e.pb({n+1, n+3, dist(b, po[n+1])});
    } else {
        e.pb({n, n+3, dist(b, po[n])});
        e.pb({n+1, n+2, dist(a, po[n+1])});
    }

    cout << shortestPath(e, n+2, n+3);

    return 0;
}