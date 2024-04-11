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
#include <queue>
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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
vvi g;
vvi gn;
vi ans;
int n;
vi d2(1,1);

map<int, vi> gdp;

vi getdist(int s, int imax) {
    if(gdp[s].size() > 0) return gdp[s];
    vi res(d2[n], -1);
    res[s] = 0;
    priority_queue<pi> q;
    //    set<pi> q;
    //    q.insert(mp(0, s));
    q.push(mp(0,s));
    while(!q.empty()) {
        auto it = q.top();
        int v = it.second;
        int d = -it.first;
        //        q.erase(it);
        q.pop();
        forn(i,0,imax+1) if(res[g[v][i]] == -1) {
            res[g[v][i]] = d + 1;
            q.push(mp(-d-1, g[v][i]));
            //            q.insert(mp(d+1, u));
        }
    }
    vi ver;
    forn(i,0,d2[n]) if(res[i]!=-1) ver.pb(i);
    forn(i,imax+1,n) {
        int k = ver.size();
        forn(j,0,k) {
            int u = g[ver[j]][i];
            ver.pb(u);
            res[u] = res[ver[j]]+1;
        }
    }
    gdp[s] = res;
    return res;
}

//map<int, int> getdist(int s) {
//    map<int, int> ret;
//    map<int, int> done;
//    ret[s] = 0;
//    set<pi> q;
//    q.insert(mp(0, s));
//    while(!q.empty()) {
//        auto it = q.begin();
//        int v = it->second;
//        int d = it->first;
//        q.erase(it);
//        if(done[v]) continue;
//        done[v] = 1;
//        ret[v] = d;
//        for(auto u : g[v]) q.insert(mp(d+1, u));
//    }
//    return ret;
//}

void gos(int v, int v2, int imax) {
//    map<int, int> tp;
    vi tp(d2[n]);
    //    map<int, int> d1 = getdist(v);
    //    map<int, int> dd2 = getdist(v2);
    vi d1 = getdist(v, imax);
    vi dd2 = getdist(v2, imax);
    forn(x,0,d2[n]) {
        if(d1[x] < dd2[x]) tp[x] = 1;
        else tp[x] = 2;
    }
    forn(x,0,d2[n]) {
        forn(i,0, imax) if(tp[x] != tp[g[x][i]]) {
            swap(g[x][i], g[x][imax]);
            break;
        }
    }
}

void split(int v, int i) {
    int v2 = g[v][i];
    vi ver(1,v2);
    ans[v2] += d2[i];
    forn(j,0,i) {
        int k = ver.size();
        forn(ii,0,k) {
            int v3 = g[ver[ii]][j];
            ans[v3] += d2[i];
            ver.pb(v3);
        }
    }
    if(i>0) {
        split(v,i-1);
        split(v2,i-1);
    }
}

//void go(int v, vi & ord) {
//    if(g[v].empty()) return;
//    int v2 = ord.back();
//    map<int, int> tp;
//    map<int, int> d1 = getdist(v);
//    map<int, int> d2 = getdist(v2);
//    for(auto x : d1) {
//        if(d1[x.first] < d2[x.first]) tp[x.first] = 1;
//        else tp[x.first] = 2;
//    }
//    ord.pop_back();
//    vi ord2;
//    for(auto x : ord) {
//        for(auto u : g[x]) if(tp[u] == 2) ord2.pb(u);
//    }
//    for(auto x : d1) {
//        for(auto u : g[x.first]) if(tp[x.first] != tp[u]) {
//            g[x.first].erase(u);
//            break;
//        }
//    }
//    int dwas = d1.size()/2;
//    for(auto x : d1) if(tp[x.first] == 2) ans[x.first] += dwas;
//
//    go(v, ord);
//    go(v2, ord2);
//}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    forn(i,0,20) d2.pb(d2.back()*2);
    vi bitodd(1,0);
    forn(i,1,d2[16]+1) {
        bitodd.pb((i%2)^bitodd[i/2]);
    }
    vvi col(17);
    col[1] = {0,0};
    forn(id,1,5) {
        int dd = d2[id-1];
        int dn = d2[id];
        forn(i,0,d2[dd]) {
            forn(j,0,d2[dd]) {
                col[dn].pb((col[dd][j] + col[dd][i]) % dd + (bitodd[i])*dd);
            }
        }
    }
    int t;
    scanf("%d", &t);
    vpi e;
    forn(i,0,d2[4]) {
        forn(j,0,4) if((i^d2[j]) < i) e.pb(mp(i, i^d2[j]));
    }
    while(t--) {
        gdp =map<int, vi>();
        scanf("%d", &n);
        g = vvi (d2[n]);
        gn = vvi(d2[n], vi(n));
        ans = vi(d2[n], 0);
        forn(i,0,n*d2[n-1]) {
            int u,v;
            scanf("%d %d", &u, &v);
            // u = e[i].first;
            // v = e[i].second;
            g[u].pb(v);
            g[v].pb(u);
        }
        vi ord;
        int pt = 0;
        vi spor = g[0];
        for(auto v : spor) gos(0, v, n-1-(pt++));
//                for(auto v : g[0]) ord.pb(v);
        //        go(0, ord);
        split(0, n-1);
        vi res(d2[n]);
        forn(i,0,d2[n]) res[ans[i]] = i;
        forn(i,0,d2[n]) printf("%d ", res[i]);
        printf("\n");
        if(col[n].size() == 0) {
            printf("-1\n");
        }
        else {
            forn(i,0,d2[n]) printf("%d ", col[n][ans[i]]);
            printf("\n");
        }
    }
    
    
    
}