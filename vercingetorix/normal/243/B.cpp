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
const int A = 100400;
vi g[A];
int nb[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,h,t;
    scanf("%d %d %d %d", &n, &m, &h, &t);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(v,0,n) if(g[v].size() >= h+1) {
        for(auto u : g[v]) if(g[u].size() >= t+1) {
            auto win = [&]() {
                printf("YES\n");
                printf("%d %d\n", v+1, u+1);
                for(auto x : g[u]) nb[x]++;
                for(auto x : g[v]) nb[x]++;
                nb[u] = 0;
                nb[v] = 0;
                for(auto x : g[v]) if(nb[x] == 1 && h > 0) {
                    printf("%d ", x+1);
                    nb[x] = 0;
                    h--;
                }
                for(auto x : g[v]) if(nb[x] > 0 && h > 0) {
                    printf("%d ", x+1);
                    nb[x] = 0;
                    h--;
                }
                printf("\n");
                for(auto x : g[u]) if(nb[x] == 1 && t > 0) {
                    printf("%d ", x+1);
                    nb[x] = 0;
                    t--;
                }
                for(auto x : g[u]) if(nb[x] >0 && t > 0) {
                    printf("%d ", x+1);
                    nb[x] = 0;
                    t--;
                }
                printf("\n");
                exit(0);
            };
            if(g[v].size() >=  h+t+1 || g[u].size() >= h+t+1) win();
            for(auto x : g[v]) nb[x] = 1;
            int dec = 0;
            for(auto x : g[u]) if(nb[x]) dec++;
            for(auto x : g[v]) nb[x] = 0;
            if(g[v].size() + g[u].size() >= h+t+2+dec) win();
        }
    }
    printf("NO\n");
    
    
    
}