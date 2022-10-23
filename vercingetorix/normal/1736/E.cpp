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
const int A = 501;
int d[A][A][A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    const int INF = 1e9;
    forn(i,0,A) forn(j,0,A) forn(k,0,A) d[i][j][k] = -INF;
    d[0][0][1] = a[0];
    d[0][1][0] = a[1];
    forn(last,0,n-1) {
        forn(tk,0,last+2) {
            forn(fr,0,n+1) if(d[last][tk][fr] >= 0) {
                d[last+1][tk][fr] = max(d[last+1][tk][fr], d[last][tk][fr] + a[tk]);
//                if(last >= tk) {
                    if(last+1 > tk) d[last+1][last+1][fr+1] = max(d[last+1][last+1][fr+1], d[last][tk][fr] + a[last+1]);
                    forn(nx,last+2,n) {
                        int need = nx - last - 2;
                        if(need > fr) break;
                        d[nx-1][nx][fr-need] = max(d[nx-1][nx][fr-need], d[last][tk][fr]  + a[nx]*(nx-1-last));
                    }
//                }
//                int reach = last + fr + 1;
//                if(reach >= n) reach = n-1;
//                if(reach > tk) d[last+1][reach][1] = max(d[last+1][reach][1], d[last][tk][fr] + a[reach]);
//                ++reach;
//                if(reach < n && reach > tk) d[last+1][reach][0] = max(d[last+1][reach][0], d[last][tk][fr] + a[reach]);
//                if(last >= tk) {
//                    d[last+1][last+1][fr+1]= max(d[last+1][last+1][fr+1], d[last][tk][fr] + a[last+1]);
//                    forn(nx, last + 2, n) {
//                        int need = nx - last - 2;
//                        if(need > fr) break;
//                        d[last+1][nx][fr-need] = max(d[last+1][nx][fr-need], d[last][tk][fr] + a[nx]);
//                    }
//                }
            }
        }
    }
    int ans = 0;
    forn(i,0,n) forn(j,0,n+1) ans = max(ans, d[n-1][i][j]);
    
    cout<<ans;
}