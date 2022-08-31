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
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

ll powM(ll k, ll n, ll modulo) {
    if (n==0) return 1;
    if(n==1) return k;
    ll x = powM(k, n/2, modulo);
    return (((x*x)%modulo)*powM(k, n%2, modulo)) % modulo;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 2000000;
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
    vi sgn(LIMIT+1, 1);
    forn(i,2,LIMIT+1) {
        int was = i/mindiv[i];
        if(sgn[was] == 0 || mindiv[was] == mindiv[i]) sgn[i] = 0;
        else sgn[i] = -sgn[was];
    }
    vvi sqfd(LIMIT+1);
    sqfd[1].pb(1);
    forn(m,2,LIMIT+1) {
        int was = m / mindiv[m];
        sqfd[m] = sqfd[was];
        if(mindiv[was] != mindiv[m]) {
            for(auto x : sqfd[was]) sqfd[m].pb(x*mindiv[m]);
        }
    }
    int n,k;
    cin>>n>>k;
    
    vll dn(k+1,0);
    forn(i,1,k+1) dn[i] = powM(i, n, mod);
    vll ans(k+1);
    ans[1] = 1;
    vll cnt(k+1, 0);
    cnt[1] = 1;
    forn(i,2,k+1) {
        ans[i] = ans[i-1];
        for(auto d : sqfd[i]) {
            int l = i/d;
            cnt[d] = (cnt[d] + dn[l] - dn[l-1] + mod) % mod;
            ans[i] = (ans[i] + sgn[d]*(dn[l] - dn[l-1]) + mod) % mod;
        }
    }
    ll res = 0;
    forn(i,1,k+1) res = (res+(ans[i]^i))%mod;
    cout<<res;
    
    
    
    
}