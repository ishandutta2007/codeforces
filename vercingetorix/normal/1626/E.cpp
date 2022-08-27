#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vvi g(n);
    readv(col, n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi deg(n);
    forn(i,0,n) deg[i] = g[i].size();
    vi q;
    forn(i,0,n) if(col[i] == 0 && deg[i] == 1) q.pb(i);
    vi ans(n, 0);
    vi dead(n,0);
    vpi ff;
    while(!q.empty()) {
        int v = q.back();
        dead[v] = 1;
        q.pop_back();
        for(auto u : g[v]) {
            if(dead[u] == 0) {
                ff.pb(mp(v, u));
                deg[u]--;
                if(col[u] == 0 && deg[u] == 1) q.pb(u);
            }
        }
    }
    forn(v,0,n) {
        if(col[v] == 1) {
            int num = 0;
            ans[v] = 1;
            for(auto u : g[v]) {
                ans[u] = 1;
                if(dead[u] == 0) num++;
                if(col[u] == 1) num+=2;
            }
            if(num > 1) {
                forn(i,0,n) ans[i] = 1;
                break;
            }
        }
        else {
            int num = 0;
            int b = 0;
            for(auto u : g[v]) {
                if(dead[u] == 0) num++;
                if(col[u] == 1) b++;
            }
            if(num > 2 && b > 0) {
                forn(i,0,n) ans[i] = 1;
                break;
            }
        }
    }
    while(!ff.empty()) {
        ans[ff.back().first] = ans[ff.back().second];
        ff.pop_back();
    }
    forn(i,0,n) printf("%d ", ans[i]);
    
    
    
}