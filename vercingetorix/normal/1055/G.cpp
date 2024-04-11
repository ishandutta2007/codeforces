#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

const int MAXN = 1000; //  
const int INF = 1000000000; // -

struct edge {
    int a, b, cap, flow;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
            to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
        to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<ll> P;

bool cmp (P a, P b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw (P a, P b, P c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (P a, P b, P c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<P> & a) {
    if (a.size() == 1)  return;
    sort (a.begin(), a.end(), &cmp);
    P p1 = a[0],  p2 = a.back();
    vector<P> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back (down[i]);
}

P zr(0, 0);
vector<P> a;
vll ad;
vector<P> as;

ll s32(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool tooclose(P x, ll r) {
    ll dx = gcd(abs(x.x), abs(x.y));
    P xs(x.x/dx,x.y/dx);
    forn(i,0,a.size()) {
        int i1= (i+1)%a.size();
        if(cw(x,a[i],a[i1]) && cw(zr,x,a[i1]) && cw(zr,a[i],x)) return true;
        if((a[i]-x).dist2() < r*r) return true;
        if(as[i] == xs && abs(as[i].x) +abs(as[i].y) >= abs(x.x) + abs(x.y)) return true;
        ll d2u = (a[i]-x).dist2();
        ll d2v = (a[i1]-x).dist2();
        __int128 d2 = (a[i]-a[i1]).dist2();
        if(d2u>=d2v+d2) continue;
        if(d2v>=d2u+d2) continue;
        __int128 st = abs(s32(a[i].x,a[i].y,a[i1].x,a[i1].y,x.x,x.y));
        if(st*st < d2*r*r) return true;
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int nv,w;
    scanf("%d %d", &nv, &w);
    vll x(nv),y(nv);
    int l = w;
    int r = 0;
    vector<P> pt;
    forn(i,0,nv) {
        scanf("%lld %lld", &x[i], &y[i]);
        l = min(l,(int)x[i]);
        r = max(r,(int)x[i]);
        pt.emplace_back(x[i],y[i]);
    }
    //    vector<P> a;
    forn(i,0,nv) forn(j,0,nv) a.pb(pt[i]-pt[j]);
    convex_hull(a);
    forn(i,0,a.size()) ad.pb(gcd(abs(a[i].x), abs(a[i].y)));
    forn(i,0,a.size()) as.pb(P(a[i].x/ad[i], a[i].y/ad[i]));
    int bob = r-l;
    int m;
    read(m);
    vll mx(m),my(m),mr(m);
    forn(i,0,m) {
        scanf("%lld %lld %lld", &mx[i], &my[i], &mr[i]);
    }
    s = 2*m;
    t = 2*m+1;
    n = 2*m+2;
    forn(i,0,m) {
        add_edge(i, i+m, 1);
        if(bob + mr[i] > mx[i]) add_edge(s, i, 1);
        if(mx[i]+mr[i]+bob>w) add_edge(i+m, t, 1);
    }
    forn(i,0,m) forn(j,i+1,m) {
        ll dx = mx[j] - mx[i];
        ll dy = my[j] - my[i];
        ll sr = mr[i] + mr[j];
        ll sr2 = sr*sr;
        P vec(dx,dy);
        int bad = 0;
        //        if(sr2 < )
        if(tooclose(vec, mr[i]+mr[j])) bad  =1;
        if(bad) {
            add_edge(i+m, j, 1);
            add_edge(j+m, i, 1);
        }
    }
    cout<<dinic();
    
    
}