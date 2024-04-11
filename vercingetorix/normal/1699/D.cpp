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

const int A = 5000;
int d[A][A];
int cnt[A];
int best[A];
const int INF = 1e8;

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
        forn(l,0,n) {
            forn(i,0,n) cnt[i] = 0;
            int mx = 0;
            forn(r,l,n) {
                mx = max(mx, ++cnt[a[r]]);
                d[l][r] = 0;
                if((r-l+1) >= mx*2 && (r-l)%2==1) d[l][r] = 1;
            }
        }
        
        forn(i,0,n) best[i] = -INF;
        forn(i,0,n) {
            if(i==0 || d[0][i-1]) best[i] = 1;
            forn(j,0,i) if(a[j] == a[i] && (j+1==i || d[j+1][i-1])) best[i] = max(best[i], best[j]+1);
        }
        int ans = 0;
        forn(i,0,n) if(i == n-1 || d[i+1][n-1]) ans = max(ans, best[i]);
        printf("%d\n", ans);
    }
    
    
}