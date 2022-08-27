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

int d[5001][5001];
//ll pred[5001][5001];
vvi g;
int n,k;
ll pred[2][5001];

void update_pred(int i, int to) {
//    vll pred(k);
    pred[to][0] = d[i][0];
    forn(j,1,k) pred[to][j] = (pred[to][j-1] + d[i][j]) % mod;
}



void dfs(int v, int p) {
    d[v][0] = 1;
    for(auto u : g[v]) {
        if(u == p) continue;
        dfs(u, v);
        vll nd(k, 0);
        update_pred(u, 1);
        update_pred(v, 0);
        forn(nl,0,k) {
            nd[nl] = d[v][nl] * pred[1][k-1] % mod;
            if(nl > 0) nd[nl] += d[u][nl-1] * pred[0][min(nl-1, k-nl-1)];
            if(nl > 0 && nl < k-1) nd[nl] += d[v][nl] * pred[1][min(nl - 1, k - nl - 2)];
            nd[nl] %= mod;
        }
        forn(i,0,k) d[v][i] = nd[i];
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &k);
    k++;
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0);
    if(k == 1) {
        ll ans = 1;
        cout<<ans;
        exit(0);
    }
    update_pred(0, 0);
    cout<<pred[0][k-1];
    
}