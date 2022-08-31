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

int n,m,q;
int ans[1<<12][101];
int cnt[1<<12];
int cost[1<<12];

int w[20];
int toy(const string & s) {
    int ret = 0;
    forn(i,0,n) {
        ret = ret*2 + (s[i]-'0');
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d %d", &n, &m, &q);
    char c[20];
    forn(i,0,n) scanf("%d", &w[n-1-i]);
    forn(i,0,m) {
        scanf("%s", c);
        cnt[toy(string(c))]++;
    }
    forn(mask,0,1<<n) {
        forn(bit,0,n) {
            if((mask & (1<<bit)) == 0) {
                cost[mask | (1<<bit)] = cost[mask] + w[bit];
            }
        }
    }
    int inv = (1<<n) - 1;
    forn(mask,0,1<<n) {
        forn(mask2,0,1<<n) {
            int k = cost[mask^mask2^inv];
            if(k <= 100) ans[mask][k] += cnt[mask2];
        }
        forn(k,1,101) ans[mask][k] += ans[mask][k-1];
    }
    while(q--) {
        int k;
        scanf("%s %d\n", c, &k);
        printf("%d\n", ans[toy(string(c))][k]);
    }
    
    
}