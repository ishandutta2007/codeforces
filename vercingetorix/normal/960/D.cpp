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
vll shift(63, 0);
vll d2(1,1);

void mv(int deg, ll k) {
    shift[deg] += k;
    shift[deg] = (shift[deg] % d2[deg] + d2[deg]) % d2[deg];
}

ll sl(int deg, ll x, ll k) {
    return d2[deg]+((x+k) % d2[deg] + d2[deg]) % d2[deg];
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,63) d2.pb(d2.back()*2);
    int q;
    scanf("%d", &q);
    
    while(q--) {
        int tp;
        ll x,k;
        scanf("%d %lld", &tp, &x);
        if(tp == 1) {
            scanf("%lld", &k);
            int deg = 0;
            while(1ll<<(deg+1) <= x) deg++;
            mv(deg, k);
            mv(deg+1, -2*k);
        }
        else if(tp == 2) {
            scanf("%lld", &k);
            int deg = 0;
            while(1ll<<(deg+1) <= x) deg++;
            mv(deg, k);
        }
        else {
            int deg = 0;
            while(1ll<<(deg+1) <= x) deg++;
            while(x >= 1) {
                printf("%lld ", x);
                x = sl(deg, x,shift[deg])/2;
                deg--;
            }
            printf("\n");
        }
    }
    
}