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
    read(ta);
    forn(ifa,0,ta) {
        int n,k;
        scanf("%d %d", &n, &k);
        readv(a,n);
        vi b = a;
        srt(b);
        int need = (n+k+1)/2;
        pi best = mp(b[0], b.back());
        forn(i,0,n-need+1) {
            if(b[i+need-1] - b[i] < best.second - best.first) {
                best = mp(b[i], b[i+need-1]);
            }
        }
        printf("%d %d\n", best.first, best.second);
        int pt = 0;
        vpi ans;
        int l = best.first;
        int r = best.second;
        forn(i,0,k) {
            int cur = 0;
            int pr = pt;
            while(cur<=0) {
                if(a[pr] >= l && a[pr] <= r) cur++;
                else cur--;
                pr++;
            }
            ans.pb(mp(pt+1, pr));
            pt = pr;
        }
        ans.back().second = n;
        for(auto x : ans) printf("%d %d\n", x.first, x.second);
    }
    
    
}