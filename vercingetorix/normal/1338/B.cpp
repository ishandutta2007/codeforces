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

vvi g;
vi d;
void go(int v, int p, int l) {
    d[v] = l;
    for(auto u:g[v]) {
        if(u!=p) go(u,v,l+1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    g = vvi(n);
    d.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vvi cnt(n);
    int mx = n-1;
    forn(i,0,n) {
        if(g[i].size() > 1) {
            int c1 = 0;
            for(auto u : g[i]) if(g[u].size() == 1) c1++;
            if(c1>0) mx -= (c1-1);
        }
    }
    go(0,0,0);
    vi can(2,0);
    int c2 = 0;
    forn(i,0,n) {
        if(g[i].size() == 1) {
            can[d[i]%2] ++;
        }
        else c2++;
    }
    int mn = 1;
    if(c2 == 1) mn =1;
    else if(can[0] > 0 && can[1] > 0) mn = 3;
    else mn = 1;
    cout<<mn<<' '<<mx;
}