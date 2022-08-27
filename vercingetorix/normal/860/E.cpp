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
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

class stree {
public:
    vll t;
    vll lazy;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            s = n;
            t.resize(4*s);
            lazy.resize(4*s);
        }
        if (tl == tr) {
            t[v] = 0;
            lazy[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            lazy[v] = 0;
            t[v] = t[v*2] + t[v*2 + 1];
        }
    }
    
    void push(int v, int tl, int tr) {
        if (lazy[v] == 0) return;
        t[v] += lazy[v]*(tr-tl+1);
        if(v<2*s) {
            lazy[v*2] += lazy[v];
            lazy[v*2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int add) {
        push(v, tl, tr);
        if (l > r)
            return;
        if (l == tl && tr == r) {
            lazy[v] += add;
            push(v, tl, tr);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            t[v] = t[v*2] + t[v*2 + 1];
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r)
            return 0;
        if (l == tl && tr == r) {
            return t[v];
        }
        else {
            int tm = (tl + tr) / 2;
            ll ret = get(v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
            t[v] = t[v*2] + t[v*2 + 1];
            return ret;
        }
    }
};
vi par;
vvi ch;
vi s;
vi heavy;
vi hpar;
void dfsst(int v) {
    s[v] = 1;
    for(auto u : ch[v]) {
        dfsst(u);
        s[v] += s[u];
    }
}
void dfsh(int v) {
    for(auto u : ch[v]) {
        if(heavy[u]) hpar[u] = hpar[v];
        else hpar[u] = u;
        dfsh(u);
    }
}
vi vis;
int cnt = 0;
vector<stree> st;
vi num, pos;
void dfsbuild(int v) {
    for(auto u : ch[v]) dfsbuild(u);
    if(!vis[v]) {
        vi lol;
        int cur = v;
        while(cur != hpar[v]) {
            vis[cur] = 1;
            lol.pb(cur);
            cur = par[cur];
        }
        lol.pb(cur);
        vis[cur] = 1;
//        if(v == hpar[v]) {
//            vis[v] = 1;
//            lol.pb(v);
//        }
        reverse(all(lol));
        st.emplace_back();
        int k =lol.size();
        st.back().build(k, 1, 0, k-1);
        forn(i,0,lol.size()) {
            num[lol[i]] = cnt;
            pos[lol[i]] = i;
        }
        cnt++;
    }
}

void upd(int v, ll k) {
    while(v != -1) {
        st[num[v]].update(1, 0, st[num[v]].s-1, 0, pos[v], k);
        v = par[hpar[v]];
    }
}

ll get(int v) {
    ll ret = 0;
    while(v != -1) {
        ret += st[num[v]].get(1, 0, st[num[v]].s-1, 0, pos[v]);
        v = par[hpar[v]];
    }
    return ret;
}

vvi lvl;

void go(int v, int l) {
    lvl[l].pb(v);
    for(auto u : ch[v]) go(u, l+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    lvl.resize(n+1);
    ch.resize(n);
    heavy.resize(n);
    s.resize(n);
    par.resize(n);
    pos.resize(n);
    num.resize(n);
    hpar.resize(n);
    vis = vi(n,0);
    forn(i,0,n) scanf("%d", &par[i]);
    int root = -1;
    forn(i,0,n) {
        par[i] --;
        if(par[i] == -1) root = i;
        else ch[par[i]].pb(i);
    }
    dfsst(root);
    forn(i,0,n) {
        if(i!=root) {
            if(s[par[i]] <= 2*s[i]) heavy[i] = 1;
        }
    }
    hpar[root] = root;
    dfsh(root);
    go(root, 1);
    dfsbuild(root);
    vll ans(n,0);
    forn(i,1,n+1) {
        for(auto x : lvl[i]) upd(x, 1);
        for(auto x : lvl[i]) if(x!=root) ans[x] = get(par[x]) - i + 1;
    }
//    ans[root]=0;
    forn(i,0,n) printf("%lld ", ans[i]);
    
    
}