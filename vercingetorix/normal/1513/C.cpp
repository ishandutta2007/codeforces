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
int k = 10;

ll mh[3][10][10];

void mul(int a, int b, int c) {
    forn(i,0,k) forn(j,0,k) mh[c][i][j] = 0;
    forn(i,0,k) forn(j,0,k) {
        forn(p,0,k) mh[c][i][j] += mh[a][i][p] * mh[b][p][j];
        mh[c][i][j] %= mod;
    }
}

vll mulv(const vvll & x, const vll & y) {
    vll res(k,0);
    forn(i,0,k) {
        forn(p,0,k) res[i] += x[i][p] * y[p] % mod;
        res[i] %= mod;
    }
    return res;
}

//vvll mpow(vvll & x, int k) {
//    if(k == 1) return x;
//    vvll u = mpow(x, k/2);
//    vvll res = mul(u, u);
//    if(k%2) res = mul(res, x);
//    return res;
//}

ll res[10][200500];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    vvll a(10, vll(10, 0));
    forn(i,0,9) a[i+1][i] = 1;
    a[0][9] = 1;
    a[1][9] = 1;
    forn(i,0,10) forn(j,0,10) mh[2][i][j] = a[i][j];
    forn(i,0,10) forn(j,0,10) mh[1][i][j] = a[i][j];
    forn(i,0,10) res[i][0] = 1;
    vvll ak = a;
    forn(i,1,200020) {
        forn(d,0,10) forn(l,0,10) res[d][i] += mh[i%2][l][d];
//        ak = mul(ak, a);
        mul(2,i%2,1-i%2);
    }
    forn(ifa,0,t) {
        int n,m;
        scanf("%d %d", &n, &m);
        vll cnt(10,0);
        while(n>0) {
            cnt[n%10]++;
            n/=10;
        }
        
        ll ans = 0;
        forn(i,0,10) ans += cnt[i]*res[i][m];
        printf("%lld\n", ans%mod);
    }
    
    
    
}