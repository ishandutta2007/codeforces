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
const int INF = 1000000;
//const int INF = 30;
int parent[INF+1];
vi ls[INF+1];
void make_set (int v) {
    parent[v] = v;
    ls[v] = vi(1,v);
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if(ls[a] < ls[b]) swap(a,b);
    for(auto u : ls[b]) {
        parent[u] = a;
        ls[a].pb(u);
    }
    ls[b].clear();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q,s,d;
    scanf("%d %d %d %d", &n, &q,&s,&d);
    readv(a,n);
    s--;
    set<int> x;
    forn(i,0,n) x.insert(a[i]);
    
    vi cost(INF+1, INF);
    forn(i,0,INF+1) make_set(i);
    cost[a[s]] = 0;
    vector<pair<int, pi>> g;
    forn(i,0,n) {
        int v = a[i];
        forn(j,0,2) {
            int u = a[i];
            if(j == 0) u-=d;
            else u +=d;
            auto it = x.lower_bound(u);
            if(it!=x.begin()) {
                it--;
                int f = *it;
                it++;
                g.pb(mp(u-f, mp(v,f)));
            }
            if(it!=x.end()) {
                int f = *it;
                g.pb(mp(f-u, mp(v,f)));
                if(*it == u) {
                    it++;
                    if(it!=x.end()) {
                        int f = *it;
                        g.pb(mp(f-u, mp(v,f)));
                    }
                }
            }
        }
    }
    srt(g);
    for(auto x : g) {
        int u = x.second.first;
        int v = x.second.second;
        u = find_set(u);
        v = find_set(v);
        if(u!=v) {
            if(v == find_set(a[s])) {
                swap(u,v);
            }
            if(u == find_set(a[s])) {
                for(auto y : ls[v]) cost[y] = x.first;
            }
            union_sets(u, v);
        }
    }
    while(q--) {
        int i,k;
        scanf("%d %d", &i, &k);
        i--;
        if(k>=cost[a[i]]) printf("Yes\n");
        else printf("No\n");
    }
    
    
}