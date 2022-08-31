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

ll d[2][1010][204];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(a,n);
    srt(a);
    d[0][0][0] = 1;
    forn(ia,0,n) {
        int i = ia%2;
        int i1 = i^1;
        forn(j,0,k+1) forn(t,0,n+1) d[i1][j][t] = 0;
        forn(j,0,k+1) {
            forn(t,0,ia+1) {
                int add = 0;
                if(ia > 0) add = t*(a[ia]-a[ia-1]);
                if(j+add>k) continue;
                if(t>0) d[i1][j + add][t-1] = (d[i1][j + add][t-1] + t*d[i][j][t])%mod;
                d[i1][j + add][t] = (d[i1][j + add][t] + (t+1)*d[i][j][t])%mod;
                d[i1][j + add][t+1] = (d[i1][j + add][t+1] + d[i][j][t])%mod;
            }
        }
    }
    ll ans = 0;
    forn(i,0,k+1) ans += d[n%2][i][0];
    cout<<ans%mod;
    
}