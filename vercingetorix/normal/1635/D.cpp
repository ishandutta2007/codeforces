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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,p;
    scanf("%d %d", &n, &p);
    readv(a,n);
    set<int> b;
    for(auto x : a) b.insert(x);
    forn(i,0,n) {
        int bad = 0;
        int m = a[i];
        while(m>0) {
            if(m%2) m/=2;
            else if(m%4==0) m/=4;
            else break;
            if(b.count(m)) bad = 1;
        }
        if(bad) {
            swap(a[i], a.back());
            a.pop_back();
            n--; i--;
        }
    }
    vi f(p+1,0);
    f[0] = 1;
    f[1] = 1;
    forn(i,2,p+1) {
        f[i] = (f[i-1] + f[i-2])%mod;
    }
    forn(i,1,p+1) f[i] = (f[i]+f[i-1])%mod;
    ll ans = 0;
    for(auto x : a) {
        int deg = 0;
        while(x > 0) {
            deg++;
            x/=2;
        }
        if(deg <= p) ans = (ans + f[p-deg])%mod;
    }
    cout<<ans;
    
}