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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    vll bad;
    ll x,y,l,r;
    cin>>x>>y>>l>>r;
    bad.pb(l-1);
    bad.pb(r+1);
    vll dx(1,1);
    vll dy(1,1);
    while(1) {
        ll xb = dx.back();
        if(r/x < xb) break;
        dx.pb(xb*x);
    }
    while(1) {
        ll xb = dy.back();
        if(r/y < xb) break;
        dy.pb(xb*y);
    }
    for(auto ax : dx) for(auto ay : dy) {
        if(ax+ay >= l && ax+ay<=r) bad.pb(ax+ay);
    }
    sort(all(bad));
    ll ans = 0;
    forn(i,0,bad.size() - 1) ans = max(ans, bad[i+1]-bad[i]-1);
    cout<<ans;
    
}