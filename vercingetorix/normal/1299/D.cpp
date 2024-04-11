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
typedef std::vector<vvi > vvvi;
typedef std::vector<vvvi > vvvvi;
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
vvi basis;

void reduce(vi & a) {
    int k = a.size();
    forn(i,0,k) {
        forn(j,i+1, k) if(a[j] > a[i]) swap(a[i], a[j]);
        forn(j,i+1,k) if((a[j]^a[i]) < a[j]) a[j] ^= a[i];
        forn(j,0,i) if((a[i]^a[j]) < a[j]) a[j] ^= a[i];
    }
}

set<vi> have;

void genbasis() {
    basis.pb(vi());
    for(int l = 31; l >= 0; l--) {
        int k = basis.size();
        forn(i,0,k) {
            vi x = basis[i];
            x.pb(l);
            reduce(x);
            if(x.back() != 0 && have.find(x)==have.end()) {
                basis.pb(x);
                have.insert(x);
            }
        }
    }
}

vvpi g;
vvvi bs(6);
vvi mul;

map<vi, int> wh;
vi block;

vi dist;
int curbasis;
vi tin;
int curt = 0;
void dfs(int v, int p1, int p2, int cur) {
//    cout<<v<<' '<<p1<<endl;
    dist[v] = cur;
    tin[v] = curt++;
    for(auto u : g[v]) {
        if(u.first == p1 || u.first == p2) continue;
        if(dist[u.first] != -1) {
            if(tin[u.first] >= tin[v]) continue;
            int cl = dist[u.first] ^ dist[v] ^ u.second;
//            cout<<"HI:" <<u.first<<' '<<v<<' '<<cl<<endl;
            if(cl == 0) curbasis = -1;
            else {
                int nb = wh[vi(1, cl)];
                if(curbasis != -1) curbasis = mul[curbasis][nb];
            }
        }
        else {
            dfs(u.first, v, v, cur^u.second);
        }
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    genbasis();
    for(auto x : basis) bs[x.size()].pb(x);
    int k = basis.size();
    forn(i,0,k) wh[basis[i]] = i;
    mul = vvi(k, vi(k, -1));
    forn(i,0,k) forn(j,0,k) {
        vi x = basis[i];
        for(auto v : basis[j]) x.pb(v);
        reduce(x);
        if(x.empty()||x.back() != 0) mul[i][j] = wh[x];
    }
//    bs[5] = vvi();
//    bs[5].pb(vi({16,8,4,2,1}));
//    forn(i,0,6) forn(j,0,bs[i].size()) wh[bs[i][j]] = mp(i,j);
//    cout<<1;
//    forn(n1,0,6) forn(n2,0,6) {
//        if(n1+n2 <= 5) {
//            mul[n1][n2] = vvi(bs[n1].size(), vi(bs[n2].size(), -1));
//            forn(i,0,bs[n1].size()) forn(j,0,bs[n2].size()) {
//                vi test = bs[n1][i];
//                for(auto x : bs[n2][j]) test.pb(x);
//                reduce(test);
//                if(test.empty() || test.back() != 0) {
//                    if(n1+n2 == 5) mul[n1][n2][i][j] = 0;
//                    else mul[n1][n2][i][j] = wh[test].second;
//                }
//            }
//        }
//    }
//    exit(0);
    int n,m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
    }
    vi pr(n, -1);
    vi cost(n);
    vi cost2(n);
    for(auto x : g[0]) pr[x.first] = x.first;
    for(auto x : g[0]) cost[x.first] = x.second;
    for(auto x : g[0]) {
        int u = x.first;
        for(auto vp : g[u]) {
            int v = vp.first;
            if(v == 0 || pr[v] == -1)  continue;
            cost2[v] = cost[v]^cost[u]^vp.second;
            cost2[u] = cost[v]^cost[u]^vp.second;
            pr[v] = u;
            pr[u] = v;
        }
    }
    vpi p;
    vi q;
    block = vi(n,0);
    block[0] = 1;
    for(auto x : g[0]) block[x.first] = 1;
    forn(i,0,n) {
        if(pr[i] == i) q.pb(i);
        else if(pr[i] != -1) {
            p.pb(mp(i, pr[i]));
            pr[pr[i]] = -1;
            pr[i] = -1;
        }
    }
    
    dist = vi(n,-1);
    tin = vi(n,0);
    
    vll d(k,0);
    d[0] = 1;
    int can = 1;
    for(auto v : q) {
        curbasis = 0;
        
        dfs(v, 0, 0, 0);
        if(curbasis == -1) {
            continue;
        }
        vll nd = d;
        forn(i,0,k) {
            int to = mul[i][curbasis];
            if(to != -1) nd[to] = (nd[to] + d[i]) % mod;
        }
        d = nd;
    }
    for(auto xx : p) {
        int v1 = xx.first;
        int v2 = xx.second;
        curbasis = 0;
        dfs(v1, v2, 0, 0);
        int b1 = curbasis;
        curbasis = 0;
        dfs(v2, v1, 0 ,0);
        int b2 = curbasis;
        if(b1 == -1 || b2 == -1) {
            continue;
            
        }
        int b = mul[b1][b2];
        if(b == -1) {
            continue;
        }
        vll nd = d;
        forn(i,0,k) {
            int to = mul[i][b];
            if(to != -1) nd[to] = (nd[to] + 2*d[i]) % mod;
        }
        if(cost2[v1] != 0) {
            int b3 = wh[vi(1,cost2[v1])];
            b = mul[b][b3];
            if(b != -1) {
                forn(i,0,k) {
                    int to = mul[i][b];
                    if(to != -1) nd[to] = (nd[to] + d[i]) % mod;
                }
            }
        }
        
        d = nd;
    }
    if (can == 0) cout<<0;
    else {
        ll ans = 0;
        forn(i,0,k) ans += d[i];
        ans%=mod;
        cout<<ans;
    }
//    cout<<1;
    
    
    
}