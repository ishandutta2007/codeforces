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

const long long mod = 998244353 ;
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
const int A = 1502;
const int B = A*(A-1)/2 + 1;
vpi de[B];

int ans[A+1];
int parent[B];
int rk[B];
int st[B];
int e[B];
int good[B];
int bg[2];
bitset<A> in[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
    st[v] = 1;
    e[v] = 0;
    bg[0]++;
    in[v][v] = 1;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

vector<bitset<A>> g;

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
        bg[good[a]]--;
        bg[good[b]]--;
        st[a] += st[b];
        e[a] += e[b]+1;
        in[a] |= in[b];
        if(st[a]*st[a] == e[a]) good[a] = 1;
        else good[a] = 0;
        bg[good[a]]++;
        if(good[a]) g.pb(in[a]);
        
    }
    else {
        bg[good[a]]--;
        e[a]++;
        if(st[a]*st[a] == e[a]) good[a] = 1;
        else good[a] = 0;
        bg[good[a]]++;
        if(good[a]) g.pb(in[a]);
    }
}

vvi ch;
vi par;

vvll d;
int ls[2*A];

void dfs(int v) {
    if(ch[v].empty()) {
        ls[v] = 1;
        d[v] = vll({0,1});
        return;
    }
    int big = -1;
    for(auto u : ch[v]) {
        dfs(u);
        ls[v] += ls[u];
        if(big == -1 || ls[big] < ls[u]) big = u;
    }
    swap(d[v], d[big]);
    for(auto u : ch[v]) {
        if(u==big) continue;
        forn(i,0,d[u].size()) d[v].pb(0);
        for(int i = d[v].size() - 1; i>= 1; i--) {
            d[v][i] = 0;
            forn(j,1,d[u].size()) {
                if(i>j) d[v][i] = (d[v][i] + d[v][i-j]*d[u][j])%mod;
            }
        }
    }
    d[v][1] = 1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    forn(i,0,n) make_set(i);
    vvi a(n, vi(n,0));
    forn(i,0,n) forn(j,0,n) {
        scanf("%d", &a[i][j]);
        de[a[i][j]].pb(mp(i,j));
    }
    forn(i,0,A*(A-1)/2+1) {
        if(de[i].empty()) continue;
        for(auto x : de[i]) union_sets(x.first, x.second);
        if(bg[0] == 0) ans[bg[1]]++;
    }
//    for(auto x : g) {
//        forn(i,0,n) if(x[i]) printf("%d ", i+1);
//        printf("\n");
//    }
    reverse(all(g));
    int m = g.size();
    par.resize(m);
    ch.resize(m);
    forn(i,1,m) {
        for(int j = i-1; j>=0; j--) {
            if((g[j] | g[i]) == g[j]) {
                par[i] = j;
                ch[j].pb(i);
                break;
            }
        }
    }
    d.resize(m);
    dfs(0);
    forn(i,1,n+1) printf("%lld ", d[0][i]);
//    forn(i,1,n+1) printf("%d ", ans[i]);
    
    
}