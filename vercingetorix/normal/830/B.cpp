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

class stree {
public:
    vi t;
    int s;
    void build (vi & a, int v, int tl, int tr) {
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
            t[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos);
            else set(v*2+1, tm+1, tr, pos);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
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
    int n;
    scanf("%d", &n);
    vi def(n,1);
    stree st;
    st.build(def, 1, 0, n-1);
    map<int, vi> m;
    forn(i,0,n) {
        int x;
        scanf("%d", &x);
        m[x].pb(i);
    }
    ll ans = 0;
    int nx = 0;
    for(auto vx : m) {
        auto it = lower_bound(all(vx.second), nx);
        if (it == vx.second.end()) it = vx.second.begin();
        int ind = it-vx.second.begin();
        int k = vx.second.size();
        ind = (ind+k-1)%k;
        int npos = vx.second[ind];
        if(npos >= nx) ans += st.get(1, 0, n-1, nx, npos);
        else ans += st.get(1, 0, n-1, 0, npos) + st.get(1, 0, n-1, nx, n-1);
        for(auto y : vx.second) st.set(1, 0, n-1, y);
        nx = npos;
    }
    cout<<ans;
    
}