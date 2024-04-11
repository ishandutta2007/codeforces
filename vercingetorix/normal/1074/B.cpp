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
const int A = 1001;
vi g[A];
int me[A];
int lee[A];

int ask(char c, int v) {
    printf("%c %d\n", c, v+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret-1;
}

void go(int v) {
    printf("C %d\n", v+1);
    fflush(stdout);
}

int dfs(int v, int p) {
    if(me[v]) return v;
    for(auto u : g[v]) {
        if(u == p) continue;
        int ret = dfs(u,v);
        if(ret != -1) return ret;
    }
    return -1;
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        forn(i,0,n) g[i].clear();
        forn(i,0,n) me[i] = 0;
        forn(i,0,n) lee[i] = 0;
        forn(i,0,n-1) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        int k1;
        int k2;
        read(k1);
        readv(x,k1);
        read(k2);
        readv(y,k2);
        for(auto v : x) me[v-1] = 1;
        for(auto v : y) lee[v-1] = 1;
        int root = ask('B', y[0]-1);
        if(me[root] == 1) {
            go(root);
            continue;
        }
        int hit = dfs(root, root);
        int u = ask('A', hit);
        if(lee[u]) {
            go(hit);
            continue;
        }
        printf("C -1\n");
        fflush(stdout);
        
    }
    
    
}