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

const int A = 200000;
vector<pair<int, pi>> ev1[A];
vector<pair<int, pi>> ev2[A];

class stree {
public:
    vll t;
    int s;
    void build (vll & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    void set (int v, int tl, int tr, int pos) {
        if (pos == tl && tr == pos) {
            t[v] = 1;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos);
            else set(v*2+1, tm+1, tr, pos);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return get (v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    vi a(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    vll l(q), r(q), d(q), u(q);
    vll ans(q);
    ll tot = ((ll)n*(ll(n-1)))/2;
    forn(i,0,q) {
        ans[i] = tot;
        int li,ri,di,ui;
        scanf("%d %d %d %d", &li, &di, &ri, &ui);
        li--; di--; ri--; ui--;
        l[i] = li;
        r[i] = ri;
        d[i] = di;
        u[i] = ui;
        vll dec;
        dec.pb(li); dec.pb(di); dec.pb(n-1-ri); dec.pb(n-1-ui);
        for(auto x : dec) ans[i] -= (x*(x-1))/2;
        if(li > 0) {
            if(di>0) ev1[li-1].pb(mp(i, mp(0, di-1)));
            if(ui<n-1) ev1[li-1].pb(mp(i, mp(ui+1, n-1)));
        }
        if(ri < n-1) {
            if(di>0) ev2[ri].pb(mp(i, mp(0, di-1)));
            if(ui<n-1) ev2[ri].pb(mp(i, mp(ui+1, n-1)));
        }
    }
    vll def(n,0);
    stree st;
    st.build(def, 1, 0, n-1);
    forn(i,0,n) {
        st.set(1, 0, n-1, a[i]);
        for(auto u : ev1[i]) {
            ll cnt = st.get(1, 0, n-1, u.second.first, u.second.second);
            ans[u.first] += (cnt*(cnt-1))/2;
        }
        for(auto u : ev2[i]) {
            ll cnt = st.get(1, 0, n-1, u.second.first, u.second.second);
            cnt = u.second.second-u.second.first+1-cnt;
            ans[u.first] += (cnt*(cnt-1))/2;
        }
    }
    forn(i,0,q) printf("%lld\n", ans[i]);
    
}