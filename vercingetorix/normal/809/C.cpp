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

pll req(ll x, ll y, ll k) {
//    cout<<x<<' '<<y<<' '<<k<<endl;
    if(k<1) return mp(0,0);
    if(x == 0 || y == 0) return mp(0,0);
    if(x == 1 && y == 1) {
        if(k >= 1) return mp(1,1);
        else return mp(0,0);
    }
    ll deg = 0;
    ll d2 = 1;
    while(max(x,y) > d2) {
        deg++;
        d2*=2;
    }
    ll a = d2/2;
    if(x>y) swap(x,y);
    if(x<=a) {
        ll m = min(a,k);
        ll sm = ((m*(m+1))/2) % mod;
        pll res = mp(x*m, x*sm);
        pll res2 = req(x, y-a, k-a);
        res2.second += res2.first*a;
        res.first += res2.first;
        res.second = (res.second + res2.second)%mod;
        res.first = res.first%mod;
        return res;
    }
    ll m = min(a,k);
    ll sm = ((m*(m+1))/2) % mod;
    pll res = mp(a*m, a*sm);
    ll m2 = min(a, k-a);
    if(m2<0) m2=0;
    ll sm2 = (a*m2+(m2*(m2+1))/2) % mod;
    res.first += (x+y-2*a)*m2;
    res.second += (x+y-2*a)*sm2;
    pll res2 = req(x-a, y-a, k);
    res.first += res2.first;
    res.first = res.first % mod;
    res.second = (res.second + res2.second)%mod;
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    scanf("%d", &q);
    forn(i,0,q) {
        int x1,y1,x2,y2,k;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        printf("%lld\n", (req(x2,y2,k).second - req(x1-1,y2,k).second - req(x2,y1-1,k).second + req(x1-1,y1-1,k).second + 10*mod)%mod);
    }
    
    
}