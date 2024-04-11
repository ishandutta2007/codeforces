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

//ll shift[1<<24];
set<ll> found;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s;
    cin>>s;
    int pt = 0;
    while(pt < s.size() && s[pt] == '0') pt++;
    if(pt == s.size()) {
        cout<<-1;
        exit(0);
    }
    int add = pt;
    s = s.substr(pt);
    while(s.back() == '0') s.pop_back();
    if(s.size() == 1) {
        printf("%d %d\n", add+1, add+2);
        exit(0);
        
    }
    ll n = 0;
    for(auto x : s) n = n*2 + (x-'0');
    ll cur = (n-1)/2;
    ll ans = 1;
    while(cur % 2 == 0) {
        cur>>=1;
        ans++;
    }
    ll oddmask = 0;
    forn(i,0,20) oddmask |= (1ll<<(i*2+1));
    ll curshift = 0;
    auto babystep = [&]() {
        if(cur == 1) {
            printf("%lld %lld\n", add + 1ll, add + 1 + ans);
            exit(0);
        }
        cur ^= n;
        int tz = __builtin_ctzll(cur);
        cur >>= tz;
        ans += tz;
    };
    int num = 1000000;
    found.insert(cur);
    forn(i,0,num) {
        babystep();
        found.insert(cur);
    }
    forn(i,0,100) {
        babystep();
        found.insert(cur);
    }
    ll gs = ans-1;
    ll gmask = cur;
    auto giantstep = [&]() {
        ll to = 0;
        ll mv = gs;
        int bs = 0;
        forn(bit,0,40) {
            bs++;
            if(cur & (1ll<<bit)) to ^= (gmask<<bs);
            while(to >= (1ll<<(s.size()-1))) {
                mv++;
                bs--;
                if(to%2 == 0) to >>= 1;
                else {
                    to^=n;
                    to>>=1;
                }
            }
        }
        while(to%2 == 0) {
            to>>=1;
            mv++;
        }
        while(to >= 1ll<<s.size()) {
            to ^= n;
            int tz = __builtin_ctzll(to);
            to >>= tz;
            mv += tz;
        }
        if(found.find(to) != found.end()) return false;
        else {
            ans += mv;
            cur = to;
            return true;
        }
    };
    while(giantstep()) {}
    while(1) babystep();
}