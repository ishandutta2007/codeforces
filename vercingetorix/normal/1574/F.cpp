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
const int A = 300500;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    vvi g(k), gr(k);
    forn(i,0,k) make_set(i);
    vi bad(k,0);
    forn(afi,0,n) {
        int c;
        scanf("%d", &c);
        readv(a,c);
        forn(i,0,c) a[i]--;
        forn(i,0,c-1) {
            g[a[i]].pb(a[i+1]);
            gr[a[i+1]].pb(a[i]);
            union_sets(a[i], a[i+1]);
        }
        
    }
    forn(i,0,k) {
        srt(g[i]);
        srt(gr[i]);
        if(g[i].size() > 1 && g[i][0] == g[i].back()) g[i].resize(1);
        if(gr[i].size() > 1 && gr[i][0] == gr[i].back()) gr[i].resize(1);
        if(g[i].size() > 1 || gr[i].size() > 1) {
            bad[find_set(i)] = 1;
//            printf("0");
//            exit(0);
        }
    }
    vi l;
    vi vis(k,0);
    forn(i,0,k) {
        if(!vis[i]) {
            int cur = 1;
            int m = i;
            vis[m] = 0;
            while(g[m].size() > 0) {
                m = g[m][0];
                if(vis[m]) {
                    bad[find_set(i)] = 1;
                    break;
//                    cout<<0;
//                    exit(0);
                }
                vis[m] = 1;
                cur++;
            }
            m = i;
            while(gr[m].size() > 0) {
                m = gr[m][0];
                if(vis[m]) {
                    bad[find_set(i)] = 1;
                    break;
                }
                vis[m] = 1;
                cur++;
            }
            if(bad[find_set(i)] == 0) l.pb(cur);
        }
    }
    map<int, int> mstep;
    for(auto x : l) mstep[x]++;
    vpi step;
    for(auto x : mstep) step.pb(x);
    vll d(m+1, 0);
    d[0] = 1;
    forn(i,1,m+1) {
        for(auto x : step) {
            if(i >= x.first) {
                d[i] += d[i-x.first] * x.second;
            }
        }
        d[i] %= mod;
    }
    cout<<d[m];
//    cout<<l.size();
    
    
}