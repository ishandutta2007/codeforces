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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vpll y;
const ll INF = 1e9;

ll go(ll a, ll ato, ll b, ll bto) {
    if(a >= ato && b>=bto) return 0;
    if(y.empty()) return INF;
    pll yb = y.back();
    ll d = yb.first;
    ll cnt = yb.second;
    ll ca = a;
    ll cb = b;
    ll nda = 0;
    ll ndb = 0;
    while(ca < ato) {
        nda++;
        ca *= d;
    }
    while(cb < bto) {
        ndb++;
        cb *= d;
    }
    if(nda + ndb <= cnt) return nda + ndb;
    int c1 = 0;
    int c2 = 0;
    ca = a;
    cb = b;
    forn(i,0,min(nda, cnt)) {
        ca *= d;
        c1 ++;
    }
    forn(i,0,cnt-c1) {
        cb *= d;
    }
    c2 = cnt - c1;
    ll ans = INF;
    y.pop_back();
    ans = min(ans, cnt + go(ca, ato, cb, bto));
    while(1) {
        ca/=d;
        c1--;
        cb*=d;
        c2++;
        ans = min(ans, cnt + go(ca, ato, cb, bto));
        if(c1==0 || c2 == ndb) break;
    }
    y.pb(yb);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll a,b,h,w,n;
    cin>>a>>b>>h>>w>>n;
    vll x;
    forn(i,0,n) {
        int u;
        scanf("%d", &u);
        x.pb(u);
    }
    sort(all(x));
    ll last = 0;
    for(auto u : x) {
        if(u==last) {
            y.back().second++;
        }
        else {
            y.pb(mp(u,1));
            last = u;
        }
    }
    ll ans = min(go(h,a,w,b), go(h,b,w,a));
    if(ans == INF) ans = -1;
    cout<<ans;
    
}