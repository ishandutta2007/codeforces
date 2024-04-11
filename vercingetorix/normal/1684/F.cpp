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
        int n,m;
        scanf("%d %d", &n, &m);
        readv(a,n);
        vi er(n,-1);
        vi el(n,n+1);
        forn(i,0,n) {
            er[i] = i;
            el[i] = i;
        }
        forn(i,0,m) {
            int l,r;
            scanf("%d %d", &l, &r);
            --l; --r;
            er[l] = max(er[l], r);
            el[r] = min(el[r], l);
        }
        forn(i,1,n) er[i] = max(er[i], er[i-1]);
        for(int i = n-2; i>=0; i--) el[i] = min(el[i], el[i+1]);
        vi lto(n,-1);
        vi rto(n,n);
        map<int, int> last;
        forn(i,0,n) {
            auto it = last.find(a[i]);
            if(it != last.end()) lto[i] = it->second;
            last[a[i]] = i;
        }
        last.clear();
        for(int i = n-1; i>=0; i--) {
            auto it = last.find(a[i]);
            if(it != last.end()) rto[i] = it->second;
            last[a[i]] = i;
        }
        int minr = -1;
        forn(i,0,n) if(er[i] >= rto[i]) minr = max(minr, i);
        int ans = n;
        if(minr == -1) {
            printf("0\n");
            continue;
        }
        map<int, vi> pos;
        forn(i,0,n) pos[a[i]].pb(i);
        forn(l,0,n) {
            ans = min(ans, minr - l + 1);
            if(el[l] <= lto[l]) break;
            auto it = lower_bound(all(pos[a[l]]), er[l]+1);
            it--;
            minr = max(minr, *it);
        }
        printf("%d\n", ans);
    }
    
    
}