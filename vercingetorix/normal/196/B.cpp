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
const int A = 1510;
pi can[A][A];
const pi INF = mp(871348718, 1000000008);
int g[A][A];

pi operator+(pi & a, pi & b) {
    return mp(a.first+b.first, a.second+b.second);
}
int n,m;
bool valid(int x, int y) {
    x = (x%n+n)%n;
    y = (y%m+m)%m;
    return g[x][y];
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &m);
    forn(i,0,n) forn(j,0,m) can[i][j] = INF;
    vs a;
    char c[A];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    vpi q;
    vpi dir;
    forn(i,-1,2) forn(j,-1,2) if(i*j==0 && i+j!=0) dir.pb(mp(i,j));
    forn(i,0,n) {
        forn(j,0,m) {
            if(a[i][j] != '#') g[i][j] = 1;
            if(a[i][j] == 'S') q.pb(mp(i,j));
        }
    }
    can[q[0].first][q[0].second] = q[0];
    while(!q.empty()) {
        auto cur = q.back();
        q.pop_back();
        for(auto to : dir) {
            auto nx = cur+to;
            if(valid(nx.first, nx.second)) {
                int x = (nx.first%n+n)%n;
                int y = (nx.second%m+m)%m;
                if(can[x][y] == nx) continue;
                if(can[x][y] != INF) {
                    cout<<"Yes\n";
                    exit(0);
                }
                can[x][y] = nx;
                q.pb(nx);
            }
        }
    }
    cout<<"No\n";
    
}