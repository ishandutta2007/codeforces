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

pll ccount(ll cl, ll cr, bool forcel) {
    if(forcel) {
        if(cl <= cr) {
            cr--;
        }
        if(cr == 0) return mp(1,1);
        else return mp(2, cr);
    }
    if(cl+cr==0) return mp(0,1);
    if(cl == 0 || cr == 0)  {
        return mp(1, cl+cr);
    }
    if(cl+cr==2) {
        return mp(1, 2);
    }
    ll ways = (cl*cr-min(cl,cr));
    return mp(2,ways);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vll imod(1,0);
    forn(i,1,10000) imod.pb(invmod(i, mod));
    int n,m;
    scanf("%d %d", &n, &m);
    vi s(n+2);
    forn(i,1,n+1) scanf("%d", &s[i]);
    s[0] = 0;
    s[n+1] = n+1;
    vvi cnum(n+2,vi(n+1,0));
    forn(i,0,m) {
        int f,h;
        scanf("%d %d", &f, &h);
        cnum[f][h] = 1;
    }
    cnum[0][1] = 1;
    cnum[n+1][1] = 1;
    forn(i,0,n+2) forn(j,0,n) cnum[i][j+1] += cnum[i][j];
    vi gr(n+1, 0);
    forn(i,1,n+1) gr[s[i]]++;
    vi cl(n+1,0);
    vi cr(n+1,0);
//    vvi cntl(n+2, vi(n+2,0));
//    vvi cntr(n+2, vi(n+2,0));
    vi grass(n+2,0);
//    forn(i,0,n+2) {
//        grass[s[i]]++;
//        forn(j,0,n+2) cntl[i][j] = cnum[j][grass[j]];
//    }
    forn(i,0,n+2) grass[i] = 0;
//    for(int i = n+1; i>=0; i--) {
//        grass[s[i]]++;
//        forn(j,0,n+2) cntr[i][j] = cnum[j][grass[j]];
//    }
    vi grl(n+2,0);
    vi grr(n+2,0);
    grl[s[0]]++;
    forn(i,1,n+2) grr[s[i]]++;
    ll cur = 1;
    int cows = 0;
    forn(i,0,n+2) {
        pll res = ccount(cnum[i][grl[i]], cnum[i][grr[i]], false);
        cows += res.first;
        cur = cur*res.second%mod;
    }
    ll ans = cur;
    int ansk = cows;
    
    
    forn(fl,1,n+1) {
        int col = s[fl];
//        pll was = ccount(cntl[fl-1][col], cntr[fl][col], false);
        pll was = ccount(cnum[col][grl[col]], cnum[col][grr[col]], false);
//        pll to = ccount(cntl[fl][col], cntr[fl+1][col], false);
        grl[col]++;
        grr[col]--;
        pll to = ccount(cnum[col][grl[col]], cnum[col][grr[col]], false);
        cows -= was.first;
        cur = cur*invmod(was.second, mod)%mod;
        if(cnum[col][grl[col]] > cnum[col][grl[col]-1]) {
            pll toy = ccount(cnum[col][grl[col]], cnum[col][grr[col]], true);
            if(ansk < cows+toy.first) {
                ansk =cows+toy.first;
                ans= cur*toy.second%mod;
            }
            else if(ansk == cows+toy.first) {
                ans= (ans+cur*toy.second)%mod;
            }
        }
        
        cur = cur*to.second%mod;
        cows +=to.first;
    }
    cout<<ansk-2<<' '<<ans;
    
}