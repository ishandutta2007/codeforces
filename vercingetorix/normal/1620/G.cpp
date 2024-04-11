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

const int nb = 23;
const int alp = 26;

int mn[alp][1<<nb];
ll num[1<<nb];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    char c[50000];
    forn(i,0,n) {
        scanf("%s", c);
        string s(c);
        forn(j,0,s.size()) {
            mn[s[j]-'a'][1<<i]++;
        }
    }
    num[0] = 0;
    forn(mask,1,1<<n) {
        int bit = 0;
        while((mask&(1<<bit)) == 0) bit++;
        if(mask != (1<<bit)) {
            int m2 = mask ^ (1<<bit);
            forn(j,0,alp) mn[j][mask] = min(mn[j][m2], mn[j][1<<bit]);
        }
        num[mask] = 1;
        forn(j,0,alp) {
            num[mask] = num[mask]*(1+mn[j][mask])%mod;
        }
        if(__builtin_popcount(mask) % 2 == 0) num[mask] = (mod-num[mask])%mod;
    }
    forn(bit,0,n) forn(mask,0,1<<n) {
        if((mask&(1<<bit))==0) {
            num[mask^(1<<bit)] += num[mask];
        }
    }
    ll ans = 0;
    forn(mask,1,1<<n) {
        num[mask]%=mod;
        ll sum = 0;
        forn(bit,0,n) if(mask&(1<<bit)) sum+=bit+1;
        sum*=__builtin_popcount(mask);
        ans ^= num[mask]*sum;
    }
    cout<<ans;
    
    
}