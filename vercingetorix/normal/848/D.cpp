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
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    gcd(a, modulo, x, y);
    return (x%modulo+modulo)%modulo;
}
ll facinv[100];
ll fac[100];

ll ank(ll n, ll k) {
    ll ret = facinv[k];
    forn(i,0,k) ret = ret * (n+i) % mod;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fac[0] = 1;
    facinv[0] = 1;
    for(ll i =1; i<100; i++) {
        fac[i] = fac[i-1]*i%mod;
        facinv[i] = invmod(fac[i], mod);
    }
    vvll cnk(201, vll(201, 0));
    forn(i,0,201) cnk[i][0] = 1;
    forn(i,1,201) {
        forn(j,1,min(i+1,201)) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }
    
    vvll d(121, vll(121,0));
    vvll dp(121, vll(121, 0));
    d[0][1] = 1;
    forn(n, 0, 51) {
        forn(m, 1, 51) {
//            vvll dp(n+1, vll(51, 0));
//            forn(n1,1,n+1) {
//                forn(m,1,51) {
//                    forn(n12,0,n1) {
//                        int n22 = n1 -1 - n12;
//                        if(n12 != n22) {
//                            
//                        }
//                    }
//                }
//            }
//            vvll nd(n+1, vll(51,0));
//            forn(n1,1,n+1) {
//                forn(m,)
//            }
            dp[2*n+1][m] = (d[n][m]*d[n][m] + dp[2*n+1][m])%mod;
            forn(n1,0,51) {
                if(n1>n) break;
                forn(m1, 1, 51) {
                    if(n1==n && m1 == m) break;
                    dp[n+n1+1][min(m,m1)] = (dp[n+n1+1][min(m,m1)] + 2*d[n][m]*d[n1][m1]) % mod;
                }
            }
            vvll nd = d;
            forn(k,1,51) {
                if(k*n > 50) break;
                ll sp = ank(dp[n][m], k);
                for(int n1 = 50; n1 >= k*n; n1--) {
                    for(int m1 = 50; m1 >= 1+k*m; m1--) {
                        nd[n1][m1] = (nd[n1][m1] + (d[n1-k*n][m1-k*m] * sp)) % mod;
                    }
                }
            }
            d = nd;
//            d[n][m] = (d[n][m] + dp[n][m-1]) % mod;
        }
    }
    
    
    int n,m;
    cin>>n>>m;
    cout<<d[n][m];
    
}