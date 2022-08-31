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

ll d[20][4][4][11][11];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,4) forn(j,0,4) if(i!=j) d[1][i][j][0][0] = 1;
    int n,t;
    scanf("%d %d", &n, &t);
    forn(cur,2,n) {
        forn(p1,0,4) forn(p2,0,4) forn(p,0,4) forn(x,0,11) forn(y,0,11) {
            if(d[cur-1][p1][p2][x][y] == 0) continue;
            if(p == p2) continue;
            if(p2 < min(p1,p)) d[cur][p2][p][x][y+1] += d[cur-1][p1][p2][x][y];
            else if(p2 > max(p1,p)) d[cur][p2][p][x+1][y] += d[cur-1][p1][p2][x][y];
            else d[cur][p2][p][x][y] += d[cur-1][p1][p2][x][y];
        }
    }
    ll ans = 0;
    forn(x,0,4) forn(y,0,4) ans += d[n-1][x][y][t][t-1];
    cout<<ans;
    
}