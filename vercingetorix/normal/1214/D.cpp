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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d\n", &n, &m);
    vs a;
    char c[1234567];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    vvi rdr(n, vi(m, 0));
    rdr[0][0] = 1;
    vvi rul(n, vi(m, 0));
    rul[n-1][m-1] = 1;
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] == '#') continue;
        if(i>0) rdr[i][j] |= rdr[i-1][j];
        if(j>0) rdr[i][j] |= rdr[i][j-1];
    }
    for(int i = n-1; i>=0; i--) for(int j = m-1; j>=0; j--) {
        if(a[i][j] == '#') continue;
        if(i<n-1) rul[i][j] |= rul[i+1][j];
        if(j<m-1) rul[i][j] |= rul[i][j+1];
    }
    map<int, int> f;
    forn(i,0,n) forn(j,0,m) if(rul[i][j] && rdr[i][j]) f[i+j]++;
    int ans = 2;
    forn(i,1,n+m-2) ans = min(ans, f[i]);
    cout<<ans;
}