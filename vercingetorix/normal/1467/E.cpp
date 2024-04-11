#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

class btree {
public:
    vi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
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
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  (
                 get (v*2, tl, tm, l, min(r,tm)) +
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  (t[v*2]+ t[v*2+1]);
        }
    }
};
class stree {
public:
    vi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += val;
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get (v*2, tl, tm, pos);
        else
            return t[v] + get (v*2+1, tm+1, tr, pos);
    }
};
const int A = 200500;
vi g[A];
int timer =0;
int tl[A];
int tr[A];
int par[A];
vi ch[A];
void dfs(int v, int p) {
    par[v] = p;
    tl[v] = timer++;
    for(auto u : g[v]) {
        if(u == p) continue;
        ch[v].pb(u);
        dfs(u, v);
    }
    tr[v] = timer - 1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    map<int, vi> val;
    forn(i,0,n) val[a[i]].pb(i);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    stree st;
    st.build(vi(n,0), 1, 0, n-1);
    btree bt;
    bt.build(vi(n,0), 1, 0, n-1);
    for(auto bv : val) {
        vi & pos = bv.second;
        int num = pos.size();
        for(auto i : pos) bt.update(1, 0, n-1, tl[i], 1);
        for(auto i : pos) {
            int down = bt.get(1, 0, n-1, tl[i], tr[i]);
            if(down != num) st.update(1, 0, n-1, tl[i], tr[i], 1);
            else {
                for(auto u : ch[i]) if(bt.get(1, 0, n-1, tl[u], tr[u]) != num-1) {
                    st.update(1, 0, n-1, tl[u], tr[u], 1);
                }
            }
            if(down != 1) {
                st.update(1, 0, n-1, 0, n-1, 1);
                st.update(1, 0, n-1, tl[i]+1, tr[i], -1);
            }
        }
        for(auto i : pos) bt.update(1, 0, n-1, tl[i], 0);
    }
    int ans = 0;
    forn(i,0,n) if(st.get(1, 0, n-1, tl[i]) == 0) ans++;
    cout<<ans;
    
    
}