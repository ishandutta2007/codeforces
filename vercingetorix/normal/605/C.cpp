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

bool ccw (pt a, pt b, double x, double y) {
    return a.x*(b.y-y)+b.x*(y-a.y)+x*(a.y-b.y) > 0;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,p,q;
    scanf("%d %d %d", &n, &p, &q);
    int mxa = 0;
    int mxb = 0;
    vector<pt> a;
    a.pb(pt(0,0));
    forn(i,0,n) {
        int x, y;
        scanf("%d %d", &x, &y);
        a.pb(pt(x,y));
        mxa = max(mxa,x);
        mxb = max(mxb,y);
    }
    a.pb(pt(mxa,0));
    a.pb(pt(0,mxb));
    convex_hull(a);
//    cout<<a.size();
    double l = 0;
    double r = 2e6;
    forn(it,0,250) {
        double m = (l+r)/2;
        double x = p*m;
        double y = q*m;
        int in = 1;
        for(int i = 0; i < a.size(); i++) {
            int i1 = (i+1)%a.size();
            if(ccw(a[i], a[i1], x, y)) {
                in = 0;
                break;
            }
        }
        if(in) l = m;
        else r = m;
    }
    printf("%.10lf", 1./l);
    
    
}