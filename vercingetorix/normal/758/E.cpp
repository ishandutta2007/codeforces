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
vll w,p;
vll minw, maxw;
vll needw;
vll curw;
vvpi nb;
vvi ch;
int n;
vi par;

bool can = true;
void dfs(int v) {
    for(auto u : ch[v]) dfs(u);
    minw[v] = 0;
    maxw[v] = 0;
    curw[v] = 0;
    for(auto u : ch[v]) {
        maxw[v] += maxw[u];
        minw[v] += minw[u];
        curw[v] += curw[u];
    }
    if(v==0) return;
    
    int e = par[v];
    curw[v] += w[e];
    if(p[e] < minw[v]) {
        cout<<-1;
        exit(0);
    }
    ll dim = min(w[e] - 1, p[e] - minw[v]);
    minw[v] += w[e] - dim;
    maxw[v] = min(maxw[v], p[e]);
    maxw[v] += w[e];
}

void dim(int v, ll to) {
    for(auto u : ch[v]) {
        needw[u] = curw[u];
        if(needw[u] > maxw[u]) {
            curw[v] -= (needw[u]-maxw[u]);
            needw[u]=maxw[u];
        }
    }
    for(auto u : ch[v]) {
        ll rem = min(needw[u] - minw[u], curw[v] - to);
        needw[u]-=rem;
        curw[v]-=rem;
        dim(u, needw[u]);
    }
    w[par[v]] -= curw[v]-to;
    p[par[v]] -= curw[v]-to;
    curw[v] = to;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d", &n);
    w.resize(n-1);
    p.resize(n-1);
    par.resize(n);
    nb.resize(n);
    ch.resize(n);
    minw.resize(n);
    curw.resize(n);
    maxw.resize(n);
    vi u1(n), u2(n);
    forn(i,0,n-1) {
        int x,y;
//        scanf("%d %d %d %d", &n);
        scanf("%d %d %lld %lld", &x, &y, &w[i], &p[i]);
        u1[i] = x; u2[i]=y;
        x--;
        y--;
        
        nb[x].pb(mp(y,i));
        nb[y].pb(mp(x,i));
    }
    vpi q;
    q.pb(mp(0,0));
    int pt = 0;
    while(pt<q.size()) {
        int v = q[pt].first;
        for(auto u : nb[v]) {
            if(u.first != q[pt].second) {
                par[u.first] = u.second;
                ch[v].pb(u.first);
                q.pb(mp(u.first, v));
            }
        }
        pt++;
    }
    dfs(0);
    needw.resize(n);
    for(auto v : ch[0]) dim(v, min(curw[v],maxw[v]));
    printf("%d\n", n);
    
    forn(i,0,n-1) {
        printf("%d %d %lld %lld\n", u1[i], u2[i], w[i], p[i]);
    }
    
    
    
}