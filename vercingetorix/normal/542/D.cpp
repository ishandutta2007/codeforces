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
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;

typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
typedef vector<vector<pll>> vvpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vi p;
const int LIMIT = 1000000;
vb isp(LIMIT+1, true);
vi mindiv(LIMIT+1, 0);

ll valid(ll x) {
    if (x == 1) return 0;
    if (x == 2) return 0;
    ll x1 = x-1;
    for(auto u : p) {
        ll v = u;
        if(v*v > x1) break;
        if(x1 %v == 0) {
            while(x1%v == 0) {
                x1/=v;
            }
            if (x1 == 1) return v;
            else return 0;
        }
    }
    return x1;
}

map <ll, int> delnum;
vvpll dels;
vll used;
int ans = 0;
vpll norm;

void go(ll num, ll m) {
    if(num == 1) {
        ans++;
        return;
    }
    int ind = delnum[num];
    auto pt = lower_bound(all(dels[ind]), mp(m,(ll)0));
    while (pt != dels[ind].end()) {
        bool f= false;
        for(auto was : used) {
            if(was == pt->second) {
                f=true;
                break;
            }
        }
        if(f) {
            pt++;
            continue;
        }
        else {
            used.pb(pt->second);
            go(num/pt->first, pt->first);
            used.pop_back();
        }
        pt++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);

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
    
    ll n;
    cin>>n;
    vll d;
    if(n==1) {
        cout<<1;
        return 0;
    }
    for(ll i = 1; i<1000001; i++) {
        if(i*i == n) {
            d.pb(i);
        }
        if(i*i >= n) break;
        if (n%i == 0) {
            d.pb(i);
            d.pb(n/i);
        }
    }
    sort(all(d));
    vi pol(d.size(), 0);

    for(int i=0; i<d.size(); i++) {
        ll v= d[i];
        ll x = valid(v);
        if(x>0) norm.pb(mp(v,x));
        if(x>0) pol[i] = 1;
    }
    
    dels.resize(d.size());
    forn(i,0,d.size()) {
        delnum[d[i]] = i;
        forn(j,0,norm.size()) {
            if(norm[j].first > d[i]) break;
            if(d[i]%norm[j].first == 0) dels[i].pb(norm[j]);
        }
    }
    
    go(n, 2);
    cout<<ans;
}