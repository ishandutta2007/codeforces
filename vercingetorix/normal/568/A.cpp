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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 10000000;
    vb isp(LIMIT+1, true);
    isp[1]=false;
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
    ll P,Q;
    cin>>P>>Q;
    ll primes = 0;
    ll pal = 0;
    ll ans = 0;
    for(int i = 1; i<=10000000; i++) {
        if(isp[i]) primes++;
        if(i<10) pal++;
        else if(i<100) {if(i%10==i/10) pal++;}
        else if(i<1000) {if(i%10==i/100) pal++;}
        else if(i<10000) {if(i%10==i/1000) if((i%100)/10 == (i%1000)/100) pal++;}
        else if(i<100000) {if(i%10==i/10000) if((i%100)/10 == (i%10000)/1000) pal++;}
        else if(i<1000000) {if(i%10==i/100000) if((i%100)/10 == (i%100000)/10000) if((i%1000)/100 == (i%10000)/1000) pal++;}
        else if(i<10000000) {if(i%10==i/1000000) if((i%100)/10 == (i%1000000)/100000) if((i%1000)/100 == (i%100000)/10000) pal++;}
        if(primes*Q <= P*pal) ans = i;
    }
   
    cout<<ans;
}