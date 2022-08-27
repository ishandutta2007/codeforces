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

const long long mod = 998244353;
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
ll d[13][12][12];
ll d2[12][23][12][12];
ll cnk[30][30];
ll fall[30][30];
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

const int A = 500;
ll nfac[A];
ll ifac[A];
ll in[A];

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
    forn(n,0,30) cnk[n][0] = 1;
    forn(n,1,30) forn(k,1,30) cnk[n][k] = (cnk[n-1][k] + cnk[n-1][k-1])%mod;
    d[1][0][0]=1;
    d[2][1][1]=1;
    d[3][2][1]=2;
    d[3][3][2]=1;
    d[4][3][1]=3;
    d[4][3][2]=1;
    d[4][4][1]=1;
    d[4][4][2]=4;
    d[4][5][2]=3;
    d[4][6][3]=1;
    d[5][4][1]=4;
    d[5][4][2]=4;
    d[5][5][1]=2;
    d[5][5][2]=12;
    d[5][5][3]=2;
    d[5][6][1]=2;
    d[5][6][2]=12;
    d[5][6][3]=4;
    d[5][7][2]=9;
    d[5][7][3]=6;
    d[5][8][2]=3;
    d[5][8][3]=6;
    d[5][9][3]=4;
    d[5][10][4]=1;
    d[6][5][1]=5;
    d[6][5][2]=10;
    d[6][5][3]=1;
    d[6][6][1]=3;
    d[6][6][2]=28;
    d[6][6][3]=13;
    d[6][7][1]=4;
    d[6][7][2]=35;
    d[6][7][3]=29;
    d[6][7][4]=1;
    d[6][8][1]=3;
    d[6][8][2]=35;
    d[6][8][3]=41;
    d[6][8][4]=4;
    d[6][9][1]=1;
    d[6][9][2]=30;
    d[6][9][3]=44;
    d[6][9][4]=7;
    d[6][10][2]=17;
    d[6][10][3]=45;
    d[6][10][4]=7;
    d[6][11][2]=8;
    d[6][11][3]=30;
    d[6][11][4]=11;
    d[7][6][1]=6;
    d[7][6][2]=20;
    d[7][6][3]=6;
    d[7][7][1]=4;
    d[7][7][2]=55;
    d[7][7][3]=50;
    d[7][7][4]=3;
    d[7][8][1]=6;
    d[7][8][2]=80;
    d[7][8][3]=118;
    d[7][8][4]=18;
    d[7][9][1]=6;
    d[7][9][2]=95;
    d[7][9][3]=186;
    d[7][9][4]=48;
    d[7][10][1]=6;
    d[7][10][2]=101;
    d[7][10][3]=230;
    d[7][10][4]=85;
    d[7][10][5]=2;
    d[7][11][1]=2;
    d[7][11][2]=94;
    d[7][11][3]=260;
    d[7][11][4]=113;
    d[7][11][5]=4;
    d[8][7][1]=7;
    d[8][7][2]=35;
    d[8][7][3]=21;
    d[8][7][4]=1;
    d[8][8][1]=5;
    d[8][8][2]=96;
    d[8][8][3]=145;
    d[8][8][4]=26;
    d[8][9][1]=8;
    d[8][9][2]=155;
    d[8][9][3]=358;
    d[8][9][4]=124;
    d[8][9][5]=3;
    d[8][10][1]=9;
    d[8][10][2]=207;
    d[8][10][3]=616;
    d[8][10][4]=313;
    d[8][10][5]=16;
    d[8][11][1]=11;
    d[8][11][2]=250;
    d[8][11][3]=859;
    d[8][11][4]=567;
    d[8][11][5]=53;
    d[9][8][1]=8;
    d[9][8][2]=56;
    d[9][8][3]=56;
    d[9][8][4]=8;
    d[9][9][1]=6;
    d[9][9][2]=154;
    d[9][9][3]=350;
    d[9][9][4]=126;
    d[9][9][5]=4;
    d[9][10][1]=10;
    d[9][10][2]=268;
    d[9][10][3]=898;
    d[9][10][4]=552;
    d[9][10][5]=48;
    d[9][11][1]=12;
    d[9][11][2]=389;
    d[9][11][3]=1654;
    d[9][11][4]=1404;
    d[9][11][5]=204;
    d[9][11][6]=1;
    d[10][9][1]=9;
    d[10][9][2]=84;
    d[10][9][3]=126;
    d[10][9][4]=36;
    d[10][9][5]=1;
    d[10][10][1]=7;
    d[10][10][2]=232;
    d[10][10][3]=742;
    d[10][10][4]=448;
    d[10][10][5]=43;
    d[10][11][1]=12;
    d[10][11][2]=427;
    d[10][11][3]=1967;
    d[10][11][4]=1887;
    d[10][11][5]=357;
    d[10][11][6]=6;
    d[11][10][1]=10;
    d[11][10][2]=120;
    d[11][10][3]=252;
    d[11][10][4]=120;
    d[11][10][5]=10;
    d[11][11][1]=8;
    d[11][11][2]=333;
    d[11][11][3]=1428;
    d[11][11][4]=1302;
    d[11][11][5]=252;
    d[11][11][6]=5;
    d[12][11][1]=11;
    d[12][11][2]=165;
    d[12][11][3]=462;
    d[12][11][4]=330;
    d[12][11][5]=55;
    d[12][11][6]=1;
    d2[0][0][0][0] = 1;
    forn(l,2,13) forn(k,0,12) forn(x,0,12) if(d[l][k][x] > 0) {
        int cur = d[l][k][x];
        for(int wg = 10; wg >= 0; wg--) {
            forn(wl,0,23) forn(wk,0,12) forn(wx,0,12) if(d2[wg][wl][wk][wx]) {
                ll dd = cur;
                for(int tk = 1; wl + l*tk <= 22 && wk + k*tk<12 && wx+x*tk<12; tk++) {
                    d2[wg+tk][wl+l*tk][wk+k*tk][wx+x*tk] = (d2[wg+tk][wl+l*tk][wk+k*tk][wx+x*tk] + d2[wg][wl][wk][wx]*cnk[wg+tk][tk]%mod*dd)%mod;
                    dd = dd*cur%mod;
                }
            }
        }
    }
    int pl = 0;
    vvi imp;
    forn(g,0,12) forn(l,0,23) forn(k,0,12) forn(x,0,12) if(d2[g][l][k][x]) imp.pb({g,l,k,x});
    int ta;
    read(ta);
    forn(i,0,30) fall[i][0] = 1;
    forn(ifa,0,ta) {
        int n,k,x;
        scanf("%d %d %d", &n, &k, &x);
        forn(dec,0,30) forn(i,1,30) fall[dec][i] = fall[dec][i-1]*(n-dec+1-i)%mod*in[i]%mod;
        ll ans = 0;
        for(auto vv : imp) {
            int wg = vv[0];
            int wl = vv[1];
            int wk = vv[2];
            int wx = vv[3];
            if(wk != k || wx != x || wl > n) continue;
            ll cur = d2[wg][wl][wk][wx];
            ans = (ans + cur*fall[wl-wg][wg])%mod;
//            cout<<wg<<' '<<wl<<' '<<cur<<' '<<fall[wl]<<'\n';
//            cout<<wg<<' '<<wl<<' '<<wk<<' '<<wx<<' '<<d2[wg][wl][wk][wx]<<'\n';
        }
        printf("%lld\n", ans);
//        exit(0);
    }
    

    
    
}