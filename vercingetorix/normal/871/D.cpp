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
    vi sqfree(LIMIT+1, 1);
    vi pcnt(LIMIT+1, 0);
    forn(i,2,LIMIT+1) {
        int k = i/mindiv[i];
        if(mindiv[k] == mindiv[i] || sqfree[k] == 0) sqfree[i] = 0;
        pcnt[i] = pcnt[k]+1;
    }
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    mindiv[1] = 1;
    vll cmin(LIMIT+1,0);
    ll n;
    cin>>n;
    forn(i,2,n+1) cmin[mindiv[i]] ++;
    ll ans = ((n*(n-1))/2)*3;
    ll totp = ans;
    ll badnum = 1;
    for(auto x : p) if(x <= n && 2*x > n) badnum++;
    ll badp = badnum*n - (badnum*(badnum+1))/2;
    ans -= 3*badp;
    ll group2 = 0;
    for(auto x : p) if(x <= n) group2 += (cmin[x]*(cmin[x]-1))/2;
    forn(i,2,n+1) if(pcnt[i] == 2 && sqfree[i] == 1) {
        int p1 = i / mindiv[i];
        int p2 = mindiv[i];
        group2 += cmin[p1]*cmin[p2];
    }
    ans -= group2;
    ll hd = 0;
    forn(i,2,n+1) {
        if(sqfree[i]) {
            ll num = n/i;
            ll nump = (num*(num-1))/2;
//            printf("Pairs div %d: %d\n", i, nump);
            if(pcnt[i]%2) hd+=nump;
            else hd-=nump;
//            printf("new hd %d\n", hd);
        }
    }
    ans -= hd;
//    printf("Total pairs: %d\n Bad pairs: %d\n pq pairs: %d\n Have gcd pairs: %d\n", totp/3, badp, group2, hd);
    cout<<ans;
    

}