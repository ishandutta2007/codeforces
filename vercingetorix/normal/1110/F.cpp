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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const ll INF = 1e18;
ll t[2000000];
ll pp[2000000];
const int buka = 1000000;
class stree {
public:
//    vll t;
//    vll pp;
    int s;
    void build (vll & a, int v, int tl, int tr) {
        int n = a.size();
        if(v==1) {
            forn(i,0,n*4) {
                t[i] = 0;
                pp[i] = 0;
            }
//            t.resize(n * 4);
//            pp = vll(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
//    void push(int v, int tl, int tr) {
//        if(pp[v] == 0) return;
//        t[v] += pp[v];
//        if(tl != tr) {
//            pp[2*v] += pp[v];
//            pp[2*v+1] += pp[v];
//        }
//        pp[v] = 0;
//    }
    void push(int v) {
        if(pp[v] == 0) return;
        t[v] += pp[v];
        if(v < buka) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, ll val) {
        //        cout<<"UPD "<<tl<<' '<<tr<<' '<<l<<' '<<r<<' '<<val<<endl;
        if (l == tl && tr == r) {
            pp[v] += val;
            push(v);
            return;
        }
        if (l > r) {
            push(v);
            return;
        }
        else {
            push(v);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        //        if(tl!=tr) {
        push(v);
        //        }
        if (l>r) return INF;
        if (tl==l && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        ll ret =  min(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = min(t[v*2], t[v*2+1]);
        return ret;
    }
};
vll w;
vi par;
int n,q;
vvi ch;
vll dist;

void dfsd(int v, ll d) {
    if(ch[v].empty()) dist[v] = d;
    for(auto u : ch[v]) {
        dfsd(u, d + w[u]);
    }
}

vector<vpi> qv;
vector<pair<int, pi>> qo;
map<pair<int, pi>, ll> ans;
stree st;
ll gm = 0;
vi rv;
int dfsr(int v) {
    int ret = v;
    for(auto u : ch[v]) {
        ret = max(ret, dfsr(u));
    }
    rv[v] = ret;
    return ret;
}

void dfs(int v) {
    gm += w[v];
    st.update(1, 0, n-1, v, rv[v], -2*w[v]);
    for(auto req : qv[v]) {
        ans[mp(v, req)] = st.get(1, 0, n-1, req.first, req.second) + gm;
    }
    for(auto u : ch[v]) dfs(u);
    st.update(1, 0, n-1, v, rv[v], 2*w[v]);
    gm -= w[v];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &q);
    par = vi(n,-1);
    w = vll(n,0);
    rv.resize(n);
    ch.resize(n);
    qv.resize(n);
    dist = vll(n,INF);
    forn(i,1,n) {
        scanf("%d %lld", &par[i], &w[i]);
        par[i]--;
        ch[par[i]].pb(i);
    }
    dfsd(0,0);
    dfsr(0);
    
//    st.build(n, 1, 0, n-1);
//    forn(i,0,n) st.update(1, 0, n-1, i, i, dist[i]);
    st.build(dist, 1, 0, n-1);
    forn(i,0,q) {
        int v,l,r;
        scanf("%d %d %d", &v, &l, &r);
        v--; l--; r--;
        qv[v].pb(mp(l,r));
        qo.pb(mp(v,mp(l,r)));
    }
    dfs(0);
    forn(i,0,q) {
        printf("%lld\n", ans[qo[i]]);
    }
}