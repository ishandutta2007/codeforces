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
vvi g;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    const int INF = 1e6;
    vvi d(n, vi(n, INF));
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v); u--; v--;
        g[u].pb(v);
        g[v].pb(u);
        d[u][v] = 1;
        d[v][u] = 1;
    }
    forn(i,0,n) d[i][i] = 0;
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    vvll res(n, vll(n,0));
    forn(x,0,n) {
        vpi e;
        forn(y,0,n) e.pb(mp(d[x][y], y));
        srt(e);
        forn(y,x,n) {
            map<pi, int> cnt;
            pi zz(-1, -1);
            vi used(n, 0);
            vi cand(n,0);
            forn(z,0,n) if(d[x][z] + d[z][y] == d[x][y]) {
                cnt[mp(d[x][z], d[z][y])]++;
                used[z] = 1;
                for(auto z2 : g[z]) if(d[x][z2] == d[x][z] + 1 && d[y][z2] == d[y][z] + 1) cand[z2]++;
            }
            int can = 1;
            for(auto tt : cnt) if(tt.second > 1) can = 0;
            if(can == 0) {
                res[x][y] = 0;
                res[y][x] = 0;
                continue;
            }
            ll ans = 1;
            for(auto pz : e) {
                int z = pz.second;
                if(used[z] == 1) continue;
                ans = ans*cand[z]%mod;
                for(auto z2 : g[z]) if(d[x][z2] == d[x][z] + 1 && d[y][z2] == d[y][z] + 1) cand[z2]++;
            }
            res[x][y] = ans;
            res[y][x] = ans;
        }
    }
    forn(x,0,n) {
        forn(y,0,n) printf("%lld ", res[x][y]);
        printf("\n");
    }
}