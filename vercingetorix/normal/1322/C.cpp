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

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        int n,m;
        scanf("%d %d", &n, &m);
        vll c(n);
        forn(i,0,n) scanf("%lld", &c[i]);
        vvi to(n);
        
        vvi bys(n+1);
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            to[v].pb(u);
        }
        forn(i,0,n) bys[to[i].size()].pb(i);
        ll ans = 0;
        forn(s,1,n+1) {
            vector<pair<vi, int>> x;
            for(auto ind : bys[s]) {
                srt(to[ind]);
                x.pb(mp(to[ind], ind));
            }
            srt(x);
            ll cur = 0;
            forn(i,0,x.size()) {
                if(i == 0 || x[i].first == x[i-1].first) cur+=c[x[i].second];
                else {
                    ans = gcd(ans, cur);
                    cur = c[x[i].second];
                }
            }
            ans = gcd(ans, cur);
        }
        printf("%lld\n", ans);
        
    }
    
    
}