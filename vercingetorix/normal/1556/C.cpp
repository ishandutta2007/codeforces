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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    int t;
//    read(t);
//    forn(ifa,0,t) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        vvll wdr(n, vll(n, 0));
        vvll wul(n, vll(n, 0));
        vvll sum(n, vll(n, 0));
        for(int len = 2; len <= n; len+=2) {
            for(int l = 1; l + len <= n; l += 2) {
                wdr[l][l+len-1] = a[l];
                if(l+2<n) wdr[l][l+len-1] = max((ll)a[l], wdr[l+2][l+len-1] + a[l] - a[l+1]);
//                wul[l][l+len-1] = a[l+len-1];
                wul[l][l+len-1] = max((ll)a[l+len-1], wul[l][l+len-3] + a[l+len-1] - a[l+len-2]);
                sum[l][l+len-1] = a[l];
                if(l+1 < n) sum[l][l+len-1] -= a[l+1];
                if(l+2<n) sum[l][l+len-1] = sum[l+2][l+len-1] + a[l] - a[l+1];
            }
        }
        ll ans = 0;
        for(int l = 0; l<n; l+=2) {
            for(int r = l+1; r < n; r += 2) {
                ll minl = wdr[l+1][r-1];
                ll minr = wul[l+1][r-1];
                ll s = sum[l+1][r-1];
                ll maxl = a[l];
                ll maxr = a[r];
                ll minv = max(minr, minl - s);
                minv = max(minv,1ll);
                ll maxv = min(maxr, maxl - s);
                if(maxv >= minv) ans += maxv-minv+1;
                
                
            }
        }
        printf("%lld", ans);
//    }
    
    
}