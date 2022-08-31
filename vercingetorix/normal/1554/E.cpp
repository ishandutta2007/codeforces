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

const long long mod = 998244353;
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
vpi ord;
vector<set<int>> g;
vi deg;
void go(int v) {
    if(deg[v] == 1) {
        int to = *g[v].begin();
        ord.pb(mp(v, to));
        g[to].erase(v);
        g[v].erase(to);
        deg[to]--;
        deg[v]--;
        go(to);
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
    forn(afaf,0,t) {
        int n;
        read(n);
        g = vector<set<int>> (n);
        deg = vi(n,0);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].insert(v);
            g[v].insert(u);
            deg[u] ++;
            deg[v] ++;
        }
        ord = vpi();
        forn(i,0,n) go(i);
        vi ans(n+1, 0);
        ll lft = 1;
        forn(i,0,n-1) lft = lft*2%mod;
        for(int d = n-1; d >= 2; d--) {
            if((n-1)%d == 0) {
                vi val(n,0);
                for (auto x : ord) {
                    if(val[x.first] % d == 0) {
                        val[x.second]++;
                    }
                    else val[x.first]++;
                }
                int can = 1;
                forn(i,0,n) if(val[i] % d != 0) can = 0;
                for(int d2 = 2*d; d2<n; d2+=d) {
                    if(ans[d2] == 1) can = 0;
                }
                if(can == 1) {
                    ans[d] = 1;
                    lft = (lft + mod - 1) % mod;
                }
            }
        }
        ans[1] = lft;
        forn(i,1,n+1) {
            printf("%d", ans[i]);
            if (i!=n) printf(" ");
            else printf("\n");
        }
        
    }
    
}