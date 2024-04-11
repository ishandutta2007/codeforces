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
    ll n,s;
    scanf("%lld %lld", &n, &s);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    int l = 0;
    int r = n+1;
    ll ans = 0;
    while(r-l>1) {
        ll m = (r+l)/2;
        vll b;
        forn(i,0,n) b.pb(a[i] + m*(i+1));
        sort(all(b));
        ll cand = 0;
        forn(i,0,m) cand+=b[i];
        if(cand <= s) {
            l=m;
            ans = cand;
        }
        else r=m;
    }
    cout<<l<<' '<<ans;
    
    
}