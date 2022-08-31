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

const long long mod = 998244353;
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

ll d[501][501];
ll deg[501][501];
ll cnk[501][501];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,501) {
        cnk[i][0] = 1;
        d[0][i] = 1;
        deg[i][0] = 1;
        forn(p,1,501) deg[i][p] = deg[i][p-1]*i%mod;
    }
    forn(n,1,501) {
        forn(k,1,501) {
            cnk[n][k] = (cnk[n-1][k] + cnk[n-1][k-1])%mod;
        }
    }
//    d[0][0] = 0;
    forn(n,2,501) {
        forn(hmax,1,501) {
            forn(df,0,n+1) {
                if(hmax <= n-1) {
                    if(df != n) continue;
                    else d[n][hmax] = deg[hmax][n];
                    continue;
                }
                d[n][hmax] = (d[n][hmax] + deg[n-1][df] * cnk[n][df] %mod *  d[n-df][hmax - n + 1]) % mod;
            }
        }
    }
    int nn, hp;
    cin>>nn>>hp;
    cout<<d[nn][hp];
    
    
}