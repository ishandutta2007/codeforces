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
const int A = 400500;
ll fac[A];
ll ifac[A];
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

ll cnk(int n, int k) {
    if(k<0 || k>n) return 0;
    ll ret = fac[n]*ifac[k]%mod*ifac[n-k]%mod;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fac[0] = 1;
    forn(i,1,A) fac[i] = fac[i-1]*i%mod;
    ifac[A-1] = invmod(fac[A-1], mod);
    for(int i = A-2; i>=0; i--) ifac[i] = ifac[i+1]*(i+1)%mod;
    int n;
    scanf("%d\n", &n);
    int dx = 0;
    int dx1 = 0;
    char c[5];
    int canw = 1;
    int canb = 1;
    ll wsame = 1;
    forn(i,0,n) {
        scanf("%s", c);
        string s(c);
        if(s[1] == 'B') s[1] = 'W';
        else if(s[1] == 'W') s[1] = 'B';

        if(s[0] == 'B' || s[1] == 'B') canw = 0;
        if(s[0] == 'W' || s[1] == 'W') canb = 0;

        if(s == "BW" || s == "WB") wsame = 0;

        
        if(s == "WW" || s == "BB") continue;
        else if(s == "WB") dx++;
        else if(s == "BW") dx--;
        else if(s == "W?" || s == "?B") {
            dx1 ++;
        }
        else if(s == "B?" || s == "?W") {
            dx1++;
            dx--;
        }
        else {
            wsame = wsame*2%mod;
            dx--;
            dx1 += 2;
        }
    }
    ll ans = (canb + canw - wsame + mod)%mod;
//    ans += cnk(dx1, -dx-1);
    ans += cnk(dx1, -dx);
//    ans += cnk(dx1, -dx+1);
    cout<<ans%mod;
    
    
}