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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
const int A = 100;
ll d[A+1][A+1];
ll fac[A+1];
ll ifac[A+1];
ll cfac[A+1][A+1];

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
    fac[0] = 1;
    for(ll i = 1; i<=A; i++) fac[i] = (fac[i-1]*i)%mod;
    forn(i,0,A+1) ifac[i] = invmod(fac[i], mod);
    d[0][0] = 1;
    forn(i,0,A+1) forn(j,0,i+1) cfac[i][j] = fac[i]*ifac[i-j]%mod;
    forn(b,0,A+1) forn(a,0,A+1) {
        if(a == 0) {
            if(b>0) d[0][b] = (d[0][b-1]*b)%mod;
            continue;
        }
        forn(tb,0,b+1) {
            d[a][b] += d[a-1][b-tb]*cfac[b][tb]%mod;
        }
        if(a>1) {
            forn(tb,0,b+1) {
                d[a][b] += (d[a-2][b-tb]*(a-1)*(tb+1))%mod*cfac[b][tb]%mod;
            }
        }
        d[a][b] %= mod;
        
    }
    int n;
    scanf("%d", &n);
    int a= 0;
    int b = 0;
    forn(i,0,n) {
        int x;
        read(x);
        if(x==1) a++;
        else b++;
    }
    cout<<d[a][b];
    
    
}