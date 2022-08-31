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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(p,n);
        srtrev(p);
        int pt = 0;
        int x,a,y,b;
        scanf("%d %d %d %d", &x, &a, &y, &b);
        ll k;
        scanf("%lld", &k);
        ll ab = ll(a)/gcd(a,b) * b;
        if(x>y) {
            swap(a,b);
            swap(x,y);
        }
        int l = 0;
        int r = n;
        ll cand = 0;
        for(ll i = ab; i <= n; i+=ab) {
            cand += p[pt++]/100 * (x+y);
        }
        for(int i = b; i <= n; i+=b) {
            if(i%a == 0) continue;
            cand += p[pt++]/100 * y;
        }
        for(int i = a; i <= n; i+=a) {
            if(i%b == 0) continue;
            cand += p[pt++]/100 * x;
        }
        if(cand < k) {
            printf("-1\n");
            continue;
        }
        while(r-l>1) {
            int m = (r+l)/2;
            pt=0;
            cand = 0;
            for(ll i = ab; i <= m; i+=ab) {
                cand += p[pt++]/100 * (x+y);
            }
            for(int i = b; i <= m; i+=b) {
                if(i%a == 0) continue;
                cand += p[pt++]/100 * y;
            }
            for(int i = a; i <= m; i+=a) {
                if(i%b == 0) continue;
                cand += p[pt++]/100 * x;
            }
            if(cand >= k) r = m;
            else l = m;
        }
        printf("%d\n", r);
        
    }
    
    
}