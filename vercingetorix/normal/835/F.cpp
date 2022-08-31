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

vvpi nb;
vpi par;
vi vis;
int ban = -1;
vpi cycle;

ll mcand = 0;

void dfsc(int v, int p) {
    vis[v] = 1;
    for(auto u : nb[v]) {
        if (u.first == p || u.first == ban) continue;
        if (vis[u.first]) {
            ban = v;
            cycle.pb(u);
            int cur = v;
            while(cur != u.first) {
                cycle.pb(mp(cur, par[cur].second));
                cur = par[cur].first;
            }
        }
        else {
            par[u.first] = mp(v, u.second);
            dfsc(u.first, v);
        }
    }
}

ll dfsl(int v, int p, ll cur) {
    ll res = cur;
    ll tup = 0;
    for(auto u : nb[v]) {
        if(u.first == p) continue;
        ll yeah = dfsl(u.first, v, cur + (ll)u.second);
        res = max(res, yeah);
        mcand = max(mcand, yeah - cur + tup);
        tup = max(yeah - cur, tup);
    }
    return res;
}
const ll INF = 1e18;
class stree {
public:
    vpll t;
    int s;
    void build (vll & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr)
            t[v] = mp(a[tl],tl);
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    pll get (int v, int tl, int tr, int l, int r) {
        if(l>r) return mp(-INF,0);
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return max(get (v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
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
    nb.resize(n);
    forn(i,0,n) {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c);
        u--; v--;
        nb[u].pb(mp(v,c));
        nb[v].pb(mp(u,c));
    }
    par.resize(n);
    vis = vi(n,0);
    dfsc(0, -1);

    int k = cycle.size();
    vll d(k,0);
    
    forn(i,0,k) {
        int nb1 = cycle[(i+1)%k].first;
        int nb2 = cycle[(i+k-1)%k].first;
        for(auto u : nb[cycle[i].first]) if(u.first != nb1 && u.first != nb2) {
            ll upd = dfsl(u.first, cycle[i].first, u.second);
            mcand = max(d[i] + upd, mcand);
            d[i] = max(d[i], upd);
        }
        
    }
//    for(auto x : cycle) cout<<x.first<<' '<<x.second<<endl;
    ll clen = 0;
    for(auto x : cycle) clen += (ll)x.second;
    int cur = 0;
    vll torin;
    vll tolin;
    ll dist = 0;
    forn(i,0,2*k) {
        torin.pb(d[i%k] - dist);
        tolin.pb(d[i%k] + dist);
        dist += (ll)cycle[i%k].second;
    }
    stree tor, tol;
    tor.build(torin, 1, 0, 2*k-1);
    tol.build(tolin, 1, 0, 2*k-1);
    ll ans = INF;
    forn(s,0,k) {
        ll cand = d[s] + d[(s+1)%k] + clen - (ll)cycle[s].second;
        pll rcurval = tor.get(1, 0, 2*k-1, s+1, s+1);
        pll rbestval = tor.get(1,0,2*k-1,s+1,s+k-1);
        pll lcurval = tol.get(1, 0, 2*k-1, s+k, s+k);
        pll lbestval = tol.get(1,0,2*k-1,s+2,s+k);
        int sr = rbestval.second;
        int sl = lbestval.second;
        if (sr%k != sl%k) cand += rbestval.first - rcurval.first + lbestval.first - lcurval.first;
        else {
            pll r2bestval = tor.get(1,0,2*k-1,s+1,sr-1);
            pll l2bestval = tol.get(1,0,2*k-1,sl+1,s+k);
            cand += max(r2bestval.first+lbestval.first, l2bestval.first+rbestval.first) - rcurval.first - lcurval.first;
        }
        ans = min(ans, cand);
    }
    ans = max(ans, mcand);
    cout<<ans;
}