#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

using flow_t = int;
constexpr flow_t INF = 1e9+10;

struct MaxFlow {
    struct Edge {
        int dst, inv;
        flow_t flow, cap;
    };

    vector<vector<Edge>> G;
    vector<flow_t> add;
    Vi prev;

    // Initialize for n vertices
    MaxFlow(int n = 0) : G(n) {}

    // Add new vertex
    int addVert() {
        G.emplace_back(); return sz(G)-1;
    }

    // Add edge between u and v with capacity cap
    // and reverse capacity rcap
    void addEdge(int u, int v,
                 flow_t cap, flow_t rcap = 0) {
        G[u].pb({ v, sz(G[v]), 0, cap });
        G[v].pb({ u, sz(G[u])-1, 0, rcap });
    }

    // Compute maximum flow from src to dst.
    // Flow values can be found in edges,
    // vertices with `add` >= 0 belong to
    // cut component containing `s`.
    flow_t maxFlow(int src, int dst) {
        flow_t i, m, f = 0;
        each(v, G) each(e, v) e.flow = 0;

    nxt:
        queue<int> Q;
        Q.push(src);
        prev.assign(sz(G), -1);
        add.assign(sz(G), -1);
        add[src] = INF;

        while (!Q.empty()) {
            m = add[i = Q.front()];
            Q.pop();

            if (i == dst) {
                while (i != src) {
                    auto& e = G[i][prev[i]];
                    e.flow -= m;
                    G[i = e.dst][e.inv].flow += m;
                }
                f += m;
                goto nxt;
            }

            each(e, G[i])
                if (add[e.dst] < 0 && e.flow < e.cap) {
                    Q.push(e.dst);
                    prev[e.dst] = e.inv;
                    add[e.dst] = min(m, e.cap-e.flow);
                }
        }

        return f;
    }

    // Get if v belongs to cut component with src
    bool cutSide(int v) {
        return add[v] >= 0;
    }
};

// ---

// Base class of versions for ints and doubles
template<class T, class S> struct bvec2 {
    T x, y;
    S operator+(S r) const {return{x+r.x,y+r.y};}
    S operator-(S r) const {return{x-r.x,y-r.y};}
    S operator*(T r) const { return {x*r, y*r}; }
    S operator/(T r) const { return {x/r, y/r}; }

    T dot(S r)   const { return x*r.x+y*r.y; }
    T cross(S r) const { return x*r.y-y*r.x; }
    T len2()     const { return x*x + y*y; }
    S perp()     const { return {-y,x}; } //90deg

    pair<T, T> yxPair() const { return mp(y,x); }
};

// Version for integer coordinates (long long)
struct vec2i : bvec2<ll, vec2i> {
    vec2i() : bvec2{0, 0} {}
    vec2i(ll a, ll b) : bvec2{a, b} {}

    bool operator==(vec2i r) const {
        return x == r.x && y == r.y;
    }

    // Sort by angle, length if angles equal
    bool operator<(vec2i r) const {
        if (upper() != r.upper()) return upper();
        auto t = cross(r);
        return t > 0 || (!t && len2() < r.len2());
    }

    bool upper() const {
        return y > 0 || (y == 0 && x >= 0);
    }
};

using vec2 = vec2i;

// ---

// Base class of versions for ints and doubles
template<class P, class S> struct bseg2 {
    P a, b; // Endpoints
};

// Version for integer coordinates (long long)
struct seg2i : bseg2<vec2i, seg2i> {
    seg2i() {}
    seg2i(vec2i c, vec2i d) : bseg2{c, d} {}

    bool contains(vec2i p) {
        return (a-p).dot(b-p) <= 0 &&
               (a-p).cross(b-p) == 0;
    }

