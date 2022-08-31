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
    vll d2(1,1);
    forn(i,0,200500) d2.pb(d2.back() * 2 % mod);
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d", &n, &m);
        vpi ev;
        forn(i,0,m) {
            int l,r,x;
            scanf("%d %d %d", &l, &r, &x);
            l--; r--;
            ev.pb(mp(l,1+x));
            ev.pb(mp(r+1,-1-x));
        }
        srt(ev);
        vi cnt(30,0);
        vi cur(30,0);
        int pt = 0;
        int tot = 0;
        forn(i,0,n) {
            while(pt < ev.size() && ev[pt].first <= i) {
                if(ev[pt].second > 0) {
                    ev[pt].second--;
                    tot++;
                    forn(bit,0,30) if((ev[pt].second & (1<<bit)) == 0) cur[bit]++;
                }
                else if(ev[pt].second < 0){
                    ev[pt].second++;
                    tot--;
                    forn(bit,0,30) if(((-ev[pt].second) & (1<<bit)) == 0) cur[bit]--;
                }
                pt++;
            }
            forn(j,0,30) if(cur[j] == 0) cnt[j]++;
        }
        ll ans = 0;
        forn(i,0,30) if(cnt[i] > 0) {
            ans = ans + ll(1<<i)*d2[n-1]%mod;
        }
        printf("%lld\n", ans%mod);
    }
    
    
}