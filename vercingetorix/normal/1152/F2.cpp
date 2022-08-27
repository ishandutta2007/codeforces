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

int d[13][63][8][24][12][12];

void inc(int & a, int x) {
    a = (a + x)%mod;
}

int ans[13][13][63];
ll dn[50][50];
int cnk[50][50];

const int A = 500;
ll nfac[A];
ll ifac[A];
ll in[A];
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
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
    forn(i,1,A) in[i] = ifac[i]*nfac[i-1]%mod;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    forn(i,0,50) {
        dn[i][0] = 1;
        forn(j,1,50) dn[i][j] = dn[i][j-1]*i%mod;
    }
    forn(i,0,50) {
        cnk[i][0] = 1;
        if(i>0) forn(j,1,50) cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
    }
    int l,k,m;
    cin>>l>>k>>m;
    d[1][1][0][0][0][0] = 1;
    int gmask = (1<<(m))-1;
    int fmask = (1<<(m-1))-1;
    forn(was,1,12) forn(len,1,4*was-2) forn(mask,0,8) forn(d2,0,24) forn(d3,0,12) forn(d5,0,12) if(d[was][len][mask][d2][d3][d5] != 0) {
        int cur =d[was][len][mask][d2][d3][d5];
        forn(shift,1,m+1) {
            int mmask = ((2*mask+1) << (shift-1)) & gmask;
            int nmask = mmask&fmask;
            int w = __builtin_popcount(mmask) + 1;
            if(w == 5) inc(d[was+1][len+shift][nmask][d2][d3][d5+1], cur);
            else if(w == 4) inc(d[was+1][len+shift][nmask][d2+2][d3][d5], cur);
            else if(w == 3) inc(d[was+1][len+shift][nmask][d2][d3+1][d5], cur);
            else if(w == 2) inc(d[was+1][len+shift][nmask][d2+1][d3][d5], cur);
        }
    }
    ans[0][0][0] = 1;
    forn(n,1,k+1) forn(len,1,4*n-2) forn(d2,0,24) forn(d3,0,12) forn(d5,0,12) {
        ll sum = 0;
        forn(mask,0,8) sum += d[n][len][mask][d2][d3][d5];
        sum %= mod;
        if(sum == 0) continue;
        ll win = dn[2][d2] * dn[3][d3] % mod * dn[5][d5] % mod * sum%mod;
        for(int gwas = k-1; gwas>=0; gwas--) {
            forn(was,gwas,k) forn(waslen,gwas,(m+1)*was+1) {
                if(ans[gwas][was][waslen] != 0) {
                    ll pwin = win;
                    forn(tk,1,13) {
                        if(tk*n + was > k) break;
                        ans[gwas + tk][was + tk*n][waslen + tk*(len+m)] = (ans[gwas + tk][was + tk*n][waslen + tk*(len+m)] + ans[gwas][was][waslen] * cnk[gwas + tk][tk] % mod  * pwin) % mod;
                        pwin = pwin*win%mod;
                    }
                }
            }
        }
        
    }
    ll res = 0;
    forn(g,1,k+1) forn(len,0,k*(m+1)+1) {
        if(ans[g][k][len] != 0) {
            int n = l - (len - m);
            if(n>=0) {
                ll cur = 1;
                forn(i,1,g+1) cur = cur*(n+i)%mod*in[i]%mod;
                res = (res+cur*ans[g][k][len])%mod;
            }
            
        }
    }
    cout<<res;
}