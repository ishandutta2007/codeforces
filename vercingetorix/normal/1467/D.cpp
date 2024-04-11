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

const int A = 5001;
int d[A][A];
ll c[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k,q;
    scanf("%d %d %d", &n, &k, &q);
    forn(i,0,n) d[i][0] = 1;
    forn(l,1,k+1) {
        forn(i,0,n) {
            if(i > 0) d[i][l] = d[i-1][l-1];
            if(i < n-1) {
                d[i][l] += d[i+1][l-1];
                if(d[i][l] >= mod) d[i][l] -= mod;
            }
        }
    }
    forn(i,0,n) forn(pos,0,k+1) {
        c[i] = (c[i] + ll(d[i][pos])*d[i][k-pos])%mod;
    }
    ll ans = 0;
    readv(a,n);
    forn(i,0,n) ans = (ans + a[i]*c[i])%mod;
    while(q--) {
        int i,x;
        scanf("%d %d", &i, &x);
        i--;
        ans = (ans + mod - a[i]*c[i]%mod)%mod;
        a[i] = x;
        ans = (ans + a[i]*c[i])%mod;
        printf("%lld\n", ans);
    }
    
}