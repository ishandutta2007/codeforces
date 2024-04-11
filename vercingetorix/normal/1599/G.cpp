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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
#ifdef LOCAL
const int A = 10;
#else
const int A = 200500;
#endif
int n,k;
ll x[A];
ll y[A];
ll sq(ll u) {
    return u*u;
}

ld dist(pi p1, pi p2) {
    return sqrt(ld(sq(p1.first-p2.first)+sq(p1.second-p2.second)));
}

ld dist(int i, int j) {
    return sqrt(ld(sq(x[i]-x[j])+sq(y[i]-y[j])));
}

void fin(ld x) {
    printf("%.12lf", (double) x);
    exit(0);
}

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

pi norm(int f, int to) {
    int cx = x[to] - x[f];
    int cy = y[to] - y[f];
    if(cx < 0 || (cx == 0 && cy < 0)) cx*=-1, cy*=-1;
    int d = gcd(abs(cx), abs(cy));
    cx/=d;
    cy/=d;
    return mp(cx, cy);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &k);
    k--;
    forn(i,0,n) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    if(n == 3) fin(dist((k+1)%3, (k+2)%3) + min(dist(k,(k+1)%3), dist(k,(k+2)%3)));
    map<pi, int> v;
    forn(i,0,n) if(i!=k) v[norm(k, i)]++;
    if(v.size() > 2) {
        vpi ap;
        forn(i,0,n) if(i!=k) ap.pb(mp(x[i], y[i]));
        srt(ap);
        x[2] = x[k];
        y[2] = y[k];
        x[0] = ap[0].first;
        y[0] = ap[0].second;
        x[1] = ap.back().first;
        y[1] = ap.back().second;
        k = 2;
        fin(dist((k+1)%3, (k+2)%3) + min(dist(k,(k+1)%3), dist(k,(k+2)%3)));
    }
    int pt = 0;
    while(1) {
        if(pt == k) pt++;
        if(v[norm(k, pt)] == 1)  break;
        else pt++;
    }
    vpi ap;
    forn(i,0,n) if(i!=pt) ap.pb(mp(x[i], y[i]));
    srt(ap);
    int num = 0;
    pi pk = mp((int)x[k], (int)y[k]);
    pi p = mp(x[pt], y[pt]);
    while(ap[num] != pk) num++;
    ld ans = 1e14;
    ans = min(ans, dist(pk, p) + dist(p, ap[0]) + dist(ap[0], ap.back()));
    ans = min(ans, dist(pk, p) + dist(p, ap.back()) + dist(ap[0], ap.back()));
    if(num == 0) {
        ans = min(ans, dist(pk, p) + dist(p, ap.back()) + dist(ap[1], ap.back()));
        ans = min(ans, dist(pk, p) + dist(p, ap[1]) + dist(ap[1], ap.back()));
    }
    else if(num == n-2) {
        ans = min(ans, dist(pk, p) + dist(p, ap[n-3]) + dist(ap[0], ap[n-3]));
        ans = min(ans, dist(pk, p) + dist(p, ap[0]) + dist(ap[0], ap[n-3]));
    }
    else {
        ans = min(ans, dist(ap[0], ap[num]) + dist(ap[0], p) + dist(ap[num+1], ap[n-2]) + min(dist(p, ap[num+1]), dist(p, ap[n-2])));
        ans = min(ans, dist(ap[n-2], ap[num]) + dist(ap[n-2], p) + dist(ap[num-1], ap[0]) + min(dist(p, ap[num-1]), dist(p, ap[0])));
    }
    ld d2 = dist(ap[0], ap[n-2]) + min(dist(ap[0], pk), dist(ap[n-2], pk));
    forn(i,0,n-2) {
        ans = min(ans, d2 + dist(ap[i], p) + dist(ap[i+1], p) - dist(ap[i], ap[i+1]));
    }
    ans = min(ans, dist(ap[0], ap.back()) + dist(pk, ap[0]) + dist(p, ap.back()));
    ans = min(ans, dist(ap[0], ap.back())+  dist(p, ap[0]) + dist(pk, ap.back()));
    fin(ans);
    
}