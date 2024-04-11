#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
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
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

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

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vll x(n); vll y(n);
    forn(i,0,n) scanf("%lld %lld", &x[i], &y[i]);
    ll mx = 0, my = 0;
    forn(i,0,n) mx += 2*x[i], my += 2*y[i];
    forn(i,0,n) x[i] *= n*2, y[i] *= n*2;
    vi dead(n, 0);
    forn(i,0,n) if(x[i] == mx && y[i] == my) {
        dead[i] = 1;
    }
    forn(i,0,n) forn(j,i+1,n) {
        if(!dead[i] && !dead[j] && x[i]-mx == mx-x[j] && y[i]-my == my-y[j]) {
            dead[i] = 1;
            dead[j] = 1;
        }
    }
    vll nx, ny;
    forn(i,0,n) if(!dead[i]) nx.pb(x[i]), ny.pb(y[i]);
    x = nx;
    y = ny;
    n = x.size();
    if(n <= 2) {
        printf("-1");
        return 0;
    }
    vector<pt> poly;
    forn(i,0,n) poly.pb(pt(x[i], y[i]));
    convex_hull(poly);
    if(poly.size() == 1) {
        printf("-1");
        return 0;
    }
    else if(poly.size() == 2) {
        bool can = true;
        sort(all(x));
        forn(i,0,n) if(mx-x[i] != x[n-1-i] - mx) can = false;
        if(can) printf("-1");
        else printf("1");
        return 0;
    }
    int k = poly.size();
    vpi q;
    forn(i,0,k) {
        pt a = poly[i];
        pt b = poly[(i+1)%k];
        forn(j,i+1,i+n-1) {
            pt c = poly[j % k];
            pt d = poly[(j+1) % k];
            pt e = poly[(j+2) % k];
            pt bcd(b.x + d.x - c.x, b.y + d.y - c.y);
            pt aed(a.x + d.x - e.x, a.y + d.y - e.y);
            if(!cw(bcd, b, a) && !cw(aed, b, a)) {
                q.pb(mp((j+1)%k, i%k));
                q.pb(mp((j+1)%k, (i+1)%k));
            }
        }
    }
    vpll ans;
    for(auto pix : q) {
        pt a = poly[pix.first];
        pt b = poly[pix.second];
        ll px = (a.x + b.x)/2;
        ll py = (a.y + b.y)/2;
        px -= mx;
        py -= my;
        ll d = gcd(abs(px), abs(py));
        px/=d;
        py/=d;
        vll dist;
        forn(i,0,n) {
            ll tx = x[i] - mx;
            ll ty = y[i] - my;
            dist.pb(-tx/2*py + ty/2*px);
        }
        sort(all(dist));
        bool can = true;
        forn(i,0,n) if(dist[i] + dist[n-1-i] != 0) can = false;
        if(can) {
            ll d = gcd(abs(px), abs(py));
            px /= d;
            py /= d;
            if(py < 0) {
                px = -px;
                py = -py;
            }
            else if(py == 0 && px < 0) {
                px = -px;
                py = -py;
            }
            ans.pb(mp(px, py));
        }
    }
    sort(all(ans));
    int res = 0;
    forn(i,0,ans.size()) if(i == 0 || ans[i] != ans[i-1]) res++;
    cout<<res;
    
    
}