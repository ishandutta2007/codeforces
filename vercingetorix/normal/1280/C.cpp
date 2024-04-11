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
vvpi g;
int n;
ll G= 0;
ll B=0;

int dfsg(int v, int p) {
    vi up(1,1);
    for(auto u : g[v]) {
        if(u.first == p) continue;
        int ret = dfsg(u.first, v);
        G += ll(ret)*u.second;
        up.pb(ret);
    }
    sort(all(up));
    int sum = 0;
    for(auto x : up) sum += x;
    return sum%2;
}

int dfsbad(int v, int p) {
    int st = 1;
    for(auto u : g[v]) {
        if(u.first == p) continue;
        int ret = dfsbad(u.first, v);
        B += ll(min(ret, 2*n-ret))*u.second;
        st += ret;
    }
    return st;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    char c[1000];
    while(t--) {
        G = 0;
        B = 0;
        scanf("%d",&n);
        g = vvpi(2*n);
        forn(i,0,2*n-1) {
            int u,v, t;
            scanf("%d %d %d", &u, &v, &t);
            u--; v--;
            g[u].pb(mp(v,t));
            g[v].pb(mp(u,t));
        }
        dfsg(0, 0);
        dfsbad(0, 0);
        printf("%lld %lld\n", G, B);
    }
    
}