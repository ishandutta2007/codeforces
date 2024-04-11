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
int n;
const int A = 100500;
vi g[A];
int st[A];

int root = -1;
int par[A];
void dfs1(int v, int p) {
    st[v] = 1;
    for(auto u : g[v]) {
        if(u==p) continue;
        par[u] = v;
        dfs1(u, v);
        st[v] += st[u];
    }
    if(root == -1 && st[v]*2>=n) root = v;
}

map<vi, int> code;
int num = 1;

int ucnt[A];
int d[A];


void dfs(int v, int p) {
    vi ch;
    for(auto u : g[v]) {
        if(u==p) continue;
        
        dfs(u,v);
        ch.pb(d[u]);
    }
    srt(ch);
    if(code.count(ch)) d[v] = code[ch];
    else {
        code[ch] = num;
        ucnt[num] = g[v].size() < 4;
        forn(i,0,ch.size()) if(i==0 || ch[i] != ch[i-1]) ucnt[num] += ucnt[ch[i]];
        d[v] = num++;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ucnt[0] = 1;
    code[vi()] = 0;
    read(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(0,0);
    if(st[root]*2 == n)  {
        dfs(root, par[root]);
        dfs(par[root], root);
        int ans = ucnt[d[root]];
        if(d[root] != d[par[root]]) ans += ucnt[d[par[root]]];
        cout<<ans;
    }
    else {
        dfs(root, root);
        cout<<ucnt[d[root]];
    }
    
    
    
}