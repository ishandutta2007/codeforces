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

const int A = 3000100;
bitset<A> ff;
bitset<A> isf;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi f(2,1);
    forn(i,2,1390444) {
        f.pb(f[i-1] + f[i-2]);
        if(f.back() > A) break;
    }
    for(auto x : f) if(x<A) isf[x] = 1;
    ff[0] = 1;
    forn(i,2,f.size()) {
        forn(j,f[i],min(A,f[i]+f[i-1])) ff[j] = ff[j-f[i]];
    }
    vpll bad;
    int n;
    cin>>n;
    ll cur = 1;
    int len = 0;
    char last = '0';
    while(n--) {
        string s;
        cin>>s;
        for(auto c : s) {
            vpll nbad;
            ll cut = cur;
            for(auto x : bad) {
                if(isf[len - x.first]) cut = (cut + mod - x.second)%mod;
                if(int(c-'0') == ff[len-x.first] && (len-x.first > 1 || last == '1')) nbad.pb(x);
            }
            nbad.pb(mp(len++, cut));
            swap(nbad, bad);
            cur = (cur + cut)%mod;
            if(len == 1) cur = 1;
            last = c;
        }
        ll ans = cur;
        for(auto x : bad) if(isf[len - x.first]) ans += mod-x.second;
        cout<<ans%mod<<'\n';
    }
    
}