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
//vvpi g;
const int A = 4000002;
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

vector<pair<int, bool>> g[4000002];
int n;
void add(int u, int v, int w) {
    g[u].pb(mp(v,w));
    g[v].pb(mp(u,w));
    union_sets(u, v);
}

int to(int i, int j) {
    return i*n+j;
}
vi col;
int can = 1;

void dfs(int v, int c) {
    col[v] = c;
    for(auto u : g[v]) {
        if(col[u.first] != -1) {if((col[u.first]^c) != u.second) can = 0;}
        else dfs(u.first,c^u.second);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d\n", &n);
    if(n%2==1) {
        printf("NONE\n");
        exit(0);
    }
//    g.resize(n*n+2);
    col = vi(n*n+2, -1);
    forn(i,0,n*n) make_set(i);
    int z = n*n;
    int o = n*n+1;
//    g[z].pb(mp(o,1));
//    g[o].pb(mp(z,1));
    for(int i = 0; i < n; i+=2) {
        add(to(i,0), to(i+1,0), 0);
        add(to(i,n-1), to(i+1,n-1), 0);
        add(to(0,i), to(0,i+1), 0);
        add(to(n-1,i), to(n-1,i+1), 0);
    }
    forn(i,0,n-1) forn(j,0,n-1) if((i+j)%2==1) add(to(i,j),to(i+1,j+1),1);
    forn(i,1,n) forn(j,0,n-1) if((i+j)%2==0) add(to(i,j),to(i-1,j+1),1);
    char a[2050];
    forn(i,0,n*n) if(col[i] == -1) dfs(i, 0);
    vi fix(n*n,-1);
    
    forn(i,0,n) {
        scanf("%s", a);
        forn(j,0,n) {
            if(a[j] != '.') {
                int v = find_set(to(i,j));
                int ncol = 0;
                if(a[j]=='S') ncol = 1;
                int sv = col[to(i,j)]^ncol;
                if(fix[v] == -1) fix[v] = sv;
                else if(fix[v] != sv) can = 0;
            }
        }
    }
    string uncol = "GS";
    if(can == 0) printf("NONE\n");
    else {
        forn(i,0,n*n) {
            if(find_set(i) == i && fix[i] == -1) {
                printf("MULTIPLE\n");
                exit(0);
            }
        }
        printf("UNIQUE\n");
        forn(i,0,n) {
            string cur(n,'.');
            forn(j,0,n) {
                cur[j] = uncol[col[to(i,j)]^fix[find_set(to(i,j))]];
            }
            printf("%s\n", cur.c_str());
        }
    }
}