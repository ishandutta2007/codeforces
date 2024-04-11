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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        vvi a(2, vi(n));
        forn(i,0,2) forn(j,0,n) scanf("%d", &a[i][j]);
        a[0][0] = -1;
        const int INF = 2e9;
        vvi du(2, vi(n,INF));
        forn(r,0,2) {
            du[r][n-1] = max(a[r][n-1]+2,a[r^1][n-1]+1);
        }
        for(int i = n-2; i >= 0; i--) {
            int step = (n-1-i)*2+1;
            forn(r,0,2) du[r][i] = max({a[r][i] + step + 1, du[r][i+1] + 1, a[r^1][i] + 1});
        }
        vvi d = du;
        for(int i = n-2; i>=0; i--) {
            int step = (n-1-i)*2+1;
            forn(r,0,2) {
                d[r][i] = min(d[r][i], max({d[r^1][i+1], a[r][i] + step + 1, a[r^1][i] + step}));
            }
        }
        printf("%d\n", d[0][0]);
    }
    
    
}