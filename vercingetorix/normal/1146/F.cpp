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

const long long mod = 998244353 ;
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
const int A = 200500;
vi ch[A];

pll dfs(int v) {
    ll a = 1;
    ll b = 1;
//    ll sb = 0;
    if(ch[v].empty()) return mp(1,2);
    ll sinv = 0;
//    ll binv = 0;
    for(auto u: ch[v]) {
        pll x = dfs(u);
        a = a*x.first%mod;
        b = b*x.second%mod;
//        sb += x.second;
        sinv = (sinv + (mod+x.second-x.first)*invmod(x.first,mod))%mod;
//        binv = (binv + x.second*invmod(x.first, mod))%mod;
//        cur = cur*(x+1)%mod;
//        p = p*x %mod;
//        sinv = (sinv + invmod(x, mod))%mod;
    }
//    sb %= mod;
    ll part = (b+ mod - a*sinv%mod)%mod;
    ll hand = a*(sinv+1)%mod;
    return mp(part, (hand + (mod+part - a) * 2)%mod);
//    cur = (cur +mod- p*sinv%mod)%mod;
//    return cur;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    forn(i,1,n) {
        int p;
        scanf("%d", &p);
        p--;
        ch[p].pb(i);
    }
    cout<<dfs(0).first;
    
    
}