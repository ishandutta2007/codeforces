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
    const int A = 2005;
    char c[A];
    forn(ifa,0,ta) {
        int n;
        scanf("%d\n", &n);
        vs a;
        forn(i,0,n) {
            scanf("%s", c);
            a.pb(string(c));
        }
        vi rn(10, A);
        vi rx(10, -1);
        vi cn(10, A);
        vi cx(10, -1);
        forn(i,0,n) forn(j,0,n) {
            int cur = a[i][j] - '0';
            rn[cur] = min(rn[cur], i);
            rx[cur] = max(rx[cur], i);
            cn[cur] = min(cn[cur], j);
            cx[cur] = max(cx[cur], j);
        }
        vi ans(10,0);
        forn(i,0,n) forn(j,0,n) {
            int cur = a[i][j]-'0';
            int cl = max(i,n-1-i);
            int rl = max(j,n-1-j);
            ans[cur] = max(ans[cur], cl * (cx[cur] - j));
            ans[cur] = max(ans[cur], cl * (j - cn[cur]));
            ans[cur] = max(ans[cur], rl * (rx[cur] - i));
            ans[cur] = max(ans[cur], rl * (i - rn[cur]));
        }
        forn(i,0,10) printf("%d ", ans[i]);
        printf("\n");
        
    }
    
    
}