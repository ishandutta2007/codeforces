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
vpi ans;
void go(const vpi & x) {
    int n = x.size();
    int k = x.back().first;
    if(k==2) {
        forn(i,0,n-1) ans.pb(mp(x[i].second, x[i+1].second));
        return;
    }
    int pt = 0;
    while(pt < n-1 && x[pt+1].first*x[pt+1].first <= k) pt++;
    forn(i,pt+1,n-1) ans.pb(mp(x[i].second, x[i+1].second));
//    printf("%d %d", x[i].second, x[i+1].second);
    vpi y;
    forn(i,0,pt+1) y.pb(x[i]);
    ans.pb(mp(x[n-1].second, x[pt].second));
//    printf("%d %d", x[n-1].second, x[pt].second);
    y.pb(mp((x[n-1].first + x[pt].first-1) / x[pt].first, x[n-1].second));
    srt(y);
    go(y);
}

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
        vpi x;
        forn(i,2,n+1) {
            x.pb(mp(i,i));
        }
        ans.clear();
        go(x);
        printf("%d\n", ans.size());
        forn(i,0,ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
    }
    
    
}