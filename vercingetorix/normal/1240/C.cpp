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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

vll bk, bk1;
vvpi g;
int n,k;

void dfs(int v, int p) {
    for(auto u : g[v]) {
        if(u.first!= p) dfs(u.first,v);
    }
    ll val = 0;
    vll imp;
    for(auto u : g[v]) {
        if(u.first==p) continue;
        val += bk[u.first];
        imp.pb(bk1[u.first] - bk[u.first] + u.second);
    }
    srtrev(imp);
    bk1[v] = val;
    forn(i,0,min((int)imp.size(), k-1)) if(imp[i] > 0) bk1[v] += imp[i];
    bk[v] = bk1[v];
    if(k-1 < imp.size() && imp[k-1] > 0) bk[v] += imp[k-1];
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        scanf("%d %d", &n, &k);
        bk = vll(n,0);
        bk1 = vll(n,0);
        g = vvpi(n);
        forn(i,0,n-1) {
            int u,v,w;
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            g[u].pb(mp(v,w)); g[v].pb(mp(u,w));
        }
        dfs(0,0);
        printf("%lld\n", bk[0]);
    }
    
    
}