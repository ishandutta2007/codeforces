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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        int n,k;
        scanf("%d %d", &n, &k);
        vvi g(n);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--;  v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        if(k==1) {
            printf("%d\n", n-1);
            continue;
        }
        vi del(n, 0);
        vi deg(n);
        forn(i,0,n) deg[i] = g[i].size();
        vvi lnb(n);
        forn(i,0,n) if(g[i].size() ==1) lnb[g[i][0]].pb(i);
        set<pi> q;
        forn(i,0,n) q.insert(mp(-lnb[i].size(), i));
        int ans = 0;
        while(1) {
            auto it = q.begin();
            if(-it->first<k) break;
            int v = it->second;
            q.erase(it);
            ans++;
            forn(i,0,k) {
                del[lnb[v].back()] = 1;
                lnb[v].pop_back();
                deg[v]--;
            }
            if(deg[v] == 1) {
                int pt = 0;
                while(del[g[v][pt]]) pt++;
                int u = g[v][pt];
                q.erase(mp(-lnb[u].size(), u));
                lnb[u].pb(v);
                q.insert(mp(-lnb[u].size(), u));
            }
            q.insert(mp(-lnb[v].size(), v));
        }
        printf("%d\n", ans);
    }
    
    
}