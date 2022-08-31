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
vll imod(1,0);
int cn;
int ck;
ll curc;

void up() {
    curc = curc*(cn-ck) % mod;
    curc = curc*imod[ck+1] % mod;
    ck++;
}

void down() {
    curc = curc*(cn-ck) % mod;
    curc = curc*imod[cn] %mod;
    cn--;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int A = 100500;
    forn(i,1,A+1) imod.pb(invmod(i,mod));
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d %d", &n, &k);
        vll sp(1, 1);
        cn = n;
        ck = 1;
        curc = n;
        while(1) {
            sp.pb(curc);
            if(cn-ck >= k) {
                forn(i,0,k-1) down();
                up();
            }
            else break;
        }
        ll curp = 1;
        ll ans = 1;
        forn(i,1,sp.size()) {
            ll pcont = sp[i]*i % mod;
            pcont = pcont * invmod(sp[i-1], mod) % mod;
            pcont = pcont * imod[n-i+1] % mod;
            curp = curp*pcont%mod;
            ans =  (ans + curp)%mod;
        }
        printf("%lld\n", ans);
    }
    
}