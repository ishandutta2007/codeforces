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
    int n,m;
    cin>>n>>m;
    vs d(n);
    forn(i,0,n) cin>>d[i];
    vpi ans;
    forn(a,1,n+1) forn(b,1,m+1) if(n%a==0 && m%b==0) {
        vs cand;
        for(int i = 0; i < n; i+=a) for(int j = 0; j < m; j += b) {
            string cur;
            forn(sx,0,a) forn(sy,0,b) cur.pb(d[i+sx][j+sy]);
            string mn = cur;
            reverse(all(cur));
            mn = min(mn, cur);
            if(a == b) {
                cur.clear();
                for(int sy = b-1; sy>=0; sy--) forn(sx,0,a) cur.pb(d[i+sx][j+sy]);
                mn = min(mn, cur);
                reverse(all(cur));
                mn = min(mn, cur);
            }
            cand.pb(mn);
        }
        srt(cand);
        int good = 1;
        forn(i,1,cand.size()) if(cand[i] == cand[i-1]) good = 0;
        if(good) ans.pb(mp(a,b));
    }
//    for(auto x : ans) printf("%d %d\n", x.first, x.second);
    int x = ans[0].first;
    int y = ans[0].second;
    printf("%d\n", ans.size());
    for(auto z : ans) {
        if(z.first * z.second < x*y || (z.first*z.second == x*y && z.first < x)) {
            x = z.first;
            y = z.second;
        }
    }
    printf("%d %d\n", x, y);
    
    
    
}