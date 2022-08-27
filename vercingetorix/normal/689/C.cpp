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
ll A;
vll cubes;
ll gc(ll x) {
    ll ans = 0;
    for(auto u : cubes) {
        if(u>x) break;
        ans+=x/u;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    for(ll x = 2; x<=200000; x++) {
        cubes.pb(x*x*x);
    }
    cin >> A;
    ll l = 1;
    ll r = 100000000ll*100000000ll;
    while(r-l > 1) {
        ll m =(r+l)/2;
        ll cnt = gc(m);
        if(cnt >= A) r = m;
        else l = m;
    }
    if(gc(r)==A) cout<<r;
    else cout<<-1;
}