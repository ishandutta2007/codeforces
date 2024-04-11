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
vi col;
vll a;
int bip;

void dfs(int v, int c) {
    col[v] = c;
    for(auto u : g[v]) {
        if(col[u] != -1) {
            if(col[u] + c != 1) bip = 0;
        }
        else {
            dfs(u, 1-c);
            a[v] -= a[u];
            a[u] = 0;
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
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        col = vi(n, -1);
        g = vvi(n);
        readv(v,n);
        readv(gt,n);
        a.resize(n);
        forn(i,0,n) a[i] = gt[i]-v[i];
        ll sum = 0;
        forn(i,0,n) sum+=a[i];
        
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        if(abs(sum)%2!=0) {
            printf("NO\n");
            continue;
        }
        bip = 1;
        dfs(0,0);
        if(bip==0 || a[0] == 0) {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    
}