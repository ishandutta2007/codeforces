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
#define readv(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair
int d[3000][3000];
// int d[10][10];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[3005];
    scanf("%s", c);
    string s(c);
    int n = s.size();
    scanf("%s", c);
    string t(c);
    int m = t.size();
    forn(i,0,n) if(i >= m || s[0] == t[i]) d[i][i] = 2;
    forn(i,1,n) {
        forn(l, 0, n-i+1) {
            int r = l+i-1;
            if(l>0 && (l-1>=m || s[i] == t[l-1])) d[l-1][r] = (d[l-1][r]+d[l][r])%mod;
            if(r+1<n && (r+1>=m || s[i] == t[r+1])) d[l][r+1] = (d[l][r+1]+d[l][r])%mod;
        }
    }
    ll ans = 0;
    forn(r,m-1,n) ans += d[0][r];
    cout<<ans%mod;
    
}