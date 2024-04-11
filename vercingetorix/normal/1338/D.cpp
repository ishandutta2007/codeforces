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
int ans = 0;
vi btake;
vi bon;

vvi g;
vi d;
void go(int v, int p) {
    vpi bons;
    vpi bts;
    int deg = 0;
    for(auto u:g[v]) {
        if(u==p) continue;
        go(u,v);
        deg++;
        bons.pb(mp(bon[u], u));
        bts.pb(mp(btake[u], u));
    }
    sort(all(bons));
    sort(all(bts));
    reverse(all(bons));
    reverse(all(bts));
    if(deg == 0) {
        btake[v] = 0;
        bon[v] = 0;
        return;
    }
    btake[v] = max(deg-1 + bts[0].first, deg + bons[0].first);
    bon[v] = bts[0].first;
    ans = max(ans, btake[v]);
    if(v!=0) ans = max(ans, btake[v] + 1);
    int add = 0;
    if(v!=0) add = 1;
    if(deg>=2) {
        set<int> inset;
        forn(i,0,2) {
            inset.insert(bts[i].second);
            inset.insert(bons[i].second);
        }
        for(auto i : inset) for(auto j : inset) {
            if(i==j) continue;
            ans = max(ans, btake[i] + btake[j] + 1);
            ans = max(ans, bon[i] + bon[j] + deg + add);
            ans = max(ans, bon[i] + 1 + btake[j] + deg - 2 + add);
            ans = max(ans, btake[i] + btake[j] + deg-2 + add);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    g = vvi(n);
    d.resize(n);
    btake= vi(n,0);
    bon = vi(n,0);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    go(0,0);
    cout<<ans;
}