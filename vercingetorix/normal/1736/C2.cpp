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
    vi al, ar, ar2;
    int n;
    scanf("%d", &n);
    readv(a,n);
    int r = 0;
    int r2 = 0;
    ll ans = 0;
    forn(l,0,n) {
        if(r < l) r = l;
        while(r<n && a[r] >= r-l+1) r++;
        if(r2 <= r && r<n) r2 = r+1;
        while(r2<n && a[r2] >= r2-l+1) r2++;
        al.pb(l);
        ar.pb(r);
        ar2.pb(r2);
        ans += (r-l);
    }
    vll bar(1,0);
    forn(i,0,n) bar.pb(bar.back() + ar[i]);
    vll bar2(1,0);
    forn(i,0,n) bar2.pb(bar2.back() + ar2[i]);
    int qq;
    read(qq);
    while(qq--) {
        int i, x;
        scanf("%d %d", &i, &x);
        --i;
        int p = lower_bound(all(ar), i)  - ar.begin();
        int q = upper_bound(all(ar), i)  - ar.begin();
        if(x > a[i]) {
            p = max(p, i+1-x);
            if(p>q) p=q=0;
            printf("%lld\n", ans + bar2[q] - bar2[p] - bar[q] + bar[p]);
        }
        else {
            int q2 = max(i+1-x,q);
            printf("%lld\n", ans - bar[q2] + bar[q] + ll(q2-q)*i);
        }
//        else printf("%lld\n", ans);
    }
//
    
    
}