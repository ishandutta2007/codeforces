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
int n,k;
vll a;
const int A = 52;
int can[A][A];

bool go(ll mask) {
    forn(i,0,n+1) forn(j,0,k+1) can[i][j] = 0;
    can[0][0] = 1;
    forn(i,0,n+1) {
        ll sum = 0;
        forn(r,i,n) {
            sum += a[r];
            if((sum&mask) == mask) {
                forn(was,0,k) can[r+1][was+1] |= can[i][was];
            }
        }
    }
    return can[n][k];
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &k);
    a.resize(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    ll ans = 0;
    for(int bit = 60; bit>=0; bit--) {
        if(go(ans + (1ll<<bit))) ans += 1ll<<bit;
    }
    cout<<ans;
    
}