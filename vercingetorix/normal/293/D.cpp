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

struct pt {
    pt(ll x, ll y) : x(x), y(y) {};
    ll x, y;
};

bool cmp (pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

// returns clockwise??
void convex_hull (vector<pt> & a) {
    if (a.size() == 1)  return;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
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

ll get;
double ans = 0;
double num = 0;
vector<pt> a;
void solve() {
    const int INF = 1e7;
    pi l = mp(INF,-1);
    pi r = mp(-INF,-1);
    forn(i,0,a.size()) {
        l = min(l, mp((int)a[i].x, i));
        r = max(r, mp((int)a[i].x, i));
    }
    vi u(r.first-l.first+1, -INF);
    vi d(r.first-l.first+1, INF);
    pt pl = a[l.second];
    pt pr = a[r.second];
    forn(i,0,a.size()) {
        pt p1 = a[i];
        pt p2 = a[(i+1)%a.size()];
        int side = -1;
        if(ccw(pl, pr, p1) || ccw(pl, pr, p2)) side = 1;
        if(cw(pl, pr, p1) || cw(pl, pr, p2)) side = 0;
        if(side == -1) {
            pt p3 = a[(i+2)%a.size()];
            if(ccw(pl,pr,p3)) side = 0;
            else side = 1;
        }
        if(p1.x == p2.x) {
            d[p1.x-l.first] = min((ll)d[p1.x-l.first], min(p1.y, p2.y));
            u[p1.x-l.first] = max((ll)u[p1.x-l.first], max(p1.y, p2.y));
        }
        else {
            if(p1.x > p2.x) swap(p1,p2);
            ll cl = p1.x;
            ll cr = p2.x;
            forn(pos,cl,cr+1) {
                if(side == 1) {
                    ll up = (p2.y*(pos-cl) + p1.y*(cr-pos))/(cr-cl);
                    u[pos-l.first] = max((ll)u[pos-l.first], up);
                }
                else {
                    ll down = (p2.y*(pos-cl) + p1.y*(cr-pos)+cr-cl-1)/(cr-cl);
                    d[pos-l.first] = min((ll)d[pos-l.first], down);
                }
            }
        }
    }
    vll cnt;
    forn(i,0,u.size()) cnt.pb(u[i]-d[i]+1);
    double s2 = 0;
    double s = 0;
    ll tot = 0;
    forn(i,0,cnt.size()) {
        s += cnt[i]*i;
        s2 += double(cnt[i])*i*i;
        tot += cnt[i];
    }
    ans += 2*tot*s2-2*s*s;
    num = double(tot)*(tot-1);
//    for(auto x : cnt) printf("%d ", x);
//    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int n;
    read(n);
    
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x, &y);
        a.emplace_back(x+1000000, y+1000000);
    }
    convex_hull(a);
    solve();
    forn(i,0,a.size()) {
        swap(a[i].x, a[i].y);
    }
    num = 0;
    solve();
    num*=2;
    printf("%.10lf", (double)ans / (double)num);
    
    
}