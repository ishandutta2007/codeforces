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
vvi g;
vi ban;
const int A = 100500;
int st[A];
int sz;
int root;
char ans[A];

void dfsroot(int v, int p) {
    st[v] = 1;
    for(auto u : g[v]) {
        if(u == p || ban[u]) continue;
        dfsroot(u, v);
        st[v] += st[u];
    }
}

void dfsroot2(int v, int p) {
    root = v;
    for(auto u : g[v]) {
        if(u == p || ban[u]) continue;
        if(st[u]*2 >= sz) dfsroot2(u, v);
    }
}


void go(int v, char cur) {
//    cout<<v<<' '<<cur<<endl;
    dfsroot(v, v);
    sz = st[v];
    dfsroot2(v, v);
    ban[root] = 1;
    ans[root] = cur;
    int croot = root;
    for(auto u : g[croot]) {
        if(ban[u] == 0) {
            go(u, cur+1);
        }
    }
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
        int u,v;
        scanf("%d %d", &u, &v );
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    ban = vi(n,0);
    go(0,'A');
    forn(i,0,n) printf("%c ", ans[i]);
    
    
}