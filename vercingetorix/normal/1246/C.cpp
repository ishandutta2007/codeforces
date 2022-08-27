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
    int n,m;
    scanf("%d %d\n", &n, &m);
    vs a;
    char c[2004];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    vvi rr(n+1, vi(m+1,0));
    vvi rd(n+1, vi(m+1,0));
    for(int i = n-1; i>=0; i--) {
        for(int j = m-1; j>=0; j--) {
            if(i<n-1) rd[i][j] = rd[i+1][j];
            if(j<m-1) rr[i][j] = rr[i][j+1];
            if(a[i][j] == 'R') {
                rd[i][j]++;
                rr[i][j]++;
            }
        }
    }
    vvll du(n, vll(m, 0));
    vvll dr(n, vll(m, 0));
    vvll rs(n+1, vll(m+1, 0));
    vvll ds(n+1, vll(m+1, 0));
    for(int i = n-1; i>=0; i--) {
        for(int j = m-1; j>=0; j--) {
            if(i==n-1 || j==m-1) {
                if(rr[i][j] == 0 && rd[i][j] == 0) {
                    du[i][j] = 1;
                    dr[i][j] = 1;
                }
            }
            else {
                // du
                if(rd[i][j] < n-i) {
                    int tor = m-1 - rr[i][j+1];
                    int tod = n-1 - rd[i][j];
                    if(tor > j) du[i][j] += rs[i+1][j+1] - rs[i+1][tor+1];
                    if(tod > i) du[i][j] += ds[i+1][j+1] - ds[tod+1][j+1];
                }
                // dr
                if(rr[i][j] < m-j) {
                    int tor = m-1 - rr[i][j];
                    int tod = n-1 - rd[i+1][j];
                    if(tor > j) dr[i][j] += rs[i+1][j+1] - rs[i+1][tor+1];
                    if(tod > i) dr[i][j] += ds[i+1][j+1] - ds[tod+1][j+1];
                }
                dr[i][j] = (dr[i][j]%mod + mod)%mod;
                du[i][j] = (du[i][j]%mod + mod)%mod;
            }
            rs[i][j] = du[i][j];
            if(j<m-1) rs[i][j] = (rs[i][j] + rs[i][j+1]) % mod;
            ds[i][j] = dr[i][j];
            if(i<n-1) ds[i][j] = (ds[i][j] + ds[i+1][j]);
        }
    }
    cout<<dr[0][0];
    
}