    // Compares distance to p with sqrt(d2),
    // -1 if smaller, 0 if equal, 1 if greater
    int cmpDistTo(vec2i p, ll d2) const {
        if ((p-a).dot(b-a) < 0) {
            ll l = (p-a).len2();
            return (l > d2) - (l < d2);
        }
        if ((p-b).dot(a-b) < 0) {
            ll l = (p-b).len2();
            return (l > d2) - (l < d2);
        }

        ll c = abs((p-a).cross(b-a));
        d2 *= (b-a).len2();
        return (c*c > d2) - (c*c < d2);
    }
};

using seg2 = seg2i;

// ---

// Get edge sequence for given polygon
// starting from lower-left vertex; time: O(n)
// Returns start position.
vec2 edgeSeq(vector<vec2> points,
             vector<vec2>& edges) {
    int i = 0, n = sz(points);
    rep(j, 0, n) {
        if (points[i].yxPair()>points[j].yxPair())
            i = j;
    }
    rep(j, 0, n) edges.pb(points[(i+j+1)%n] -
                          points[(i+j)%n]);
    return points[i];
}

// Minkowski sum of given convex polygons.
// Vertices are required to be in
// counter-clockwise order; time: O(n+m)
vector<vec2> hullSum(vector<vec2> A,
                     vector<vec2> B) {
    vector<vec2> sum, e1, e2, es(sz(A) + sz(B));
    vec2 pivot = edgeSeq(A, e1) + edgeSeq(B, e2);
    merge(all(e1), all(e2), es.begin());

    sum.pb(pivot);
    each(e, es) sum.pb(sum.back() + e);
    sum.pop_back();
    return sum;
}

// ---

// Check if p is inside convex polygon. Hull
// must be given in counter-clockwise order.
// Returns 2 if inside, 1 if on border,
// 0 if outside; time: O(n)
int insideHull(vector<vec2>& hull, vec2 p) {
    int ret = 1;
    rep(i, 0, sz(hull)) {
        auto v = hull[(i+1)%sz(hull)] - hull[i];
        auto t = v.cross(p-hull[i]);
        ret = min(ret, (t > 0) - (t < 0));
    }
    return int(max(ret+1, 0));
}

// Compare distance from point to hull
// with sqrt(d2); time: O(n)
int cmpHullDist(vector<vec2>& hull,
                vec2 p, ll d2) {
    if (insideHull(hull,p)) return (d2<0)-(d2>0);
    int ret = 1;
    rep(i, 0, sz(hull)) {
        seg2 seg{hull[(i+1)%sz(hull)], hull[i]};
        ret = min(ret, seg.cmpDistTo(p, d2));
    }
    return ret;
}

// ---

struct Circle {
    vec2 center;
    ll radius;
};

void run() {
    int n, w; cin >> n >> w;
    vector<vec2> bob(n), bobInv;
    ll minX = 1e18, maxX = -1e18;

    each(v, bob) {
        cin >> v.x >> v.y;
        bobInv.pb({ -v.x, -v.y });
        minX = min(minX, v.x);
        maxX = max(maxX, v.x);
    }

    bob = hullSum(bob, bobInv);

    ll width = maxX-minX;
    minX = -minX;
    maxX = w*2 - maxX;

    int m; cin >> m;

    vector<Circle> fishes(m);
    each(f, fishes) cin >> f.center.x >> f.center.y >> f.radius;

    MaxFlow flow(m*2+2);

    rep(i, 0, m) {
        ll x1 = fishes[i].center.x - fishes[i].radius;
        ll x2 = fishes[i].center.x + fishes[i].radius;
        flow.addEdge(i*2+2, i*2+3, 1);

        if (x1 < width) {
            flow.addEdge(0, i*2+2, INF);
        }
        if (x2 > w-width) {
            flow.addEdge(i*2+3, 1, INF);
        }

        rep(j, i+1, m) {
            auto p = fishes[i].center - fishes[j].center;
            auto r = fishes[i].radius + fishes[j].radius;

            if (cmpHullDist(bob, p, r*r) < 0) {
                flow.addEdge(i*2+3, j*2+2, INF);
                flow.addEdge(j*2+3, i*2+2, INF);
            }
        }
    }

    cout << flow.maxFlow(0, 1) << endl;
}