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

const long long mod = 998244353;
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
const int N = 100500;
vll ans[2];
vi ops[2];
vpi lr[2];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        ans[0].pb(0);
        ops[0].pb(0);
        lr[0].pb(mp(1,1));
        ll ret = 0;
        forn(i,1,n+1) {
            int x = a[i-1];
            int l = x;
            int r = x;
            int op = 0;
            int pt = 0;
            while(1) {
                ops[i%2].pb(op);
                lr[i%2].pb(mp(l,r));
                while(lr[1-i%2][pt].second > l) pt++;
                ans[i%2].pb((ll(i-1)*ops[1-i%2][pt] + ans[1-i%2][pt])%mod);
                if(r == 1) break;
                // 1+(x-1)/(op+1) <= r-1
                // (x-1)/(op+1) <= r-2
                // x-1 <= (r-2)*(op+1) + op
                // x <= (r-1)*(op+1)
                // op + 1 >= x/(r-1)
                op = max(op+1, x/(r-1)-1);
                r = 1+(x-1)/(op+1);
                l = x/(op+1);
            }
            ops[1-i%2].clear();
            ans[1-i%2].clear();
            lr[1-i%2].clear();
            ret = (ret + ans[i%2][0]) % mod;
        }
        printf("%lld\n", ret);
        ans[n%2].clear();
        lr[n%2].clear();
        ops[n%2].clear();
    }
    
    
}