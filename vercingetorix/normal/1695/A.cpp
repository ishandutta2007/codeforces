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
    cin>>ta;
    forn(ifa,0,ta) {
        int n,m;
        cin>>n>>m;
        vvi a(n, vi(m));
        forn(i,0,n) forn(j,0,m) cin>>a[i][j];
        int mx = -2e9;
        forn(i,0,n) forn(j,0,m) mx = max(mx, a[i][j]);
        int ans = n*m;
        vvi good(n+1, vi(m+1, 1));
        forn(l,0,n) forn(r,l,n) {
            int w = r-l+1;
            int cur = 0;
            forn(j,0,m) {
                int bad = 0;
                forn(i,l,r+1) if(a[i][j] == mx) bad = 1;
                if(bad) cur = 0;
                else cur++;
                good[w][cur] = 0;
            }
        }
        forn(i,1,n+1) forn(j,1,m+1) if(good[i][j])
            ans = min(ans, i*j);
        printf("%d\n", ans);
    }
    
    
}