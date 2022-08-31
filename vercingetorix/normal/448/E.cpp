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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
ll pow2(ll k, int n) {
    if (n==0) return 1;
    if(n==1) return k;
    int x = pow2(k, n/2);
    return x*x*pow2(k, n%2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 10000000;
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
    
    map<ll,vll> divs;
    ll X,k;
    cin>>X>>k;
    if(X==1) {printf("1"); return 0;}
    vll d;
    forn(i,1,1000001) {
        if(X%i == 0) {
            d.pb(i);
            if(X/i > 1000000) d.pb(X/i);
        }
    }
    sort(all(d));
    
    for(auto x : d) {
        for(auto y : d) {
            if(x%y == 0) divs[x].pb(y);
        }
    }
    
    if(k>100000) {
        if(X==1) printf("1");
        else {
            forn(i,0,100000) {
                printf("1 ");
            }
        }
        return 0;
    }
    
    vpll num;
    ll totsize = 1;
    num.pb(mp(X,0));
    forn(i,0,k) {
        ll add = 0;
        vpll num2;
        for(auto x: num) {
            if(add + x.second > 100000) break;
            vll & divx = divs[x.first];
            for(int k = 1; k< min((ll)divx.size(), 100000-x.second-add); k++) {
                num2.pb(mp(divx[k], x.second + k + add));
            }
            add+=divx.size() - 1;
            totsize += divx.size() - 1;
        }
        num.clear();
        num = move(num2);
        num2.clear();
    }
    vll ans(100000,1);
    for(auto x: num) {
        if(x.second<100000) ans[x.second] = x.first;
    }
    forn(i,0,min((ll)100000,totsize)) printf("%lld ", ans[i]);
}