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

vpll split(ll l, ll r) {
    vpll ret;
    ll cur = l;
    ll d2 = 1;
    int deg = 0;
    r++;
    while(1) {
        while(cur%(2*d2) == 0 && cur + 2*d2 <= r) {
            d2*=2;
            deg++;
        }
        if(cur + d2 > r) break;
        ret.pb(mp(cur, deg));
        cur += d2;
    }
    while(deg > 0) {
        d2 /= 2;
        deg--;
        if(cur + d2 <= r) {
            
            ret.pb(mp(cur, deg));
            cur+=d2;
        }
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        ll n,m;
        cin>>n>>m;
        auto pp = split(0, m-1);
        ll ans = 0;
        ll tot = 0;
        for(auto pcur : pp) {
            ll pref = pcur.first;
            vvll d(2, vll(2, 0));
            d[0][0] = 1;
            ll add = n + pref;
            int bit = 0;
            while(add > 0 || bit < pcur.second) {
                ll nx = add%2;
                add/=2;
                vvll nd(2, vll(2, 0));
                forn(p2,0,2) forn(last,0,2) forn(cur,0,1+int(bit<pcur.second)) {
                    if(nx + cur + last > 1) {
                        nd[p2^1][1] += d[p2][last];
                    }
                    else {
                        nd[p2][0] += d[p2][last];
                    }
                }
                bit++;
                d = nd;
            }
            forn(i,0,2) forn(j,0,2) tot += d[i][j];
            forn(last,0,2) ans += d[(__builtin_popcountll(pref) + __builtin_popcountll(n+pref))%2^1][last];
        }
        cout<<ans<<'\n';
    }
    
    
}