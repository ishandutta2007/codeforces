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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vvi g(n);
    vvi grev(n);
    forn(i,0,m)  {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        grev[v].pb(u);
    }
    const int  INF = 1e9;
    vi dto(n,INF);
    int k;
    scanf("%d", &k);
    readv(p,k);
    forn(i,0,k) p[i]--;
    int t = p.back();
    dto[t] = 0;
    deque<int> q;
    q.pb(t);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        for(auto u : grev[v]) if(dto[u]==INF){
            dto[u] = dto[v] + 1;
            q.pb(u);
        }
    }
    int mn = 0;
    int mx = 0;
    forn(i,0,k-1) {
        if(dto[p[i+1]] != dto[p[i]] - 1) mn++;
        int v = p[i];
        for(auto u : g[v]) if(u!=p[i+1] && dto[u] == dto[v] -1) {
            mx++;
            break;
        }
    }
    printf("%d %d", mn, mx);
    
}