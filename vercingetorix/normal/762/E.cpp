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
vvi freq(10001);

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
    
    void set (int v, int tl, int tr, int pos, ll val) {
        if (pos == tl && tr == pos) {
            t[v] = val;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos,val);
            else set(v*2+1, tm+1, tr, pos,val);
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
    int n,k;
    scanf("%d %d", &n, &k);
    vi x(n), r(n), f(n);
    map<int,int> xmap;
    vi xord;
    forn(i,0,n) {
        scanf("%d %d %d", &x[i], &r[i], &f[i]);
        freq[f[i]].pb(i);
        xord.pb(x[i]);
    }
    sort(all(xord));
    vi lx(n);
    vi rx(n);
    forn(i,0,n) {
        rx[i] = (upper_bound(all(xord), x[i]+r[i]) - xord.begin()) - 1;
        lx[i] = (lower_bound(all(xord), x[i]-r[i]) - xord.begin());
    }
    forn(i,0,n) xmap[xord[i]] = i;
    vi indmap(n);
    forn(i,0,n) indmap[i] = xmap[x[i]];
    set<pi> proc;
    int cur = 0;
    for(auto u : freq[1]) proc.insert(mp(x[u], u));
    ll ans = 0;
    vll def(n,0);
    stree st;
    st.build(def, 1, 0, n-1);
    ll A = 1e6;
    while(1) {
        if(cur-k > 0) for(auto u : freq[cur-k]) proc.erase(mp(x[u], u));
        cur++;
        if(cur > 10000) break;
        for(auto u : freq[cur]) proc.insert(mp(x[u], u));
        if(freq[cur].empty()) continue;
        set<pi> rend;
        for(auto u : proc) {
            int curx = x[u.second];
            while(!rend.empty() && rend.begin()->first < curx) {
                st.set(1, 0, n-1, indmap[rend.begin()->second], 0);
                rend.erase(rend.begin());
            }
            if(f[u.second] == cur) {
                ans += st.get(1, 0, n-1, lx[u.second], indmap[u.second])%A;
                st.set(1, 0, n-1, indmap[u.second], A+1);
            }
            else {
                ans += st.get(1, 0, n-1, lx[u.second], indmap[u.second])/A;
                st.set(1, 0, n-1, indmap[u.second], 1);
            }
            
            rend.insert(mp(curx + r[u.second], u.second));
        }
        for(auto u : rend) {
            st.set(1, 0, n-1, indmap[u.second], 0);
        }
    }
    cout<<ans;
    
    
}