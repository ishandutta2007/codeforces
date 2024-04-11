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
int n;
vvi g;
int par[20][100400];
int parrev[20][100400];
ll gc[20][100500];
int lev[100500];
vll a;

void dfs(int v, int p) {
    for(auto u : g[v]) {
        if(u==p) continue;
        lev[u] = lev[v] + 1;
        par[0][u] = v;
        dfs(u, v);
    }
}
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
vi pd2;
vi d2(1,1);
int up(int v, int s) {
    if(s==0) return v;
    int di = pd2[s];
    for(int i = di; i>=0; i--) {
        if(s >= d2[i]) {
            s-=d2[i];
            v = par[i][v];
        }
    }
    return v;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    a.resize(n);
    g.resize(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    lev[0] = 0;
    par[0][0] = 0;
    dfs(0,0);
    forn(i,0,n) gc[0][i] = gcd(a[i], a[par[0][i]]);
    forn(l,1,20) {
        forn(i,0,n) {
            par[l][i] = par[l-1][par[l-1][i]];
            gc[l][i] = gcd(gc[l-1][i], gc[l-1][par[l-1][i]]);
        }
    }
    pd2.pb(0);
    forn(i,0,30) d2.pb(d2.back()*2);
    int deg = 0;
    forn(i,1,n+10) {
        while(d2[deg+1] <= i) {
            deg++;
        }
        pd2.pb(deg);
    }
    ll ans = 0;
    forn(i,0,n) {
        ll cur = a[i];
        int p = i;
        while(1) {
            int l = 0;
            if(gc[19][p] == cur) {
                ans += cur*(lev[p] + 1);
                break;
            }
            for(int i = pd2[lev[p]+1]; i>=0; i--) {
                if(d2[i] <= lev[p]) if(gc[i][p]==0 || (cur!=0 && gc[i][p] % cur == 0)) {
                    l+= d2[i];
                    p = par[i][p];
                }
            }
//            int r = lev[p] + 1;
//            while(r-l>1) {
//                int m = (r+l)/2;
//                int di = pd2[m];
//                ll cg = gcd(gc[di][p], gc[di][up(p,m-d2[di]+1)]);
//                if(cg == cur) l = m;
//                else r = m;
//            }
            ans += cur*(l+1);
            if(p == 0) break;
            p = par[0][p];
            cur = gcd(cur, a[p]);
        }
        ans %= mod;
        
    }
    cout<<ans;
    
}