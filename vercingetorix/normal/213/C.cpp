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
const int A = 301;
int dp[A][A][A];
int fdp[A][A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int n;
    read(n);
    vvi a(n, vi(n));
    forn(i,0,n) forn(j,0,n) read(a[i][j]);
    forn(u,0,n) forn(d,0,u+1) dp[0][d][u] = -1e9;
    dp[0][0][0] = 0;
    forn(l,0,n) {
        forn(u,0,n) {
            int best = -1e9;
            forn(d,0,u+1) {
                best = max(best, dp[l][d][u]);
                best += a[l][d];
                dp[l+1][d][u] = best;
                if(d!=u) dp[l+1][d][u] += a[l][u];
                else fdp[l+1][d] = dp[l+1][d][d];
            }
        }
        forn(d,0,n) {
            dp[l+1][d][d] = max(dp[l+1][d][d], fdp[l+1][d]);
            if(d+1<n) fdp[l+1][d+1] = max(fdp[l+1][d+1], fdp[l+1][d] + a[l][d+1]);
            forn(u,d,n-1) {
                dp[l+1][d][u+1] = max(dp[l+1][d][u+1], dp[l+1][d][u] + a[l][u+1]);
            }
        }
    }
//    forn(i,0,n+1) {
//        cout<<i<<'\n';
//        forn(d,0,n) {
//            forn(u,0,n) cout<<dp[i][d][u]<<' ';
//            cout<<'\n';
//        }
//    }
    cout<<dp[n][n-1][n-1];
    
    
}