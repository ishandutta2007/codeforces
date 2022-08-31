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
const int A = 100000;
set<pi> t[4*A];

class stree {
public:
    void update (int v, int tl, int tr, int l, int r, pi add) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v].insert(add);
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
        }
    }
    
    void rem (int v, int tl, int tr, int l, int r, pi add) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v].erase(add);
        else {
            int tm = (tl + tr) / 2;
            rem (v*2, tl, tm, l, min(r,tm), add);
            rem (v*2+1, tm+1, tr, max(l,tm+1), r, add);
        }
    }
    
    pi getcf (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return *t[v].begin();
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return min(*t[v].begin(), getcf (v*2, tl, tm, pos));
        else
            return min(*t[v].begin(), getcf (v*2+1, tm+1, tr, pos));
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,4*A) t[i].insert(mp(0,1));
    int h,w,n;
    scanf("%d %d %d", &h, &w, &n);
    vi u(n), l(n), r(n), s(n);
    vpi ev;
    vpi evrem;
    forn(i,0,n) {
        scanf("%d %d %d %d", &u[i], &l[i], &r[i], &s[i]);
        l[i]--;
        r[i]--;
        ev.pb(mp(u[i], i));
        evrem.pb(mp(u[i] + s[i]+1, i));
    }
    vpi to(n);
    stree st;
    int ptrem = 0;
    sort(all(ev));
    sort(all(evrem));
    for(auto x : ev) {
        int curh = x.first;
        while(ptrem < evrem.size() && evrem[ptrem].first <= curh) {
            int ind = evrem[ptrem++].second;
            st.rem(1, 0, w-1, l[ind], r[ind], to[ind]);
        }
        int ind = x.second;
        int lc = l[ind] - 1;
        int rc = r[ind] + 1;
        if(rc >= w) rc = lc;
        if(lc <  0) lc = rc;
        int coef = (st.getcf(1, 0, w-1, lc).second + st.getcf(1, 0, w-1, rc).second)%mod;;
        to[ind] = mp(-curh, coef);
        st.update(1, 0, w-1, l[ind], r[ind], to[ind]);
    }
    int ans = 0;
    while(ptrem < evrem.size() && evrem[ptrem].first <= h+1) {
        int ind = evrem[ptrem++].second;
        st.rem(1, 0, w-1, l[ind], r[ind], to[ind]);
    }
    forn(i,0,w) ans = (ans+st.getcf(1, 0, w-1, i).second) % mod;
    cout<<ans;
    
}