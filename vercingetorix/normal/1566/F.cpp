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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);
        vll a(n);
        forn(i,0,n) scanf("%lld", &a[i]);
        a.pb(1e15);
        srt(a);
        vpi eo;
        forn(i,0,m) {
            int l,r;
            scanf("%d %d", &l, &r);
            eo.pb(mp(l, -r));
        }
        vpi e2;
        srt(eo);
        for(auto x : eo) {
            while(!e2.empty() && e2.back().second >= -x.second) e2.pop_back();
            e2.pb(mp(x.first, -x.second));
        }
        vpll e;
        for(auto x : e2) if(lower_bound(all(a), x.first) == lower_bound(all(a), x.second+1)) e.pb(x);
//        printf("%d\n", e.size());
//        for(auto x : e) printf("%d %d\n", x.first, x.second);
        ll d0 = 0;
        ll d1 = 0;
        int pt = 0;
        ll last = -1e15;
        for(auto x : a) {
            int ptr = pt;
            while(ptr<e.size() && e[ptr].second < x) ptr++;
            ll nd0 = 1e18;
            ll nd1 = 1e18;
            if(ptr == pt) {
                nd0 = min(d0, d1);
                nd1 = nd0;
            }
            else {
                nd0 = min(nd0, d0 + x-e[pt].second);
                nd1 = min(nd1, d0 + ll(x-e[pt].second)*2);
                nd1 = min(nd1, d1 + e[ptr-1].first -last);
                nd1 = min(nd1, d0 + 2*(e[ptr-1].first -last));
                forn(l,1,ptr-pt) {
                    auto ml = e[pt + l - 1];
                    auto mr = e[pt + l];
                    ll mb = min(d0 + 2*(ml.first - last), d1 + (ml.first - last));
                    nd0 = min(nd0, mb + x - mr.second);
                    nd1 = min(nd1, mb + 2*(x-mr.second));
                }
            }
            nd0 = min(nd0, nd1);
            last = x;
            d0 = nd0;
            d1 = nd1;
            pt = ptr;
        }
        printf("%lld\n", min(d0,d1));
        
    }
    
    
}