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

const int A = 5001;
int l[A][A];
int r[A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        forn(i,0,n) a[i]--;
        forn(i,0,n) forn(j,0,n) {
            l[i][j] = 0;
            r[i][j] = 0;
        }
        forn(i,0,n) {
            if(i > 0) {
                forn(j,0,n) l[i][j] = l[i-1][j];
            }
            forn(j,a[i]+1,n) l[i][j]++;
        }
        for(int i = n-1; i>=0; i--) {
            if(i < n-1) {
                forn(j,0,n) r[i][j] = r[i+1][j];
            }
            forn(j,a[i]+1,n) r[i][j]++;
        }
        ll ans = 0;
        forn(b,1,n-1) forn(c,b+1,n-1) {
            ans += l[b-1][a[c]]*r[c+1][a[b]];
        }
        printf("%lld\n", ans);
        
    }
    
    
}