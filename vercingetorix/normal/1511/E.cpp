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

const long long mod = 998244353 ;
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
    vll d2(1,1);
    forn(i,0,300500) d2.pb(d2.back()*2%mod);
    int n,m;
    scanf("%d %d\n", &n, &m);
    vs a;
    vll d(300500,0);
    d[0] = 0;
    d[1] = 0;
    forn(i,2,300500) {
        d[i] = (d[i-1] + 2*d[i-2] + d2[i-2])%mod;
    }
    char c[300600];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    int fr = 0;
    forn(i,0,n) forn(j,0,m) if(a[i][j] == 'o') fr++;
    vll b(300500);
    forn(i,0,fr+1) b[i] = d[i]*d2[fr-i]%mod;
    ll ans = 0;
    forn(i,0,n) {
        int cur = 0;
        forn(j,0,m) if(a[i][j] == 'o') cur++;
        else {
            ans = (ans + b[cur])%mod;
            cur = 0;
        }
        ans = (ans + b[cur])%mod;
    }
    forn(j,0,m) {
        int cur = 0;
        forn(i,0,n) if(a[i][j] == 'o') cur++;
        else {
            ans = (ans + b[cur])%mod;
            cur = 0;
        }
        ans = (ans + b[cur])%mod;
    }
    cout<<ans;
    
    
    
}