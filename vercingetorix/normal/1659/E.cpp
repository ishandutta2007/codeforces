#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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


const int A = 100500;
class dsu {
public:
    int parent[A];
    int rk[A];
    int win[A];
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
};

dsu st[30];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(b,0,30) forn(i,0,n) st[b].make_set(i);
    vi good(n, 0);
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        forn(b,0,30) if(w & (1<<b)) {
            st[b].union_sets(u, v);
        }
        if(w%2 == 0) {
            good[u] = 1;
            good[v] = 1;
        }
    }
    dsu great;
    forn(i,0,n+1) great.make_set(i);
    forn(i,0,n) if(good[i]) {
        forn(b,0,30) st[b].win[st[b].find_set(i)] = 1;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        int z = 0;
        forn(b,0,30) if(st[b].find_set(u) == st[b].find_set(v)) z = 1;
        if(z) printf("0\n");
        else{
            int o = 0;
            forn(b,1,30) if(st[b].win[st[b].find_set(u)]) o = 1;
            printf("%d\n", 2-o);
//            printf("-1\n");
        }
    }
    
    
}