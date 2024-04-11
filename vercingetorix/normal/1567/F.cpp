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

const int A = 500*500;
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
    int n,m;
    scanf("%d %d\n", &n, &m);
    vs a;
    char c[1000];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    vpi dir;
    dir.pb(mp(1,0)); dir.pb(mp(-1,0));
    dir.pb(mp(0,1)); dir.pb(mp(0,-1));
    dir.pb(mp(1,-1)); dir.pb(mp(-1,1));
    dir.pb(mp(1,1)); dir.pb(mp(-1,-1));
    
    forn(i,0,n) forn(j,0,m) make_set(i*m+j);
    forn(i,0,n) {
        union_sets(0, i*m);
        union_sets(0, i*m + m-1);
    }
    forn(j,0,m) {
        union_sets(0, j);
        union_sets(0, (n-1)*m + j);
    }
    forn(i,1,n-1) forn(j,1,m-1) {
        if(a[i][j] == '.') {
            for(auto x : dir) {
                int i2 = i+x.first;
                int j2= j+x.second;
                if(a[i2][j2] == '.') union_sets(i*m+j, i2*m+j2);
            }
        }
    }
    vi ver;
    vvi g(n*m);
    vvi w(n*m);
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] == '.') {
            if(find_set(i*m+j) == i*m+j) ver.pb(i*m+j);
            w[find_set(i*m+j)].pb(i*m+j);
        }
    }
    forn(i,0,n) forn(j,0,m-2) if(a[i][j] == '.' && a[i][j+2] == '.') {
        int u = find_set(i*m+j);
        int v = find_set(i*m+j+2);
        if(u!=v) {
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    forn(i,0,n-2) forn(j,0,m) if(a[i][j] == '.' && a[i+2][j] == '.') {
        int u = find_set(i*m+j);
        int v = find_set((i+2)*m+j);
        if(u!=v) {
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    
    vector<int> part (n*m, -1);
    int ok = 1;
    vector<int> q (n*m);
    for(auto st : ver)
        if (part[st] == -1) {
            int h=0, t=0;
            q[t++] = st;
            part[st] = 0;
            while (h<t) {
                int v = q[h++];
                for (size_t i=0; i<g[v].size(); ++i) {
                    int to = g[v][i];
                    if (part[to] == -1) {
                        part[to] = 1-part[v];
                        q[t++] = to;
                    }
                    else
                        ok &= (part[to] != part[v]);
                }
            }
        }
    vvi ans(n, vi(m, 0));
    forn(i,0,n) forn(j,0,m) if(a[i][j] == '.') {
        ans[i][j] = 1+3*(i%2);
    }
    for(auto v : ver) {
        if(part[v] == 1) for(auto x : w[v]) {
            int i = x/m;
            int j = x%m;
            ans[i][j] = 5-ans[i][j];
        }
    }
    int bad = 0;
    forn(i,0,n) forn(j,0,m) if(a[i][j] == 'X') {
        forn(uka,0,4) {
            int i2 = i + dir[uka].first;
            int j2 = j + dir[uka].second;
            if(a[i2][j2] == '.') ans[i][j] += ans[i2][j2];
        }
        if(ans[i][j] % 5 != 0) {
            bad = 1;
        }
    }
    if(bad) printf("NO\n");
    else {
        printf("YES\n");
        forn(i,0,n) {
            forn(j,0,m)printf("%d ", ans[i][j]);
            printf("\n");
        }
    }
    
    
}