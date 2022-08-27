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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    forn(ifa,0,t) {
        int n;
        scanf("%d", &n);
        readv(c,n);
        int mn[2];
        mn[0] = c[0];
        mn[1] = c[1];
        ll sum[2];
        sum[0] = c[0];
        sum[1] = c[1];
        int k = 2;
        ll ans = 1e18;
        while(k <= n) {
            int l1 = k - k/2;
            int l2 = k/2;
            ans = min(ans, sum[0] + ll(n-l1)*mn[0] + sum[1] + ll(n-l2)*mn[1]);
            if(k<n) {
                sum[k%2] += c[k];
                mn[k%2] = min(mn[k%2], c[k]);
            }
            k++;
        }
        printf("%lld\n", ans);
        
    }
    
    
}