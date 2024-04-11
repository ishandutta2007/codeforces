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
const int A = 500500;
int parent[A];
int rk[A];
int sat[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
    sat[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    int nsat = sat[a]|sat[b];
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
        sat[find_set(a)] = nsat;
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,m) make_set(i);
    vi ans;
    forn(i,0,n) {
        int k;
        int u;
        scanf("%d %d", &k, &u);
        u--;
        if(k==1) {
            u = find_set(u);
            if(sat[u] == 0) {
                sat[u] = 1;
                ans.pb(i+1);
            }
        }
        else {
            int v;
            scanf("%d", &v);
            v--;
            u = find_set(u);
            v = find_set(v);
            if (u!=v && (sat[u]&sat[v]) == 0) {
                ans.pb(i+1);
                union_sets(u, v);
            }
        }
    }
    ll d2 = 1;
    forn(i,0,ans.size()) d2 =d2*2%mod;
    printf("%lld %d\n", d2, ans.size());
    for(auto x : ans) printf("%d ", x);
    printf("\n");
    
    
    
}