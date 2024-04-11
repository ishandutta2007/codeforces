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
const int A = 1500;
vi g[A];
int st[A];
vi ch[A];
void dfs(int v, int p) {
    st[v] = 1;
    for(auto u : g[v]) {
        if(u == p) continue;
        ch[v].pb(u);
        dfs(u, v);
        st[v] += st[u];
    }
}
int ans[A];
int x[A];
int y[A];
Point<ll> p[A];
ll s32(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

ll s3(int i, int j, int k) {
    return s32(x[i], y[i], x[j], y[j], x[k], y[k]);
}

bool cw(int i, int j, int k) {
    return s3(i,j,k) < 0;
}

bool ccw(int i, int j, int k) {
    return s3(i,j,k) > 0;
}
void go(int v, int champ, vi & left) {
//    cout<<v<<' '<<champ;
//    for(auto x : left) cout<<' '<<x;
//    cout<<'\n';
    ans[champ] = v+1;
    if(left.empty()) return;
    vector<pair<pi, int>> ev;
    for(auto i : left) {
        ev.pb(mp(mp(x[i]-x[champ], y[i] - y[champ]), i));
    }
    sort(all(ev), [&](const pair<pi, int> & a, const pair<pi, int> & b) {
        //        return a.first.first < b.first.first;
        bool ha = a.first.second > 0 || (a.first.second == 0 && a.first.first > 0);
        bool hb = b.first.second > 0 || (b.first.second == 0 && b.first.first > 0);
        if(ha) {
            if(hb == false) return true;
            if(a.first.second == 0) return b.first.second > 0;
            else if(b.first.second == 0) return false;
            return ll(a.first.first)*b.first.second > ll(b.first.first)*a.first.second;
        }
        else {
            if(hb == true) return false;
            if(a.first.second == 0) return b.first.second < 0;
            else if(b.first.second == 0) return false;
            return ll(a.first.first)*b.first.second > ll(b.first.first)*a.first.second;
        }
    });
    if(ev.size() > 1) {
        int pt = 0;
        while(1) {
            int pt1 = (pt+1)%ev.size();
            if(ccw(ev[pt1].second, ev[pt].second, champ)) {
                rotate(ev.begin(), ev.begin()+pt1, ev.end());
                break;
            }
            pt = pt1;
        }
    }
    int pt = 0;
    for(auto u : ch[v]) {
        int l = st[u];
        int closest = ev[pt++].second;
        vi next;
//        auto proj = p[closest] - p[champ];
//        Point<ll> norm;
//        norm.x = -proj.y;
//        norm.y = proj.x;
//        ll best = proj.dot(proj);
        forn(i,0,l-1) {
            int ind = ev[pt++].second;
            next.pb(ind);
//            ll cand = (p[ind] - p[champ]).dot(proj);
//            if(cand < best) {
//                best = cand;
//                closest = ind;
//            }
        }
//        forn(i,0,next.size()) {
//            if(next[i] == closest) {
//                swap(next[i], next.back());
//                next.pop_back();
//                break;
//            }
//        }
        go(u, closest, next);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(0,0);
    int bi = 0;
    forn(i,0,n){
        scanf("%d %d", &x[i], &y[i]);
        if(mp(x[i], y[i]) < mp(x[bi], y[bi])) bi = i;
    }
    forn(i,0,n) {
        p[i].x = x[i];
        p[i].y = y[i];
    }
    vi left;
    forn(i,0,n) if(i!=bi) left.pb(i);
    go(0, bi, left);
    forn(i,0,n) printf("%d ", ans[i]);
    
}