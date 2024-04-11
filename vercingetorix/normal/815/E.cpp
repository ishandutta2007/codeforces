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

ll go(ll n, ll k) {
    ll mid = (n+1)/2;
    if(k==1) return (n+1)/2;
    if(n==2 && k==2) return 2;
//    ll kleft = k-1;
    k--;
    ll mn = (n-1)/2;
    ll whatr = n-1 - (n-1)/2;
    ll mx = mn + 1;
    ll cmnl = 1;
    ll cmxl = 0;
    ll cmnr = 0;
    ll cmxr = 0;
    if(whatr == mn) cmnr++;
    else cmxr++;
    ll didl = 0;
    ll didr = 0;
    while(1) {
        if(mn > 2) {
            if(mn%2 == 0) {
                if (k <= cmxl) return go((n-1)/2, didl + k);
                else if(k <= cmxl + cmxr) return (n+1)/2+go(whatr, didr + k - cmxl);
                else if(k <= cmxl + cmxr + cmnl) return go((n-1)/2, didl + k - cmxr);
                else if(k <= cmxl + cmxr + cmnl + cmnr) return (n+1)/2+go(whatr, didl + k - cmnl - cmxl);
                else {
                    k -= cmxl + cmxr + cmnl + cmnr;
//                    ll nmn = mn/2 - 1;
                    didl += cmnl + cmxl;
                    didr += cmnr + cmxr;
                    cmxl = 2*cmxl + cmnl;
                    cmxr = 2*cmxr + cmnr;
                    mn = mn/2-1;
                    mx = mn+1;
                }
            }
            else {
                if(k <= cmnl + cmxl) return go((n-1)/2, didl + k);
                else if(k <= cmxl + cmxr + cmnl + cmnr) return (n+1)/2+go(whatr, didl + k - cmnl - cmxl);
                else {
                    k -= cmxl + cmxr + cmnl + cmnr;
                    didl += cmnl + cmxl;
                    didr += cmnr + cmxr;
                    cmnl = 2*cmnl + cmxl;
                    cmnr = 2*cmnr + cmxr;
                    mn = mn/2;
                    mx = mn+1;
                }
            }
        }
        else if(mn == 2) {
            if(k <= cmxl) return go((n-1)/2, didl + k);
            else if(k <= cmxl + cmxr) return (n+1)/2+go(whatr, didr + k - cmxl);
            else {
                k -= cmxl + cmxr;
                didl += cmxl;
                didr += cmxr;
                swap(cmxl, cmnl);
                cmnl *= 2;
                swap(cmxr, cmnr);
                cmnr *= 2;
                mn = 1;
                mx = 2;
            }
        }
        else if(mn == 1) {
            if(k <= cmnl + 2*cmxl) return go((n-1)/2, didl + k);
            else return (n+1)/2+go(whatr, didr + k - cmnl - 2*cmxl);
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,k;
    cin>>n>>k;
    if(k==1) cout<<1;
    else if(k==2) cout<<n;
    else cout<<1+go(n-2,k-2);
//    cout<<go(n,k);
//    forn(k,1,n+1) cout<<go(n,k)<<endl;
}