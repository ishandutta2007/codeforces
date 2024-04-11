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
#include <array>
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
int n;
int col[A];
vi g[A];
int a[A];
ll ans = 0;
array<int, 2> tot;

void dfscol(int v, int p) {
    for(auto u : g[v]) {
        if(u==p) continue;
        col[u] = col[v]^1;
        dfscol(u,v);
    }
}



array<int, 2> dfs(int v, int p) {
    vector<array<int, 2>> q;
    array<int, 2> cur;
    cur[0] = 0;
    cur[1] = 0;
    for(auto u : g[v]) {
        if(u == p) continue;
        auto x = dfs(u, v);
        forn(it,0,2) cur[it] += x[it];
        q.pb(x);
    }
    cur[col[v]]++;
    array<int, 2> up = tot;
    forn(it,0,2) up[it] -= cur[it];
    q.pb(up);
    array<ll, 2> num;
    forn(it,0,2) num[it] = ll(tot[it])*(tot[it]-1)/2;
    for(auto x : q) {
        forn(it,0,2) {
            num[it] -= ll(x[it])*(x[it]-1)/2;
        }
    }
    forn(it,0,2) num[it]%=mod;
    ans = (ans + (mod + num[col[v]] - num[col[v]^1])*a[v])%mod;
    return cur;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d", &n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) {
        a[i] = (a[i]%mod+mod)%mod;
    }
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfscol(0, 0);
    forn(i,0,n) tot[col[i]]++;
    dfs(0, 0);
    ans*=2;
    forn(i,0,n) ans+=a[i];
    cout<<ans%mod;
    
}