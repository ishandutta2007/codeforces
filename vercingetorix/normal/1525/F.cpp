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

const long long mod = 998244353 ;
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
int n,m,k;
vvi g;
bool used[500];
vi ans;

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ans.push_back (v);
}

void topological_sort() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    ans.clear();
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
    reverse (ans.begin(), ans.end());
}
vi nd;
vi orddel;

vector<int> mt;
vector<char> used2;

bool try_kuhn (int v) {
    if (used2[v])  return false;
    used2[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int kuhn2() {
    mt.assign (n, -1);
    for (int v=0; v<n; ++v) {
        used2.assign (n, false);
        try_kuhn (v);
    }
    int ret = 0;
    for (int i=0; i<n; ++i)
        if (mt[i] != -1)
            ret++;
    return ret;
}

void build_nd() {
    int cur = kuhn2();
    nd = vi(k,0);
    for(int i = n-cur-1; i<k; i++) nd[i] = 1;
    while(cur>0) {
        vvi gwas = g;
        int did = 0;
        forn(dp,0,n) {
            g = vvi(n);
            forn(i,0,n) {
                if(i!=dp) g[i] = gwas[i];
            }
            int k2 = kuhn2();
            if(k2 < cur) {
                cur--;
                orddel.pb(dp+1);
                did=1;
                break;
            }
        }
        if(did) continue;
        forn(dm,0,n) {
            g = vvi(n);
            forn(i,0,n) for(auto v : gwas[i]) if(v != dm) g[i].pb(v);
            int k2 = kuhn2();
            if(k2 < cur) {
                cur--;
                orddel.pb(-dm-1);
                did=1;
                break;
            }
        }
    }
}




int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d", &n, &m, &k);
    g.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
    }
    vi x(k), y(k);
    forn(i,0,k) scanf("%d %d", &x[i], &y[i]);
    topological_sort();
    int pt = 0;
    build_nd();
    vvi del(k);
    vvi defdel(k);
    int ind = 0;
    ll dec = 0;
    int num = k;
//    forn(i,0,k) {
//        if(y[i] < y[ind]) ind = i;
//        if(nd[i]) {
//            del[ind].pb(orddel[pt++]);
//            dec+=y[ind];
//            num++;
//        }
//    }
//
//    for(int t0 = k-1; t0 >= 0; t0--) {
//        ll cand = x[t0];
//        forn(i,0,t0) cand += ll(y[i])*del[ind].size();
//        if(cand < dec) {
//            dec = cand;
//            forn(i,t0+1,k) {
//                for(auto x : del[i]) del[t0].pb(x);
//                del[i].clear();
//            }
//        }
//    }
    forn(i,0,k) if(nd[i]) {
        defdel[i].pb(orddel[pt++]);
        dec+=y[i];
        num++;
    }
    del = defdel;
    x.pb(0);
    forn(t0,0,k+1) {
        vvi canddel(k);
        int ind = 0;
        ll cand = x[t0];
        forn(i,0,t0) {
            if(y[i]<y[ind]) ind = i;
            for(auto x : defdel[i]) {
                canddel[ind].pb(x);
                cand += y[ind];
            }
        }
        forn(i,t0,k) {
            for(auto x : defdel[i]) canddel[t0].pb(x);
        }
        if(cand<dec) {
            dec = cand;
            del = canddel;
        }
    }
    printf("%d\n", num);
    forn(i,0,k) {
        for(auto x : del[i]) printf("%d ", x);
        printf("0 ");
    }
    
    
    
    
}