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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k,s,t;
    scanf("%d %d %d %d", &n, &k, &s,&t);
    if(t < s) {
        cout<<-1;
        return 0;
    }
    vpi var(n);
    forn(i,0,n) {
        scanf("%d %d", &var[i].first, &var[i].second);
    }
    vi g(k);
    forn(i,0,k) {
        scanf("%d", &g[i]);
    }
    g.pb(0);
    g.pb(s);
    sort(all(g));
    vi d;
    forn(i,0,k+1) {
        d.pb(g[i+1] - g[i]);
    }
    sort(all(d));
    ll l = 0;
    ll r = 2000000000;
    while(r-l>1) {
        ll m = (r+l)/2;
        ll cur = 0;
        for(ll x : d) {
            if(x > m) cur = t+1;
            else {
                cur += 2*x - min(m-x, x);
            }
        }
        if( cur <= t) r = m;
        else l = m;
    }
    int ans = 1000000001;
    for(auto x : var) {
        if(x.second >= r) ans=min(x.first, ans);
    }
    if(ans == 1000000001) ans = -1;
    cout<<ans;
    
}