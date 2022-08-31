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

const long long mod = 998244353;
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
vi col;
int curcol = 0;
int bad = 0;
vi repr;

void dfs(int v, int c) {
    col[v] = c;
    repr[c] = v;
    for(auto u : g[v]) {
        if(col[u] == -1) dfs(u,c^1);
        else if((col[u]^col[v]) != 1) bad = 1;
    }
}
vi used;
vvi g2;
void dfs2(int v, int c) {
    used[v] = c;
    for(auto u : g2[v]) {
        if(used[u] == -1) dfs2(u,c^1);
        else if((used[u]^used[v]) != 1) bad = 1;
    }
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    col = vi(n, -1);
    repr=  vi(2*n, -1);
    readv(c,n);
    g.resize(n);
    g2.resize(2*n);
    used = vi(2*n, -1);
    vi a(m), b(m);
    vvi groups(k);
    forn(i,0,n) {
        c[i]--;
        groups[c[i]].pb(i);
    }
    vector<pair<pi, int>> e;
    forn(i,0,m) {
        scanf("%d %d", &a[i], &b[i]);
        a[i]--; b[i]--;
        if(c[a[i]] == c[b[i]]) {
            g[a[i]].pb(b[i]);
            g[b[i]].pb(a[i]);
        }
        else {
            pi code = mp(min(c[a[i]], c[b[i]]), max(c[a[i]], c[b[i]]));
            e.pb(mp(code, i));
        }
    }
    vi bg(k,0);
    ll good =k;
    forn(i,0,k) {
        bad = 0;
        for(auto x : groups[i]) {
            if(col[x] == -1) dfs(x, curcol);
            curcol += 2;
        }
        if(bad) {
            bg[i] = 1;
            good--;
        }
    }
    srt(e);
    ll ans = good*(good-1)/2;
    int pt = 0;
    while(pt < e.size()) {
        if(bg[e[pt].first.first] || bg[e[pt].first.second]) {
            pt++;
            continue;
        }
        int ptr = pt+1;
        while(ptr < e.size() && e[ptr].first == e[pt].first) ptr++;
        
        vi touch;
        forn(i,pt,ptr) {
            int u = a[e[i].second];
            int v = b[e[i].second];
            int c1 = col[u];
            int c2 = col[v];
            g2[col[u]].pb(col[v]);
            g2[col[v]].pb(col[u]);
            if(c1%2==1) c1--;
            if(c2%2==1) c2--;
            touch.pb(c1);
            touch.pb(c2);
        }
        srt(touch);
        forn(i,0,touch.size()) {
            if(i==0 || touch[i] != touch[i-1]) {
                g2[touch[i]].pb(touch[i]+1);
                g2[touch[i]+1].pb(touch[i]);
            }
        }
        bad = 0;
        for(auto x : touch) if(used[x] == -1) dfs2(x, 0);
        if(bad) ans--;
        for(auto x : touch) {
            used[x] = -1;
            used[x+1] = -1;
            g2[x].clear();
            g2[x+1].clear();
        }
        pt = ptr;
    }
    cout<<ans;
}