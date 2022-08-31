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
const int B = 310;

int d[A][B];
vi pos[A];
const int INF = 1e9;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,s,e;
    scanf("%d %d %d %d", &n, &m, &s, &e);
    readv(a,n);
    readv(b,m);
    forn(i,0,m) pos[b[i]].pb(i+1);
    forn(i,0,n+1) forn(j,1,B) d[i][j] = INF;
    d[0][0] = 0;
    int ans = 0;
    forn(i,1,n+1) forn(k,1,B) {
        d[i][k] = d[i-1][k];
        if(d[i-1][k-1] < INF) {
            int r = d[i-1][k-1];
            int  v = a[i-1];
            auto it = lower_bound(all(pos[v]), r+1);
            if(it == pos[v].end()) continue;
            d[i][k] = min(d[i][k], *it);
        }
        if(k*e + i + d[i][k] <= s) ans = max(ans, k);
    }
    cout<<ans;
    
    
    
}