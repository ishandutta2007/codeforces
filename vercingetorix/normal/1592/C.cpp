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
vvi g;
int x;
vi stx;
vi st;
vi a;
int can = 0;
void dfs(int v, int p) {
    st[v] = a[v];
    for(auto u : g[v]) {
        if(u==p) continue;
        dfs(u, v);
        st[v] ^= st[u];
        stx[v] += stx[u];
    }
    if(st[v] == x && stx[v] == 0) stx[v] = 1;
    if(stx[v] > 1) can = 1;
    if(st[v] == 0 && stx[v] > 0) can = 1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    while(t-- ) {
        int n,k;
        scanf("%d %d\n", &n, &k);
//        readv(a,n);
        a.resize(n);
        forn(i,0,n) scanf("%d", &a[i]);
        x = 0;
        forn(i,0,n) x^=a[i];
        g.clear();
        g.resize(n);
        st = vi(n,0);
        stx = vi(n,0);
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        if(x == 0) {
            printf("YES\n");
            continue;
        }
        if(k == 2) {
            printf("NO\n");
            continue;
        }
        can = 0;
        dfs(0,0);
        if(can) printf("YES\n");
        else printf("NO\n");
        
        
        
    }
    
    
}