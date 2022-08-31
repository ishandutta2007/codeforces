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
vvi g;
int n,m,k;
const int INF = 1e9;
vi bfs(int s) {
    vi ret(n,INF);
    ret[s] = 0;
    deque<int> q;
    q.pb(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        for(auto u : g[v]) {
            if(ret[u] ==INF) {
                ret[u] = ret[v]+1;
                q.pb(u);
            }
        }
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d", &n, &m, &k);
    readv(a,k);
    forn(i,0,k) a[i]--;
    g.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d",  &u,  &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi d0 = bfs(0);
    vi d1 = bfs(n-1);
    vpi e;
    int d = d0[n-1];
    forn(i,0,k) {
        int dl = d0[a[i]];
        int dr = d1[a[i]];
        e.pb(mp(d-dr, dl));
    }
    srt(e);
    int dec = n;
    forn(i,0,k-1) dec = min(dec, e[i+1].first - e[i].second - 1);
    dec = max(dec,0);
    cout<<d-dec;
    
}