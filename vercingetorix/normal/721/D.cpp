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
    int n,k;
    ll x;
    int xx;
    scanf("%d %d %d", &n,&k,&xx);
    x=xx;
    vll a(n);
    int cneg = 0;
    int c0 = 0;
    int cpos = 0;
    ll minpos = 1e9 + 100000;
    ll maxneg = -minpos;
    forn(i,0,n) {
        scanf("%lld", &a[i]);
        if(a[i] == 0) c0++;
        else if(a[i] <0) {
            cneg++;
            maxneg=max(maxneg, a[i]);
        }
        else if(a[i]>0) {
            cpos++;
            minpos =min(minpos, a[i]);
        }
    }
    if(c0 > k) {
        forn(i,0,n) printf("%lld ", a[i]);
        return 0;
    }
    if(c0 == 0 && (cneg%2)==0 && minpos >= x*(ll)k && -maxneg >= x*(ll)k) {
        
        int ind = 0;
        forn(i,1,n) if(abs(a[i]) < abs(a[ind])) ind = i;
        if(a[ind] < 0) a[ind] += x*(ll)k;
        else a[ind] -= x*(ll)k;
        forn(i,0,n) printf("%lld ", a[i]);
        return 0;
    }
    bool used = false;
    
    forn(i,0,n) {
        if(a[i] == 0) {
            if(!used) {
                used = true;
                if(cneg%2==0) {
                    a[i] = -x;
                    cneg++;
                }
                else a[i] = x;
            }
            else a[i] = x;
        }
    }
    k-=c0;
    if(cneg %2 == 0) {
        int ind = 0;
        forn(i,1,n) if(abs(a[i]) < abs(a[ind])) ind = i;
        int k1 = abs(a[ind])/x + 1;
        if(a[ind] > 0) a[ind] -= x*ll(k1);
        else a[ind] += x* (ll)k1;
        k-=k1;
    }
    set<pll> dec;
    forn(i,0,n) dec.insert(mp(abs(a[i]), i));
    forn(i,0,k) {
        auto it = dec.begin();
        int v = it->second;
        dec.erase(it);
        if(a[v] < 0) a[v] -= x;
        else a[v] += x;
        dec.insert(mp(abs(a[v]),v));
    }
    forn(i,0,n) printf("%lld ", a[i]);
    return 0;
}