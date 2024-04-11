#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int LIMIT = 1000000;
vi mindiv(LIMIT+1, 0);
vll p;
vpll factor(ll n) {
    vpll d;
    if(n<=LIMIT) {
        while(n > 1) {
            ll pr = mindiv[n];
            n/=pr;
            d.pb(mp(pr,1ll));
            while(n%pr == 0) {
                d.back().second++;
                n/=pr;
            }
        }
        return d;
    }
    
    for(auto pr : p) {
        if(n % pr == 0) {
            n/=pr;
            d.pb(mp(pr,1ll));
            while(n%pr == 0) {
                d.back().second++;
                n/=pr;
            }
        }
    }
    if(n>1) d.pb(mp(n,1));
    return d;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    vb isp(LIMIT+1, true);
    
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

    ll n, k;
    cin>>n>>k;
    k = (k+1)/2;
    vpll d = factor(n);
    while(k > 0) {
        vpll nd;
        for(auto x : d) {
            if(x.second > 1) {
                nd.pb(mp(x.first, x.second-1));
            }
            for(auto y : factor(x.first-1)) nd.pb(y);
            n/=x.first;
            n*=(x.first-1);
        }
        sort(all(nd));
        d.clear();
        forn(i,0,nd.size()) {
            if(i==0 || nd[i].first != nd[i-1].first) d.pb(nd[i]);
            else d.back().second += nd[i].second;
        }
        k--;
        if(n==1) break;
    }
    cout<<n%mod;
    
    
}