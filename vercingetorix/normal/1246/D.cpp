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
vi par;
vvi ch;
vi st;
vi d;
vi md;

int dfsst(int v, int curd) {
    st[v] = 1;
    d[v] = curd;
    md[v] = curd;
    for(auto u : ch[v]) {
        st[v] += dfsst(u, curd+1);
        md[v] = max(md[v], md[u]);
    }
    return st[v];
}

int fall;
vi ans;
vi ord;
void dfs(int v) {
    ord.pb(v);
    vpi q;
    for(auto u : ch[v]) {
        q.pb(mp(md[u], u));
    }
    srt(q);
    for(auto x: q) {
        while(fall > 0) {
            ans.pb(x.second);
            fall--;
        }
        dfs(x.second);
    }
    fall++;
    srt(q);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    ch.resize(n);
    par.resize(n);
    st.resize(n);
    d.resize(n);
    md.resize(n);
    par[0] = 0;
    forn(i,1,n) {
        int x;
        scanf("%d", &x);
        par[i] = x;
        ch[x].pb(i);
    }
    fall = 0;
    dfsst(0,0);
    dfs(0);
//    cout<<1;
    forn(i,0,n) printf("%d ", ord[i]);
    printf("\n");
    printf("%d\n" ,ans.size());
    for(auto x : ans) printf("%d ", x);
    printf("\n");
    
    
    
}