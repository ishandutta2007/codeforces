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

int me[5000][5000];
ll ans[5000];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,a,b;
    scanf("%d %d %d\n", &n, &a, &b);
    char c[5005];
    scanf("%s", c);
    string s(c);
    forn(r1,0,n) forn(r2,0,n) {
        if(s[r1] == s[r2]) {
            me[r1][r2] = 1;
            if(r1>0 && r2>0) me[r1][r2] += me[r1-1][r2-1];
        }
    }
    ans[0] = a;
    forn(r,1,n) {
        ans[r] = ans[r-1] + a;
        forn(r2,0,r) {
            int tk = min(r-r2, me[r][r2]);
            ans[r] = min(ans[r], ans[r-tk] + b);
        }
    }
    cout<<ans[n-1];
    
    
    
}