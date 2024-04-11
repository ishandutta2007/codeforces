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

vvpi nb;
vpi par;
vi lvl;
int n,m;

vi vis1;
void dfs(int v, int p) {
    vis1[v] = 1;
    for(auto u : nb[v]) {
        if(!vis1[u.first]) {
            lvl[u.first] = lvl[v] + 1;
            par[u.first] = mp(v, u.second);
            dfs(u.first, v);
        }
    }
}

vi vis;
vll en;
vll need;

void dfs2(int v) {
    vis[v] = 1;
    for(auto u : nb[v]) {
        if(!vis[u.first]) {
            dfs2(u.first);
            en[u.second] += need[u.first];
            need[v] -= need[u.first];
        }
    }
}

void dfs3(int v, int p) {
    vis[v] = 1;
    for(auto u : nb[v]) {
        if(!vis[u.first]) {
            dfs2(u.first);
            en[u.second] += need[u.first];
            need[v] -= need[u.first];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d %d", &n, &m);
    nb.resize(n);
    lvl.resize(n);
    par.resize(n);
    vis1 = vi(n,0);
    vpi e;
    en = vll(m,0);
    need.resize(n);
    forn(i,0,n) scanf("%lld", &need[i]);
    forn(i,0,m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        nb[u].pb(mp(v, i));
        nb[v].pb(mp(u, i));
        e.pb(mp(u,v));
    }
    dfs(0, 0);
    forn(i,0,m) {
        int u = e[i] .first;
        int v = e[i].second;
        if((lvl[u] + lvl[v])%2 == 0) {
            deque<pi> oc;
            oc.pb(mp(u, i));
            while(lvl[u] > lvl[v]) {
                oc.push_front(mp(par[u].first, par[u].second));
                u = par[u].first;
            }
            while(lvl[v] > lvl[u]) {
                oc.pb(mp(v, par[v].second));
                v = par[v].first;
            }
            while(u!=v) {
                oc.pb(mp(v, par[v].second));
                v = par[v].first;
                oc.push_front(mp(par[u].first, par[u].second));
                u = par[u].first;
            }
            vis = vi(n,0);
            for(auto x : oc) vis[x.first] = 1;
            for(auto x : oc) dfs2(x.first);
            forn(it,0,((int)oc.size())-1) {
                int u = oc[it].first;
                int v = oc[it+1].first;
                int ind = oc[it].second;
                if(need[u] % 2 != 0) {
                    need[u]--;
                    need[v]--;
                    en[ind]++;
                }
            }
//            ll totneed = 0;
//            for(auto x : oc) totneed+=need[x.first];
//            totneed /= 2;
//            forn(j,0,oc.size()) {
//                if(j%2 == 0) en[oc[j].second] += totneed;
//                else en[oc[j].second] -= totneed;
//            }
//            need[oc[0].first] -= totneed*2;
            forn(j,0,int(oc.size())) {
                int uu = oc[j].first;
                int vv = oc[(j+1)%oc.size()].first;
                en[oc[j].second] += need[uu];
                need[vv] -= need[uu];
                need[uu] = 0;
            }
            ll totneed = need[oc[0].first]/2;
                        forn(j,0,oc.size()) {
                            if(j%2 == 0) en[oc[j].second] += totneed;
                            else en[oc[j].second] -= totneed;
                        }
                        need[oc[0].first] -= totneed*2;
            printf("YES\n");
            forn(j,0,m) printf("%lld\n", en[j]);
            return 0;
        }
    }
    vll sum(2, 0);
    forn(i,0,n) sum[lvl[i]%2] += need[i];
    if(sum[0] != sum[1]) {
        printf("NO");
        return 0;
    }
    vis = vi(n,0);
    dfs3(0, 0);
    printf("YES\n");
    forn(j,0,m) printf("%lld\n", en[j]);
    
}