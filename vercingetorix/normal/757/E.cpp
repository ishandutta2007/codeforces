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
#include <random>
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
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

ll inv[100];

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


long long cnk(ll n, ll k) {
    ll ans = 1;
    for(int i =0; i < k; i++) {
        ans = (ans*(n-i))%mod;
        ans = (ans*inv[i+1])%mod;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,1,100) {
        inv[i] =invmod(i,mod);
    }
    
    const int LIMIT = 1000100;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vi p;
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    int q;
    scanf("%d", &q);
    forn(i,0,q) {
        int r,n;
        scanf("%d %d", &r, &n);
        ll ans = 1;
        while(n>1) {
            int d=  mindiv[n];
            int t = 0;
            while(n%d==0) {
                n/=d;
                t++;
            }
            ll cand  = cnk(t+r,t)+cnk(t+r-1,t-1);
            ans = (ans*cand)%mod;
        }
        printf("%lld\n", ans);
    }
    
}