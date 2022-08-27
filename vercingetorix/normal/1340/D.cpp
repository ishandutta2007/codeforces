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
vvi g;
vpi ans;
int val = 0;

void dfs(int v, int p) {
    int l = 0;
    int r = g[v].size()+1;
    if(v != 0) {
        int cl = g[v].size()+1;
        r = max(cl-1, val);
        l = r - cl + 1;
        if(val == r) {
            ans.pb(mp(v+1, l));
            val = l;
        }
    }
    for(auto u : g[v]) {
        if(u==p) continue;
        ans.pb(mp(u+1, ++val));
        dfs(u, v);
        if(val == r) {
            ans.pb(mp(v+1, l));
            val = l;
        }
    }
    if(v != 0) {
        ans.pb(mp(p+1, ++val));
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d", &n);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(n==1) {
        cout<<1<<endl;
        printf("1 0\n");
        exit(0);
    }
    ans.pb(mp(1,0));
    val = 0;
    dfs(0, 0);
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d %d\n", x.first, x.second);
    
    
}