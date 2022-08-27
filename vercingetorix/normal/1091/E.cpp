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

const long long mod = 998244353 ;
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
    int n;
    read(n);
    readv(a,n);
    srtrev(a);
    ll sum = 0;
    forn(i,0,n) sum += a[i];
    ll mx = 0;
    forn(i,0,n) if(a[i] > 0) mx++;
    vll sl(n);
    vll sr(n);
    sl[0] = a[0];
    forn(i,1,n) sl[i] = sl[i-1]+a[i];
    sr[n-1] = a[n-1];
    sr.pb(0);
    for(int i = n-2; i>=0; i--) sr[i] = sr[i+1] + a[i];
    ll mn = 0;
    int pt = 0;
    forn(k,1,n+1) {
        if(a[k-1] >= k-1) pt = k-1;
        else while(pt>=0 && a[pt] <= k-1) pt--;
        ll tor = 0;
        if(pt>=0) tor = sl[pt] - ll(pt+1)*(k-1);
        mn = max(mn, tor - sr[k]);
        int ptl = pt;
        while(ptl>=0 && a[ptl] == k-1) ptl--;
        mx = min(mx, pt+k+sr[k]-tor+1);
    }
    vi ans;
    for(ll i= mn; i < min(sum,mx)+1; i++) {
        if(i%2 == sum%2 && i<=n) ans.pb(i);
    }
    if(ans.empty()) ans.pb(-1);
    for(auto x : ans) printf("%d ",x);
    
    
}