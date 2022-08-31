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
const int INF = 1e9;
vvi g, grev;
vi d;
vi ans;
int n,m;
void bfs() {
    deque<int> q;
    d[0] = 0;
    q.pb(0);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        for(auto x : g[v]) {
            if(d[x] == INF) {
                d[x] = d[v] + 1;
                q.pb(x);
            }
        }
    }
}

void go() {
    vpi a;
    forn(i,0,n) a.pb(mp(d[i] , i));
    sort(all(a));
//    reverse(all(a));
    vi bk(n);
    forn(i,0,n) bk[a[i].second] = i;
    vvi g2(2*n);
    forn(i,0,n) {
        g2[i].pb(i+n);
        int v = a[i].second;
        for(auto ui : g[v]) {
            int u = bk[ui];
            if(d[ui] > d[v]) {
                g2[i].pb(u);
                g2[i+n].pb(u+n);
            }
            else {
                g2[i].pb(u+n);
            }
        }
    }
    vi res(2*n, INF);
//    forn(i,0,2*n) {
    for(int i = 2*n-1; i>=0; i--) {
        if(i>=n) res[i] = d[a[i-n].second];
        for(auto u : g2[i]) res[i] = min(res[i], res[u]);
        if(i<n) ans[a[i].second] = res[i];
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(afaff,0,t) {
        scanf("%d %d", &n, &m);
        g = vvi(n);
        grev = vvi(n);
        d = vi(n,INF);
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--;v--;
            g[u].pb(v);
            grev[v].pb(u);
        }
        bfs();
        ans = vi(n,INF);
        go();
        forn(i,0,n) {
            printf("%d ", ans[i]);
        } printf("\n");
    }
}