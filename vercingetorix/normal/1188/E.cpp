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

const long long mod = 998244353;
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
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

vll imod;

class cnk {
public:
    ll curc, ck, cn;
    void adjust(ll n, ll k) {
        if(k>n) {
            curc = 0;
            return;
        }
        while(ck > k) {
            curc = curc*ck%mod;
            curc = curc*imod[cn-ck+1]%mod;
            ck--;
        }
        while(cn < n) {
            curc = curc * (cn+1)%mod;
            curc = curc * imod[cn-ck+1]%mod;
            cn++;
        }
        while(ck < k) {
            curc = curc * (cn-ck)%mod;
            curc = curc * imod[ck+1]%mod;
            ck++;
        }
        while(cn > n) {
            curc = curc * (cn-ck) %mod;
            curc = curc *imod[cn] % mod;
            cn--;
        }
    }
};


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    imod.pb(0);
    forn(i,1,2000500) imod.pb(invmod(i, mod));
    cnk c;
    int n;
    read(n);
    vll dist;
    c.cn = n-1;
    c.ck = n-1;
    c.curc = 1;
    forn(i,0,1000011) {
        c.adjust(n-1+i, n-1);
        dist.pb(c.curc);
    }
    
    readv(a,n);
    srt(a);
    set<pi> q;
    int dec = 0;
    forn(i,0,n) q.insert(mp(a[i], i));
    int forced = 0;
    vi vis(n,0);
    int fr = n;
    ll ans = 0;
    forn(p, 0, 1000001) {
        while(q.begin()->first - dec < p-forced) {
            pi x = *q.begin();
            q.erase(q.begin());
            forced++;
            dec++;
            if(forced > p) break;
            a[x.second] += n;
            q.insert(mp(a[x.second], x.second));
            if(vis[x.second] == 0) {
                vis[x.second] = 1;
                fr--;
            }
        }
        if(forced > p) break;
        ans = (ans + dist[p-forced])%mod;
        if(p-forced >= fr) {
            ans= (ans + mod - dist[p-forced-fr])%mod;
        }
        ans = ans;
    }
    cout<<ans;
    
}