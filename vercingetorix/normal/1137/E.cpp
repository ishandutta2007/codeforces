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

ll mt(ll x, ll y) {
    return (y+x-1)/x;
}
ll a = 0;
ll b = 0;
set<pll> xa;
set<pll> evb;

ll INF = 1e18;
void go(ll x) {
    auto it = xa.lower_bound(mp(x, -2*INF));
    if(it->first != x) return;
    auto itr = it;
    itr++;
    if(it == xa.begin() || itr==xa.end()) {
        xa.erase(it);
        return;
    }
    auto itl = it;
    itl--;
    pll a1 = *itl;
    pll a2 = *itr;
    xa.erase(it);
    evb.insert(mp(mt(a2.first-a1.first, a1.second-a2.second), a2.first));
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    
    ll n,m;
    scanf("%lld %lld", &n, &m);
    xa.insert(mp(0,0));
    
    while(m--) {
        int tp;
        scanf("%d", &tp);
        if(tp == 1) {
            xa.clear();
            int k;
            scanf("%d", &k);
            n += k;
            a = 0;
            b = 0;
            xa.insert(mp(0, 0));
            evb.clear();
            printf("1 0\n");
        }
        else if(tp == 2) {
            int k;
            scanf("%d", &k);
            auto it = xa.end();
            --it;
            ll val = it->first*b + it->second + a;
            if(val == 0) {
                printf("%lld 0\n", it->first+1);
            }
            else {
                printf("%lld 0\n", n+1);
                pll nval = mp(n, -n*b-a);
                xa.insert(nval);
                evb.insert(mp(mt((nval.first - it->first), (it->second - nval.second)), nval.first));
            }
            n+=k;
        }
        else if(tp == 3) {
            ll ap, bp;
            scanf("%lld %lld", &ap, &bp);
            a+=ap;
            b+=bp;
            while(!evb.empty() && evb.begin()->first <= b) {
                ll del = evb.begin() -> second;
                evb.erase(evb.begin());
                go(del);
            }
            auto it = xa.end();
            it--;
            pll x = *it;
            printf("%lld %lld\n", x.first+1, x.first*b+a+x.second);
        }
    }
    
}