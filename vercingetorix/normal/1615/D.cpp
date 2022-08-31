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

const int A = 200500;
int col[A];
vpi g[A];

int odd(int m) {
    return __builtin_popcount(m)%2;
}

int bad;
void dfs(int v) {
    for(auto u : g[v]) {
        if(col[u.first]!=-1) {
            if((col[u.first]^u.second)!=col[v]) bad = 1;
        }
        else {
            col[u.first] = col[v]^u.second;
            dfs(u.first);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d", &n, &m);
        vpi e(n-1);
        vi val(n-1);
        forn(i,0,n-1) {
            scanf("%d %d %d", &e[i].first, &e[i].second, &val[i]);
            e[i].first--;
            e[i].second--;
            if(val[i]!=-1) {
                g[e[i].first].pb(mp(e[i].second, odd(val[i])));
                g[e[i].second].pb(mp(e[i].first, odd(val[i])));
            }
        }
        forn(i,0,m) {
            int u,v;
            int p;
            scanf("%d %d %d", &u, &v, &p);
            u--; v--;
            g[u].pb(mp(v,p));
            g[v].pb(mp(u,p));
        }
        forn(i,0,n) col[i] = -1;
        bad = 0;
        forn(i,0,n) if(col[i] == -1) {
            col[i] = 0;
            dfs(i);
        }
        if(bad) printf("NO\n");
        else {
            printf("YES\n");
            forn(i,0,n-1) {
                if(val[i] != -1) printf("%d %d %d\n", e[i].first+1, e[i].second+1,val[i]);
                else printf("%d %d %d\n", e[i].first+1, e[i].second+1,col[e[i].first]^col[e[i].second]);
            }
        }
        forn(i,0,n) g[i].clear();
    }
    
    
}