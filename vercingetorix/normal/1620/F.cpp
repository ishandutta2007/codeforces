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
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        forn(i,0,n) a[i] = abs(a[i]);
        const int INF = 2e9;
        vi dm(n, INF);
        vi dp(n, INF);
        vi pp(n);
        vi pm(n);
        dm[0] = -INF;
        dp[0] = -INF;
        pp[0] = 1;
        pm[0] = -1;
        forn(i,0,n-1) {
            int to = a[i+1];
            if(-to >= -a[i] && dm[i+1] > dm[i]) {
                dm[i+1] = dm[i];
                pm[i+1] = -1;
            }
            if(-to >= dm[i] && dm[i+1] > -a[i]) {
                dm[i+1] = -a[i];
                pm[i+1] = -1;
            }
            if(to >= -a[i] && dp[i+1] > dm[i]) {
                dp[i+1] = dm[i];
                pp[i+1] = -1;
            }
            if(to >= dm[i] && dp[i+1] > -a[i]) {
                dp[i+1] = -a[i];
                pp[i+1] = -1;
            }
            
            if(-to >= a[i] && dm[i+1] > dp[i]) {
                dm[i+1] = dp[i];
                pm[i+1] = 1;
            }
            if(-to >= dp[i] && dm[i+1] > a[i]) {
                dm[i+1] = a[i];
                pm[i+1] = 1;
            }
            if(to >= a[i] && dp[i+1] > dp[i]) {
                dp[i+1] = dp[i];
                pp[i+1] = 1;
            }
            if(to >= dp[i] && dp[i+1] > a[i]) {
                dp[i+1] = a[i];
                pp[i+1] = 1;
            }
        }
        int cur = n-1;
        int sg = 0;
        if(dp[n-1] != INF) sg = 1;
        if(dm[n-1] != INF) sg = -1;
        if(sg == 0) printf("NO\n");
        else {
            while(cur >= 0) {
                a[cur] *= sg;
                if(sg > 0) sg = pp[cur--];
                else sg = pm[cur--];
            }
            printf("YES\n");
            forn(i,0,n) printf("%d ", a[i]);
            printf("\n");
        }
    }
    
    
}