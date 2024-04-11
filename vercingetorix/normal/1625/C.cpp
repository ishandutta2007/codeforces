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

const int INF = 2e9;
int d[2][502][502];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,l,k;
    scanf("%d %d %d", &n, &l, &k);
    readv(pos, n);
    readv(a, n);
    pos.pb(l);
    a.pb(0);
    forn(z,0,2) forn(i,0,n) forn(j,0,k+1) d[z][i][j] = INF;
    d[0][0][0] = 0;
    forn(zw,0,n) {
        int z = zw&1;
        forn(i,0,n) forn(j,0,k+1) d[z^1][i][j] = INF;
    forn(i,0,zw+1) forn(j,0,k+1) {
        
        
        int len = pos[zw+1]-pos[zw];
        d[z^1][i][j+1] = min(d[z^1][i][j+1], d[z][i][j] + a[i] * len);
        d[z^1][zw][j] = min(d[z^1][zw][j], d[z][i][j] + a[zw] * len);
    }
    }
    int ans = INF;
    forn(i,0,n) forn(j,0,k+1) ans = min(ans, d[n&1][i][j]);
    cout<<ans;
    
}