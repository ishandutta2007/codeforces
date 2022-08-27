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

const int A = 50;

int x[A][A][A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    vs a;
    char c[A+10];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    forn(r,0,n) forn(u,0,n) {
        for(int l = r; l >= 0; l--) for(int d = u; d >= 0; d--) {
            if(r == l && u == d) {
                if(a[l][u] == '#') x[l][r][d][u] = 1;
                else x[l][r][d][u] = 0;
            }
            else if(r-l >= u-d) {
                x[l][r][d][u] = r-l+1;
                forn(m,l,r) x[l][r][d][u] = min(x[l][r][d][u], x[l][m][d][u] + x[m+1][r][d][u]);
            }
            else {
                x[l][r][d][u] = u-d+1;
                forn(m,d,u) x[l][r][d][u] = min(x[l][r][d][u], x[l][r][d][m] + x[l][r][m+1][u]);
            }
        }
    }
    cout<<x[0][n-1][0][n-1];
    
}