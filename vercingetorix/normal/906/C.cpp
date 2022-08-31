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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

vvi a(22, vi(22,0));
vi tk;
int n,m;

vi vis;
vi res;

void dfs(int v) {
    vis[v] = 1;
    res.pb(v);
    for(auto i : tk) if(a[v][i] && !vis[i]) dfs(i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n,&m);
//    vvi a(n, vi(n,0));
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--,v--;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    vi mask(n,0);
    forn(i,0,n) {
        a[i][i] = 1;
        forn(j,0,n) mask[i] += a[i][j]*(1<<j);
    }
    if(m == n*(n-1)/2) {
        cout<<0;
        return 0;
    }
    vi xx;
    vvi ya(23);
    forn(bit, 1, 1<<n) {
        int num = 0;
        forn(i,0,n) if(bit&(1<<i)) {
            num++;
        }
        ya[num].pb(bit);
    }
    forn(i,0,23) for(auto y : ya[i]) xx.pb(y);
//    sort(all(xx));
//    forn(bit, 1, 1<<n) {
    for(auto bit : xx) {
//        int bit = lul.second;
        tk.clear();
        int cover = 0;
        int num = 0;
        forn(i,0,n) if(bit&(1<<i)) {
            tk.pb(i);
            cover |= mask[i];
            num++;
        }
        if((cover+1) != (1<<n)) continue;
        vis = vi(n,1);
        for(auto x : tk) vis[x] = 0;
        res.clear();
        dfs(tk[0]);
        if(res.size() != num) continue;
        printf("%d\n", num);
        reverse(all(res));
        for(auto x : res) printf("%d ", x+1);
        break;
    }
    
    
}