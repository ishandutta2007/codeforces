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

const int A = 51;
ll d[A][A];
vector<ld> nfac(1,1);

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,1,A) nfac.pb(nfac.back()*i);
    int n;
    read(n);
    readv(a,n);
    int tot = 0;
    forn(i,0,n) {
        tot += a[i];
    }
    int p;
    read(p);
    if(tot <= p) {
        cout<<n;
        exit(0);
    }
    ld ans = 0;
    forn(s,0,n) {
        forn(i,0,A) forn(j,0,A) d[i][j] = 0;
        d[0][0] = 1;
        forn(i,0,n) {
            if(s==i) continue;
            for(int was = i; was>=0; was--) forn(sum,0,p+1) if(sum+a[i] <= p) {
                d[was+1][sum+a[i]] += d[was][sum];
            }
        }
        forn(l,0,n) forn(sum,0,p+1) {
            if(sum + a[s] > p) {
                ans += d[l][sum]*nfac[l]*nfac[n-l-1]*l;
            }
        }
    }
    printf("%.10lf", (double)(ans/nfac[n]));
    
    
}