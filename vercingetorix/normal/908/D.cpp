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
    gcd(a, modulo, x, y);
    return (x%modulo+modulo)%modulo;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int k,a,b;
    cin>>k>>a>>b;
    ll p1 = ll(a) * invmod(a+b, mod) % mod;
    ll p2 = ll(b) * invmod(a+b, mod) % mod;
    vll d(k,0);
    d[0] = 1;
    ll ans = 0;
    forn(na,1,k) {
        vll nd = d;
        forn(i,0,k) nd[i] = nd[i] * p1 % mod;
        vll suf(k+1,0);
        forn(i,0,k) {
            ll curp = p1*p2%mod;
            ll pleft = p2;
            forn(nb,1,k+1) {
                ll nba = nb*na;
                if(i+nba >= k) {
                    ans = (ans + ll(i+nba) * pleft % mod * d[i]) % mod;
                    break;
                }
                nd[i+nba] = (nd[i+nba] + d[i] * curp) % mod;
                pleft =  (pleft + mod- curp)%mod;
                curp = curp * p2 % mod;
            }
        }
//        forn(nb,1,k) {
//            ll nba = nb*na;
//            forn(i,0,k-nba) {
//                nd[i+nba] = (nd[i+nba] + d[i] * curp)%mod;
//            }
//            ll fo = max(0ll, ll(k)-nba);
//            ans = (ans + suf[fo] * curp) % mod;
//            pleft =  (pleft + mod- curp)%mod;
//            curp = curp * p2 % mod;
//        }
//        ans = (ans + suf[0] * pleft) % mod;
        d = nd;
    }
    forn(i,0,k) {
        ans += (i+k + p1*invmod(p2,mod)) % mod * d[i] %mod;
    }
    ans %=mod;
    cout<<ans;
    
}