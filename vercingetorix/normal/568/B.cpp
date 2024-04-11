#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
ll powM(ll k, ll n, ll modulo) {
    if (n==0) return 1;
    if(n==1) return k;
    ll x = powM(k, n/2,modulo);
    return (((x*x)%modulo)*powM(k, n%2,modulo)) % modulo;
}
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
    return (x+modulo*modulo)%modulo;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n;
    ll ans=0;
    cin>>n;
    vector<vll> cnk(n+1, vll(n+1,0));
    forn(i,0,n+1) cnk[i][0] = 1;
    forn(i,1,n+1) forn(j,1,n+1) cnk[i][j] = (cnk[i-1][j-1] + cnk[i-1][j]) % mod;
    vll r(n+1,0), rkill(n+1,0);
    r[1] = 2;
    rkill[1] = 1;
    rkill[0]=1;
    forn(i, 1, n) {
        // calc B_{i+1}
        forn(k,0,i+1) r[i+1] += (r[k]*cnk[i][k]) % mod;
        r[i+1] += r[i];
        forn(k,0,i+1) rkill[i+1] += (rkill[k]*cnk[i][k]) % mod;
        rkill[i+1]=rkill[i+1]%mod;
        r[i+1]=r[i+1]%mod;
    }
   
//    vll deg2c(n+1,0);
//    forn(i,0,n+1) deg2c[i] = powM(2, i*(i+1)/2, mod);
//    vll cn(n+1,0);
//    cn[0]=1;
//    forn(i,0,n) {
//        cn[i+1] = (cn[i] * (n-i))%mod;
//        cn[i+1] = (cn[i+1]*invmod(i+1, mod)) % mod;
//    }
    forn(i,1,n+1) {
        ans = (ans + cnk[n][i]*rkill[n-i]) % mod;
    }
    cout<<ans;
}