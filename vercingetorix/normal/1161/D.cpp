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

const long long mod = 998244353 ;
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
const int A = 3003;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

vi col;
vvpi g;
int can;
void dfs(int v, int cc) {
    col[v] = cc;
    for(auto u : g[v]) {
        if(col[u.first] != -1) {
            if((col[u.first]^col[v]) != u.second) can = 0;
        }
        else dfs(u.first, cc^u.second);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[1050];
    scanf("%s", c);
    string s(c);
    reverse(all(s));
    int n = s.size();
    ll ans = 0;
    
    forn(k,1,n) {
        forn(i,0,n) make_set(i);
        forn(i,0,k) make_set(n+i);
        int z = n+k;
        int o = n+k+1;
        make_set(z);
        make_set(o);
        int N = n+k+2;
        col = vi(N, -1);
        g = vvpi(N);
        forn(i,0,n) union_sets(i, n-1-i);
        forn(i,0,k) union_sets(n+i, n+k-1-i);
        union_sets(n, o);
        forn(i,k,n) {
            if(s[i] == '0') union_sets(i, z);
            else if(s[i] =='1') union_sets(i, o);
        }
        forn(i,0,k) {
            int u = find_set(i);
            int v = find_set(n+i);
            if(s[i] == '0') {
                g[u].pb(mp(v, 0));
                g[v].pb(mp(u, 0));
            }
            else if(s[i] == '1'){
                g[u].pb(mp(v, 1));
                g[v].pb(mp(u, 1));
            }
        }
        can = 1;
        int comps = 0;
        ll val = 1;
        z = find_set(z);
        o = find_set(o);
        if(z == o) can = 0;
        col[z] = 0;
        col[o] = 1;
        dfs(z, 0);
        dfs(o, 1);
        forn(i,0,N) if(find_set(i) == i && col[i] == -1) {
            comps++;
            val = val*2;
            if(val >= mod) val -= mod;
            dfs(i, 0);
        }
        if(can) ans= (ans + val) % mod;
        
    }
    cout<<ans;
}