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
ll p[2];
ll m[2];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    p[0] = 41;
    p[1] = 237;
    m[0] =986429077;
    m[1] = 986427803;
    int t;
    read(t);
    vll dp[2];
    forn(i,0,2) dp[i].pb(1);
    forn(it,0,2)
    forn(i,0,300500) {
        dp[it].pb(dp[it].back() * p[it] % m[it]);
    }
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        vi cur;
        vvll q;
        vll h(2, 0);
        int l = 0;
        q.pb(vll(2,0));
        forn(i,0,n) {
            if(cur.empty() || cur.back() != a[i]) {
                forn(it,0,2) {
                    h[it] = (h[it] + dp[it][l]*a[i]) % m[it];
                }
                l++;
                cur.pb(a[i]);
            }
            else {
                l--;
                forn(it,0,2) {
                    h[it] = (h[it] + m[it] - dp[it][l]*a[i]%m[it]) % m[it];
                }
                cur.pop_back();
            }
            q.pb(h);
        }
        srt(q);
        int pt = 0;
        ll ans = 0;
        while(pt < q.size()) {
            int ptr = pt+1;
            while(ptr < q.size() && q[ptr] == q[pt]) ptr++;
            ll k = ptr - pt;
            ans += k*(k-1)/2;
            pt = ptr;
        }
        printf("%lld\n", ans);
    }
    
    
}