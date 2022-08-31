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
set<int> g[400500];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,k;
        scanf("%d %d", &n, &k);
        forn(i,0,n) g[i].clear();
//        g.resize(n);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].insert(v);
            g[v].insert(u);
        }
        vi cur;
        forn(i,0,n) if(g[i].size() == 1 || g[i].size() == 0) cur.pb(i);
        int ans = n;
        while(k>0 && !cur.empty()) {
            vi was = cur;
            cur.clear();
            for(auto u : was) {
                ans--;
                if(g[u].empty()) continue;
                int v = *g[u].begin();
                g[v].erase(u);
                if(g[v].size() == 1) cur.pb(v);
            }
            k--;
        }
//        vi d(n, -1);
//        deque<int> q;
//        forn(i,0,n) if(g[i].size() == 1) {
//            q.pb(i);
//            d[i] = 0;
//        }
//        while(!q.empty()) {
//            int v = q.front();
//            q.pop_front();
//            for(auto u : g[v]) if(d[u] == -1) {
//                d[u] = d[v] + 1;
//                q.pb(u);
//            }
//        }
//        int ans = 0;
//        forn(i,0,n) if(d[i] >= k) ans++;
        printf("%d\n", ans);
    }
    
    
}