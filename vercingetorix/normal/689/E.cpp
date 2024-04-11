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
    return (x+modulo*modulo)%modulo;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    
    int n,k;
    scanf("%d %d", &n, &k);
    vll cnk(n+1,0);
    cnk[k] = 1;
    for(ll i = k; i<n; i++) {
        cnk[i+1] = (((cnk[i] * (i+1)) % mod) * invmod((i-k+1), mod)) % mod;
    }
    vpi ev;
    forn(i,0,n) {
        int l,r;
        scanf("%d %d", &l, &r);
        ev.pb(mp(l, 1));
        ev.pb(mp(r+1,-1));
    }
    sort(all(ev));
    ll cnt = 0;
    ll ans = 0;
    int l = ev.size();
    for(int i = 0; i < l-1; i++) {
        cnt += ev[i].second;
        ll k = ev[i+1].first-ev[i].first;
        if(k==0) continue;
        ans = (ans + k * cnk[cnt]) % mod;
    }
    cout<<ans;
}