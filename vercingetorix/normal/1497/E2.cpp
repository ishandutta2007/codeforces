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
const int N = 10000011;
int did[N];
int fto[21][200500];
int d[21][200500];
//int fto[21][20];
//int d[21][20];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    vi sqf(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    sqf[1] = 1;
    forn(i,2,N) {
        int m = i / mindiv[i];
        if(m%mindiv[i] == 0) sqf[i] = sqf[m/mindiv[i]];
        else sqf[i] = sqf[m] * mindiv[i];
    }
    
    int t;
    read(t);
    forn(ifa,0,t) {
        int n,k;
        scanf("%d %d", &n, &k);
        readv(a,n);
        forn(i,0,n) a[i] = sqf[a[i]];
        
        forn(nc,0,k+1) {
            int conf = 0;
            int r = 0;
            int l = 0;
            while(l < n) {
                while(r<n && (did[a[r]] == 0 || conf < nc)) {
                    if(did[a[r]] > 0) conf++;
                    did[a[r]]++;
                    r++;
                }
                fto[nc][l] = r;
                did[a[l]]--;
                if(did[a[l]] > 0) conf--;
                l++;
            }
        }
        forn(i,0,k+1) {
            d[i][n] = 0;
            forn(j,0,n) d[i][j] = n;
        }
        for(int i = n-1; i>=0; i--) {
            forn(hv,0,k+1) forn(tk,0,hv+1) {
                d[hv][i] = min(d[hv][i], 1+d[hv-tk][fto[tk][i]]);
            }
        }
        int ans = n;
        forn(i,0,k+1) ans = min(ans, d[i][0]);
        printf("%d\n", ans);
        
        
        
    }
    
    
}