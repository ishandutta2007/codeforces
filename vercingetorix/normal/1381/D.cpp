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
vvi g;

void dfsl(int v, int p, int l, vi & dist) {
    dist[v] = l;
    for(auto u : g[v]) {
        if(u!=p) dfsl(u, v, l+1, dist);
    }
}
vi drop;
void dfsd(int v, int p, vi & deep) {
    deep[v] = 0;
    for(auto u : g[v]) {
        if(u!=p) {
            dfsd(u, v, deep);
            deep[v] = max(deep[v], deep[u] + 1);
        }
    }
}
int can;
int len;
vi up;
void dfsup(int v, int p) {
    vi drops;
    for(auto u : g[v]) {
        if(u!=p) {
            drops.pb(1+drop[u]);
        }
    }
    drops.pb(up[v]);
    sort(all(drops));
    reverse(all(drops));
    if(drops.size() >= 3 && drops[2] >= len) can = 1;
    for(auto u : g[v]) {
        if(u!=p) {
            if(drop[u]+1 == drops[0]) up[u] = 1 + drops[1];
            else up[u] = 1 + drops[0];
            dfsup(u,v);
        }
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
    while(t--) {
        int n,a,b;
        scanf("%d %d %d", &n, &a,&b);
        a--; b--;
        
        g = vvi(n);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--;v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        vi da(n), db(n);
        dfsl(a,a,0,da);
        dfsl(b,b,0,db);
        vi p(da[b] + 1);
        len = da[b];
        forn(i,0,n) if(da[i] + db[i] == len) p[da[i]] = i;
        vi dl(n), dr(n);
        dfsd(p[1], p[0], dr);
        dfsd(p[len-1], p[len], dl);
        int l = 0;
        int r = len;
        int br = r - dl[p[0]];
        int bl = l + dr[p[len]];
        while(l<r) {
            if(l<bl) {
                l++;
                br = min(br, l - dl[p[l]] + len);
//                br = min(br, r - dl[p[l]] + l);
            }
            else if(r>br) {
                r--;
                bl = max(bl, r + dr[p[r]] - len);
//                bl = max(bl, l + dr[p[r]] - (len-r));
            }
            else break;
        }
        if(l<r) {
            printf("NO\n");
            continue;
        }
        drop = vi(n);
        dfsd(0, 0, drop);
        up = vi(n,0);
        can = 0;
        dfsup(0, 0);
        if(can) printf("YES\n");
        else printf("NO\n");
    }
    
}