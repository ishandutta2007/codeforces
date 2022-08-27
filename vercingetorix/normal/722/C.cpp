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

vll ch;

ll gs (int l, int r) {
    if(l>r) return 0;
    ll ret = ch[r];
    if(l>0) ret-=ch[l-1];
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi a(n), x(n);
    forn(i,0,n) scanf("%d\n", &a[i]);
    forn(i,0,n) scanf("%d\n", &x[i]);
    
    ll sum = 0;
    
    forn(i,0,n) {
        sum += (ll)a[i];
        ch.pb(sum);
    }
    set<int> del;
    forn(i,0,n) del.insert(i);
    forn(i,0,n) x[i]--;
    reverse(all(x));
    del.insert(-1);
    del.insert(n);
    vi br, bl;
    forn(i,0,n) {
        br.pb(i-1);
        bl.pb(i+1);
    }
    ll best = 0;
    vll ans;
    forn(i,0,n) {
        
        int m = x[i];
        del.erase(m);
        auto it = del.lower_bound(m);
        int r = (*it) - 1;
        it--;
        int l = (*it) + 1;
        ll cur = a[m];
        if(m>0) cur+=gs(bl[m-1], m-1);
        if(m<n-1) cur+=gs(m+1, br[m+1]);
        best=max(cur, best);
        ans.pb(best);
        if(gs(l,m) > gs(l, br[l])) br[l] = m;
        if(m<n-1) if(gs(l,br[m+1]) > gs(l, br[l])) br[l] = br[m+1];
        if(gs(m,r) > gs(bl[r], r)) bl[r] = m;
        if(m>0) if(gs(bl[m-1], r) > gs(bl[r], r)) bl[r] = bl[m-1];
        
    }
    ans.pop_back();
    reverse(all(ans));
    ans.pb(0);
    for(auto x:ans) printf("%lld\n", x);
    
    
    
}