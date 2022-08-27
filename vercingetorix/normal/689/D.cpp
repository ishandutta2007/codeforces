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
#include <stack>
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
    int n;
    scanf("%d", &n);
    vi a(n);
    vi b(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) scanf("%d", &b[i]);
    int l = 0;
    deque<pi> am;
    deque<pi> bm;
    int m = 0;
    am.pb(mp(a[0],0));
    bm.pb(mp(b[0],0));
    ll ans = 0;
    forn(l,0,n) {
        if(m<=l) {
            while(!am.empty() && am.back().first < a[l]) am.pop_back();
            while(!bm.empty() && bm.back().first > b[l]) bm.pop_back();
            am.push_back(mp(a[l], l));
            bm.push_back(mp(b[l], l));
            m = l+1;
        }
        while(!am.empty() && am.front().second < l) am.pop_front();
        while(!bm.empty() && bm.front().second < l) bm.pop_front();
        while(m < n && max(am.front().first, a[m]) <= min(bm.front().first, b[m])) {
            while(!am.empty() && am.back().first < a[m]) am.pop_back();
            while(!bm.empty() && bm.back().first > b[m]) bm.pop_back();
            am.push_back(mp(a[m], m));
            bm.push_back(mp(b[m], m));
            m++;
        }
        if(am.front().first == bm.front().first) {
            int r = max(am.front().second, bm.front().second);
            ans += ll(m-r);
        }
    }
    cout<<ans;
    
}