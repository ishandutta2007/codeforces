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


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi g,r,b;
    forn(i,0,n) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        if ( c=='G') g.pb(x);
        else if(c=='B') b.pb(x);
        else if(c=='R') r.pb(x);
    }
    ll ans = 0;
    if(g.empty()) {
        if(!b.empty()) ans += (ll)(b.back()-b[0]);
        if(!r.empty()) ans += (ll)(r.back()-r[0]);
        cout<<ans;
        return 0;
    }
    int ptb = 0;
    int ptr = 0;
    int ptg = 0;
    if(ptb < b.size() && b[ptb] < g[0]) {
        ans += ll(g[0] - b[ptb]);
        while(ptb<b.size() && b[ptb] < g[0]) ptb++;
    }
    if(ptr < r.size() && r[ptr] < g[0]) {
        ans += ll(g[0] - r[ptr]);
        while(ptr<r.size() && r[ptr] < g[0]) ptr++;
    }
    int lastg = g[0];
    ptg++;
    while(ptg<g.size()) {
//        if((ptr>=r.size() || r[ptr]> g[ptg]) || (ptb>=b.size() || b[ptb] > g[ptg])) {
//            ans += ll(g[ptg]-lastg);
//            if(!((ptr>=r.size() || r[ptr]> g[ptg]) && (ptb>=b.size() || b[ptb] > g[ptg]))) {
//                ans += ll(g[ptg]-lastg);
//            }
//        }
//        else {
            int maxr = 0;
            int maxb = 0;
            vi rc;
            vi bc;
            rc.pb(lastg);
            bc.pb(lastg);
            while(ptr<r.size() && r[ptr] < g[ptg]) rc.pb(r[ptr++]);
            while(ptb<b.size() && b[ptb] < g[ptg]) bc.pb(b[ptb++]);
            rc.pb(g[ptg]);
            bc.pb(g[ptg]);
            forn(i,0,int(rc.size())-1) {
                maxr = max(maxr, rc[i+1]-rc[i]);
            }
            forn(i,0,int(bc.size())-1) {
                maxb = max(maxb, bc[i+1]-bc[i]);
            }
            ll mr = maxr;
            ll mb = maxb;
            ll l = g[ptg] - lastg;
            ans += min(2*l, 3*l-mr-mb);
//        }
        while(ptr<r.size() && r[ptr] < g[ptg]) ptr++;
        while(ptb<b.size() && b[ptb] < g[ptg]) ptb++;
        lastg = g[ptg++];
    }
    if(ptr<r.size()) ans += ll(r.back()-lastg);
    if(ptb<b.size()) ans += ll(b.back()-lastg);
    cout<<ans;
    
}