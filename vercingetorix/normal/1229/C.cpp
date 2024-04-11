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
const int A = 100500;
vi in[A];
int sum[A];
int sums[A];
vi bn[A];
int last[A];
int isbig[A];
vvi g;
ll ans = 0;

//void update(int v) {
//    for(auto u : bn[v]) {
//        if(last[u] > last[v]) {
//            auto it = in[v].lower_bound(mp(u, 0));
//            if(it!=in[v].end() && it->first == u) {
//                sum[v] -= it->second;
//                sums[v] -= g[u].size();
//                in[v].erase(it);
//            }
//            sums[v] += g[u].size();
//            sum[v] += in[u].size();
//            in[v].insert(mp(u, (int)in[u].size()));
//        }
//    }
//}

int s[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    int m;
    read(m);
    g.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i,0,n) s[i] = g[i].size();
    forn(i,0,n) last[i] = i;
    forn(v,0,n) {
        int indeg = 0;
        for(auto u : g[v]) {
            if(u > v) indeg++;
        }
        for(auto u : g[v]) {
            if(u < v) {
                in[u].pb(v);
            }
        }
    }
    const int A = 320;
    forn(i,0,n) if(g[i].size() > A) isbig[i] = 1;
//    forn(v,0,n) for(auto u : g[v]) if(isbig[u]) bn[v].pb(u);
//    forn(v,0,n) for(auto x : in[v]) sum[v] += x.second;
//    forn(v,0,n) for(auto x : in[v]) sums[v] += g[x.first].size();
//    forn(i,0,n) ans += sum[i];
    forn(i,0,n) {
        ll k = in[i].size();
        ans += k*(s[i]-k);
    }
    printf("%lld\n", ans);
    int q;
    scanf("%d", &q);
    forn(ia,0,q) {
        int x;
        scanf("%d", &x);
        x--;
        for(auto v : in[x]) {
            ll k = in[v].size();
            ans -= k*(s[v]-k);
            k++;
            ans += k*(s[v]-k);
            in[v].pb(x);
        }
        ll k = in[x].size();
        ans -= k*(s[x] - k);
        in[x].clear();
//        x--;
//        update(x);
//        ans -= sum[x];
//        ans -= in[x].size() * (g[x].size() - in[x].size());
//        ans += sums[x] - in[x].size() - sum[x];
//        last[x] = n+ia;
//        if(isbig[x]) {
//            for(auto u : bn[x]) {
//                auto it = in[u].lower_bound(mp(x, 0));
//                if(it!=in[u].end() && it->first == x) {
//                    sum[u] -= it->second;
//                    sums[u] -= g[u].size();
//                    in[u].erase(it);
//                }
//                sums[u] += g[x].size();
//                in[u].insert(mp(x, 0));
//            }
//        }
//        else {
//            for(auto u : g[x]) {
//                auto it = in[u].lower_bound(mp(x, 0));
//                if(it!=in[u].end() && it->first == x) {
//                    sum[u] -= it->second;
//                    sums[u] -= g[u].size();
//                    in[u].erase(it);
//                }
//                sums[u] += g[x].size();
//                in[u].insert(mp(x, 0));
//            }
//        }
//        sum[x] = 0;
//        sums[x] = 0;
//        in[x].clear();
        printf("%lld\n", ans);
    }
    
}