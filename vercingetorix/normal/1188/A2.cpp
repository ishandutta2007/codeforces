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
vector<set<pi>> g;

int go(int v, int p) {
    if(g[v].size() == 1) return v;
    auto it = g[v].begin();
    if(it->first == p) it++;
    return go(it->first, v);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c);
        u--; v--;
        g[u].insert(mp(v,c));
        g[v].insert(mp(u,c));
    }
    vi skip(n,0);
    forn(i,0,n) {
        forn(v,0,n) {
            if(skip[v]) continue;
            if(g[v].size() == 2) {
                auto it = g[v].begin();
                pi x = *it;
                it++;
                pi y = *it;
                if(x.second != y.second) {
                    cout<<"NO";
                    exit(0);
                }
                g[v].clear();
                g[x.first].erase(mp(v, x.second));
                g[y.first].erase(mp(v, y.second));
                g[x.first].insert(mp(y.first, x.second));
                g[y.first].insert(mp(x.first, x.second));
            }
        }
    }
    vector<pair<pi, int>> ans;
    forn(v,0,n) {
        if(skip[v]) continue;
        for(auto up : g[v]) {
            int u = up.first;
            if(u < v) continue;
            int v1 = v;
            int v2 = v;
            if(g[v].size() > 1) {
                auto it = g[v].begin();
                while(it->first == u) it++;
                v1 = it->first;
                it++;
                while(it->first == u) it++;
                v2 = it->first;
                v1 = go(v1,v);
                v2 = go(v2,v);
            }
            int u1 = u;
            int u2 = u;
            if(g[u].size() > 1) {
                auto it = g[u].begin();
                while(it->first == v) it++;
                u1 = it->first;
                it++;
                while(it->first == v) it++;
                u2 = it->first;
                u1 = go(u1,u);
                u2 = go(u2,u);
            }
            int c = up.second;
            if(c!= 0) {
                ans.pb(mp(mp(u1,v1), c/2));
                ans.pb(mp(mp(u2,v2), c/2));
                if(u1!=u2) ans.pb(mp(mp(u1,u2), -c/2));
                if(v1!=v2) ans.pb(mp(mp(v1,v2), -c/2));
            }
        }
    }
//    cout<<"YES\n";
    printf("YES\n");
    printf("%d\n", (int)ans.size());
    for(auto x : ans) printf("%d %d %d\n", x.first.first+1, x.first.second+1, x.second);
    
    
}