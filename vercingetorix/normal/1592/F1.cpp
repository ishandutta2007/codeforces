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
    vvi a(n);
    char c[1000];
    forn(i,0,n) {
        scanf("%s", c);
        forn(j,0,m) {
            if(c[j] == 'W') a[i].pb(0);
            else a[i].pb(1);
        }
    }
    int did = 0;
    int ans = 0;
    forn(i,1,n) forn(j,1,m) {
        if(did) break;
        if(a[n-1][m-1] == 1 && a[i-1][m-1] != a[i][m-1] && a[n-1][j] != a[n-1][j-1] && (a[i-1][j-1]^a[i-1][j]^a[i][j-1] ^a[i][j]) == 1) {
            did = 1;
            ans+=3;
            forn(p,i,n) forn(q,j,m) a[p][q] ^= 1;
        }
    }
    forn(i,0,n) forn(j,0,m) {
        int cur = a[i][j];
        if(i<n-1) cur^=a[i+1][j];
        if(j<m-1) cur^=a[i][j+1];
        if(i<n-1&&j<m-1) cur^=a[i+1][j+1];
        if(cur) ans++;
    }
    cout<<ans;
    
    
    
}