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
int n,k;
vvi g;
vvi cnt;

void dfs(int v, int p, int d) {
    cnt.back()[d]++;
    for(auto u : g[v]) if(u!=p) dfs(u, v, d+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        
        scanf("%d %d", &n, &k);
        g= vvi (n);
        forn(i,1,n) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        if(k == 2) {
            printf("%d\n", n*(n-1)/2);
            continue;
        }
        ll ans = 0;
        forn(i,0,n) {
            cnt = vvi();
            if(g[i].size() >= k) {
                for(auto u : g[i]) {
                    cnt.pb(vi(n,0));
                    dfs(u, i, 1);
                }
                
                forn(l,1,n) {
                    vi t;
                    forn(i,0,cnt.size()) {
                        if(cnt[i][l] > 0) t.pb(cnt[i][l]);
                    }
                    if(t.size() < k) break;
                    vll d(k+1,0);
                    d[0] = 1;
                    for(auto x : t) {
                        for(int i = k; i > 0; i--) d[i] = (d[i] + d[i-1]*x)%mod;
                    }
                    ans =  (ans+d[k])%mod;
                }
                
            }
        }
        printf("%lld\n", ans);
        
    }
    
}