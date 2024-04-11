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
char c[10];
bool ask(ll l, ll r) {
    printf("%lld %lld\n", l,r);
    fflush(stdout);
    scanf("%s", c);
    if(c[0] == 'Y') {
        if(l==r) exit(0);
        else return true;
    }
    else return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n; int k;
    scanf("%lld %d", &n, &k);
    ll l = 1;
    ll r = n;
    while(1) {
        while(r-l > 5*k) {
            ll m = (r+l)/2;
            if(ask(l,m)) r = m;
            else l = m+1;
            l = max(1ll,l-k);
            r= min(n, r+k);
        }
        ll pos = l + gen()%(r-l+1);
        ask(pos, pos);
        l = max(1ll,l-k);
        r= min(n, r+k);
    }
    
    
}