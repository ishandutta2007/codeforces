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

const int A = 150;
ll d[A][A][A][2][2];
ll p[A][A][A][2][2];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(l,0,n) forn(r,l,n) d[0][l][r][0][0] = 1;
    forn(j,0,m-1) {
        forn(l,0,n) forn(wl,0,2) forn(wr,0,2) {
            forn(r,l,n) p[j][l][r][wl][wr] = d[j][l][r][wl][wr] % mod;
            forn(r,l+1,n) {
                p[j][l][r][wl][wr] += p[j][l][r-1][wl][wr];
//                if(p[j][l][r][wl][wr]>=mod) p[j][l][r][wl][wr]-=mod;
            }
        }
        forn(l,0,n) forn(wl,0,2) {
            forn(l2,0,n) forn(r2,l2,n) {
                if(l2 < l && wl) continue;
                if(r2 < l) continue;
                int nwl = wl || (l2>l);
//                app(d[j+1][l2][r2][nwl][0], p[j][l][r2][wl][0]);
//                int rb0 = max(l,l2);
//                if(rb0>0) app(d[j+1][l2][r2][nwl][0], mod - p[j][l][rb0-1][wl][0]);
                d[j+1][l2][r2][nwl][0] += p[j][l][r2][wl][0];
//                if(d[j+1][l2][r2][nwl][0]>=mod) d[j+1][l2][r2][nwl][0]-=mod;
                int rb0 = max(l,l2);
                if(rb0 > 0) {
                    d[j+1][l2][r2][nwl][0] -= p[j][l][rb0-1][wl][0];
//                    if(d[j+1][l2][r2][nwl][0]>=mod) d[j+1][l2][r2][nwl][0]-=mod;
                }
                
//                app(d[j+1][l2][r2][nwl][1], p[j][l][n-1][wl][1]);
//                if(r2>0) app(d[j+1][l2][r2][nwl][1], mod - p[j][l][r2-1][wl][1]);
//                app(d[j+1][l2][r2][nwl][1], p[j][l][n-1][wl][0]);
//                app(d[j+1][l2][r2][nwl][1], mod-p[j][l][r2][wl][0]);
                
                d[j+1][l2][r2][nwl][1] += p[j][l][n-1][wl][1];
//                if(d[j+1][l2][r2][nwl][1]>=mod) d[j+1][l2][r2][nwl][1]-=mod;
                if(r2>0) {
                    d[j+1][l2][r2][nwl][1] -= p[j][l][r2-1][wl][1];
//                    if(d[j+1][l2][r2][nwl][1]>=mod) d[j+1][l2][r2][nwl][1]-=mod;
                }
                d[j+1][l2][r2][nwl][1] += p[j][l][n-1][wl][0];
//                if(d[j+1][l2][r2][nwl][1]>=mod) d[j+1][l2][r2][nwl][1]-=mod;
                d[j+1][l2][r2][nwl][1] -= p[j][l][r2][wl][0];
//                if(d[j+1][l2][r2][nwl][1]>=mod) d[j+1][l2][r2][nwl][1]-=mod;
            }
        }
    }
    ll ans = 0;
    forn(k,0,m) forn(l,0,n) forn(r,l,n) forn(wl,0,2) forn(wr,0,2) ans += ll(d[k][l][r][wl][wr]%mod)*(m-k);
    cout<<ans%mod;
    
    
}