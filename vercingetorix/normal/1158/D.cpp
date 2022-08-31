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

ld cross(pi a, pi b) {
    ld x1 = a.first;
    ld y1 = a.second;
    ld x2 = b.first;
    ld y2 = b.second;
    return acos((x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2)));
}

pi dif(pi a, pi b) {
    return mp(a.first-b.first, a.second-b.second);
}

struct pt {
    pt(ll x, ll y) : x(x), y(y) {};
    ll x, y;
};

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

pt dif(pt a, pt b) {
    return pt(a.x-b.x, a.y-b.y);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vi x(n), y(n);
    forn(i,0,n) scanf("%d %d\n", &x[i], &y[i]);
    vpi xy;
    forn(i,0,n) xy.pb(mp(x[i], y[i]));
    vi taken(n,0);
    vector<pt> p;
    forn(i,0,n) p.emplace_back(x[i], y[i]);
    int cur = 0;
    forn(i,0,n) if(mp(x[i], y[i]) < mp(x[cur], y[cur])) cur = i;
//    pi op = mp(0,1);
    char c[2234];
    scanf("%s", c);
    printf("%d", cur+1);
    taken[cur] = 1;
    forn(ind, 0, n-2) {
        int was = cur;
        cur = 0;
        while(taken[cur]) cur++;
//        ld best = cross(dif(xy[cur], xy[was]), op);
        forn(i,0,n) {
            if(taken[i] || i == cur) continue;
            if(ccw(p[was], p[cur], p[i])) {
                if(c[ind] == 'R') cur = i;
            }
            else {
                if(c[ind] == 'L') cur = i;
            }
//            if(taken[i]) continue;
//            ld ang = cross(op, dif(xy[i], xy[was]));
//            if(c[ind] == 'L' && ang > best) cur = i, best = ang;
//            if(c[ind] == 'R' && ang < best) cur = i, best = ang;
        }
        printf(" %d", cur+1);
//        if(c[ind] == 'L') op = dif(xy[was], xy[cur]);
//        else op = dif(xy[cur], xy[was]);
        taken[cur] = 1;
    }
    cur = 0;
    while(taken[cur]) cur++;
    printf(" %d", cur+1);
    
    
}