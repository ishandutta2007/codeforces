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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
const int A = 100000;
int n,m;
int k,x;
vi nb[A];
ll d2[11][A];
ll d1[11][A];
ll d0[11][A];

void dfs(int v, int p) {
    d2[0][v] = m-k;
    d0[0][v] = k-1;
    d1[1][v] = 1;
    for(auto u : nb[v]) {
        if(u==p) continue;
        dfs(u,v);
        for(int num = x; num >= 0; num--) {
            forn(add,1,x-num+1) {
                d1[num+add][v] = (d1[num+add][v] + d1[num][v] * d0[add][u]) % mod;
                d0[num+add][v] = (d0[num+add][v] + d0[num][v] * (d0[add][u] + d1[add][u] + d2[add][u])) % mod;
                d2[num+add][v] = (d2[num+add][v] + d2[num][v] * (d0[add][u] + d2[add][u])) % mod;
            }
            d1[num][v] = (d1[num][v] * d0[0][u]) % mod;
            d0[num][v] = (d0[num][v] * (d0[0][u] + d1[0][u] + d2[0][u])) % mod;
            d2[num][v] = (d2[num][v] * (d0[0][u] + d2[0][u])) % mod;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n); read(m);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--; nb[u].pb(v); nb[v].pb(u);
    }
    read(k); read(x);
    dfs(0,-1);
    ll ans = 0;
    forn(i,0,x+1) ans += d1[i][0]+d0[i][0] + d2[i][0];
    cout<<ans%mod;
    
}