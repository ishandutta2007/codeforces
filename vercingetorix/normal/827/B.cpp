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
    int n,k;
    cin>>n>>k;
    int cur = k;
    vpi ans;
    int len = 0;
    while(cur + k < n) {
        len+=2;
        forn(i,0,k) ans.pb(mp(cur-i, cur+k-i));
        cur+=k;
    }
    if(n-cur == 1) {
        forn(i,0,k) ans.pb(mp(cur-i, n));
        len += 2;
    }
    else if(n-cur == 2){
        forn(i,1,k) ans.pb(mp(cur-i, n-1));
        ans.pb(mp(cur, n));
        ans.pb(mp(n-1,n));
        len+=3;
    }
    else {
        len+=4;
        forn(i,0,k) ans.pb(mp(n,n-k+i));
        forn(i,0,n-cur-1) ans.pb(mp(cur-k+1+i, cur+1+i));
    }
    printf("%d\n", len);
    for(auto x : ans) printf("%d %d\n", x.first, x.second);
//    if(n-k == 1) {
//        printf("%d\n", k);
//        forn(i,1,n) printf("%d %d\n", i, n);
//        return 0;
//    }
//    else {
//        vpi ans;
//        int m = n - k - 2;
//        forn(i,0,m) ans.pb(mp(1+i, m+1));
//        forn(i,0,k) ans.pb(mp(m+3+i, m+1));
//        ans.pb(mp(m+1,m+2));
//        forn(i,0,m/2) {
//            ans.pb(mp(1+2*i, 1+2*i));
//        }
//        if(m%2) ans.pb(mp(m, m+2));
//        printf("%d\n", ans.size());
//        for(auto x : ans) printf("%d %d\n", x.first, x.second);
//    }
}