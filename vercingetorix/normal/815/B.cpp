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

ll gop(vll & a, int n) {
    if(n==1) {
        return a[0];
    }
    ll curc = 1;
    ll ans = 0;
    ans = (ans + a[0] * curc) % mod;
    forn(i,1,n) {
        curc = (curc*(n-i)) % mod;
        curc = (curc * invmod(i, mod)) % mod;
        ans = (ans + a[i] * curc) % mod;
    }
    return ans;
}

ll go(vll & a, int n) {
    if(n==1) {
        return a[0];
    }
    int cop = 1;
    if(n % 2 == 1) {
        forn(i,0,n-1) {
            a[i] = (a[i]+mod+cop*a[i+1])%mod;
            cop = -cop;
        }
        n--;
        a.pop_back();
        return go(a, n);
    }
    ll totop = (n*(n-1))/2;
    vll b;
    int sgn = 1;
    if(totop % 2 == 0) sgn = -1;
    for(int i = 0; i < n; i+=2) {
        b.pb((a[i]+mod+a[i+1]*sgn) % mod);
    }
    return gop(b,n/2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vll a(n);
    forn(i,0,n) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    
    cout<<go(a,n);
    
}