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

const int mod = 31607;
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
int d2[25];
int sm[4000000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vvi a(n, vi(n));
    vector<vd> ad(n, vd(n));
    d2[0] = 1;
    forn(i,1,25) d2[i] = d2[i-1] * 2;
    forn(i,0,n) forn(j,0,n) scanf("%d", &a[i][j]);
    forn(i,0,n) forn(j,0,n) ad[i][j] = double(a[i][j])/10000;
    int i10000 = invmod(10000, mod);
    forn(i,0,n) forn(j,0,n) a[i][j] = a[i][j]*i10000%mod;
    int totp = 1;
    vi mgood(d2[n+2], 1);
    int ans = 0;
    forn(i,0,n) {
        int pall = 1;
        forn(j,0,n) pall = pall*a[i][j] % mod;
        ans = (ans+totp*pall)%mod;
        int pnall = (mod + 1 - pall) % mod;
        sm[0] = 1;
        forn(mask,1,d2[n]) {
            int bit = 0;
            while((mask&d2[bit])==0) bit++;
            sm[mask] = sm[mask^d2[bit]]*a[i][bit] % mod;
        }
        forn(mask,0,d2[n]) {
            sm[mask] = (sm[mask] + mod - sm[d2[n] -1])%mod;
        }
        forn(mask,0,d2[n+2]) {
            int pgood = 1;
            int supmask = mask & (d2[n] - 1);
            if(mask&d2[n]) supmask |= d2[i];
            if(mask&d2[n+1]) supmask |= d2[n-1-i];
//            forn(bit,0,n) if(mask&d2[bit]) pgood = pgood * a[i][bit] % mod;
//            if(mask&d2[n]) if((mask&d2[i])==0) pgood = pgood * a[i][i] % mod;
//            if(mask&d2[n+1]) if((mask&d2[n-1-i])==0) {
//                if(i!=n-1-i || (mask&d2[n])==0) pgood = pgood * a[i][n-1-i] % mod;
//            }
//            pgood = (pgood + mod - pall) % mod;
//            mgood[mask] = mgood[mask] * pgood % mod;
            mgood[mask] = mgood[mask] * sm[supmask] % mod;
        }
    }
    
//    vd mg(d2[n+2], 1);
//    forn(i,0,n) {
//        double pall = 1;
//        forn(j,0,n) pall = pall*ad[i][j];
//        forn(mask,0,d2[n+2]) {
//            double pgood = 1;
//            forn(bit,0,n) if(mask&d2[bit]) pgood = pgood * ad[i][bit];
//            if(mask&d2[n]) if((mask&d2[i])==0) pgood = pgood * ad[i][i];
//            if(mask&d2[n+1]) if((mask&d2[n-1-i])==0) pgood = pgood * ad[i][n-1-i];
//            pgood -= pall;
//            if(pgood<-0.000001) {
//                cout<<1;
//            }
//            mg[mask] = mg[mask] * pgood;
//        }
//    }
    forn(mask,1,d2[n+2]) {
        int bnum = 0;
        forn(j,0,n+2) if(mask&d2[j]) bnum ++;
        if(bnum%2==0) mgood[0] = (mgood[0] + mgood[mask])%mod;
        else mgood[0] = (mgood[0] + mod - mgood[mask])%mod;
    }
    cout<<(mod+1-mgood[0]) %mod;
    
    
}