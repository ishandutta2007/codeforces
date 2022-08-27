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


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair


int n;
ll mod;
vvi ch;
vvpi nb;
vi digit;
vi par, v_lvl;
vvi lvl;
vi st;
ll ans = 0;

int dfs1(int v) {
    st[v] = 1;
    for(auto u : ch[v]) {
        st[v] += dfs1(u);
    }
    return st[v];
}

void rebase(int v, int p, int block) {
    vi newch;
    for(auto x : ch[v]) {
        if(x == p) continue;
        newch.pb(x);
    }
    if(par[v] != p && par[v] != block) {
        newch.pb(par[v]);
        
        rebase(par[v], v, block);
        digit[par[v]] = digit[v];
        par[par[v]] = v;
    }
    ch[v] = newch;
}

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    gcd(a, modulo, x, y);
    return (x+modulo*modulo)%modulo;
}

vll d10;
vll d10inv;

vi has;
vi need;
vi newneed;
vi newhas;

void dfs2(int v, int lev, ll up, ll down) {
    newhas.pb(up);
    newneed.pb(((mod-down)*d10inv[lev])%mod);
    for(auto u : ch[v]) {
        dfs2(u, lev+1, (up+d10[lev]*(ll)digit[u])%mod, (down*10ll + digit[u])%mod);
    }
}

void go(int root) {
    if(st[root] == 1) return;
    int v = root;
    while(1) {
        int ind = 0;
        forn(i,1,ch[v].size()) {
            if(st[ch[v][i]] > st[ch[v][ind]]) ind = i;
        }
        if(2*st[ch[v][ind]] > st[root]) v = ch[v][ind];
        else break;
    }
    if(v!=root) {
        rebase(v, -1, par[root]);
        dfs1(v);
    }
    has.clear();
    need.clear();
    for(auto u : ch[v]) {
        newneed.clear();
        newhas.clear();
        dfs2(u, 1, digit[u]%mod, digit[u]%mod);
        sort(all(newhas));
        sort(all(newneed));
        int ph = 0;
        int pn = 0;
        while(ph<newhas.size() && pn < newneed.size()) {
            if(newhas[ph] < newneed[pn]) ph++;
            else if(newhas[ph] > newneed[pn]) pn++;
            else {
                int nph = ph+1;
                while(nph < newhas.size() && newhas[nph] == newhas[ph]) nph++;
                int npn = pn+1;
                while(npn < newneed.size() && newneed[npn] == newneed[pn]) npn++;
                ans -= ll(nph-ph) * ll(npn-pn);
                ph=nph;
                pn=npn;
            }
        }
        for(auto x : newneed) need.pb(x);
        for(auto x : newhas) has.pb(x);
        
    }
    sort(all(has));
    sort(all(need));
    int ph = 0;
    int pn = 0;
    while(ph<has.size() && pn < need.size()) {
        if(has[ph] < need[pn]) ph++;
        else if(has[ph] > need[pn]) pn++;
        else {
            int nph = ph+1;
            while(nph < has.size() && has[nph] == has[ph]) nph++;
            int npn = pn+1;
            while(npn < need.size() && need[npn] == need[pn]) npn++;
            ans += ll(nph-ph) * ll(npn-pn);
            ph=nph;
            pn=npn;
        }
    }
    ph = 0; pn = 0;
    while(ph < has.size() && has[ph] == 0) { ans++; ph++; }
    while(pn < need.size() && need[pn] == 0) {ans++; pn++; }
    for(auto u : ch[v]) go(u);
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %lld", &n, &mod);
    
    v_lvl.resize(n);
    par.resize(n);
    ch.resize(n);
    digit.resize(n);
    nb.resize(n);
    lvl.resize(n+1);
    st.resize(n);
    
    int m=1;
    lvl[1].push_back(0);
    v_lvl[0]=1;
    map<pi, int> w;
    for(int i=1;i<n;i++){
        int u,v,d;
        scanf("%d %d %d", &u, &v, &d);
//        u=i-1;
//        v=i;
//        d=1;
        nb[u].push_back(mp(v,d));
        nb[v].push_back(mp(u,d));
        w[mp(u,v)] = d;
        w[mp(v,u)] = d;
    }
    int l=2;
    
    while(m<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h].first]==0){
                    v_lvl[nb[v][h].first]=l;
                    lvl[l].push_back(nb[v][h].first);
                    m++;
                    ch[v].push_back(nb[v][h].first);
                    par[nb[v][h].first]=v;
                    digit[nb[v][h].first]=nb[v][h].second;
                }
            }
        }
        l++;
    }
    l--;
    par[0] = -1;
    d10 = vll(1,1);
    forn(i,0,100000) d10.pb((d10.back()*10)%mod);
    forn(i,0,100001) d10inv.pb(invmod(d10[i], mod));
    dfs1(0);
    go(0);
    cout<<ans;
    
    
}