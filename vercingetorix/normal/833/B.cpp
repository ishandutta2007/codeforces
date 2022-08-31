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

const int INF = 1e9;
class streemax {
public:
    vi t, lazy;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            s = a.size();
            t.resize(4*s);
            lazy.resize(4*s);
        }
        if (tl == tr) {
            t[v] = a[tl];
            lazy[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            lazy[v] = 0;
            t[v] = max(t[v*2], t[v*2 + 1]);
        }
    }
    
    void push(int v) {
        if (lazy[v] == 0) return;
        t[v] += lazy[v];
        if(v<2*s) {
            lazy[v*2] += lazy[v];
            lazy[v*2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int add) {
        push(v);
        if (l > r)
            return;
        if (l == tl && tr == r) {
            lazy[v] += add;
            push(v);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            t[v] = max(t[v*2], t[v*2 + 1]);
        }
    }
    
    int gmax (int v, int tl, int tr, int l, int r) {
        push(v);
        if (l > r)
            return -INF;
        if (l == tl && tr == r) {
            return t[v];
        }
        else {
            int tm = (tl + tr) / 2;
            int ret = max(gmax(v*2, tl, tm, l, min(r,tm)),
                         gmax(v*2+1, tm+1, tr, max(l,tm+1), r));
            t[v] = max(t[v*2], t[v*2 + 1]);
            return ret;
        }
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
    vi a(n);
    vi last(n+1,-1);
    forn(i,0,n) scanf("%d", &a[i]);
    last[a[0]] = 0;
    vector<streemax> d(k+1);
    vi def(n,0);
    forn(i,1,k+1) d[i].build(def, 1, 0, n-1);
    d[1].update(1, 0, n-1, 0, 0, 1);
    forn(e,1,n) {
        int u = last[a[e]];
        for(int c = k; c>=1; c--) {
            d[c].update(1, 0, n-1, u+1, e-1, 1);
            if(c>1) d[c].update(1, 0, n-1, e, e, 1+d[c-1].gmax(1, 0, n-1, 0, e-1));
        }
        last[a[e]] = e;
    }
    int ans = 0;
    forn(c,1,k+1) ans = max(ans, d[c].gmax(1, 0, n-1, 0, n-1));
    cout<<ans;
    
}