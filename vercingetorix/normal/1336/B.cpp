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
    int t;
    read(t);
    forn(ifa,0,t) {
        int n[3];
        scanf("%d %d %d", &n[0], &n[1], &n[2]);
        vvi a(3);
        forn(i,0,3) a[i].resize(n[i]);
        forn(i,0,3) {
            forn(k,0,n[i]) scanf("%d", &a[i][k]);
            srt(a[i]);
        }
        vi perm;
        forn(i,0,3) perm.pb(i);
        ll ans = 5e18;
        do {
            int l = perm[0];
            int m = perm[1];
            int r = perm[2];
            forn(i,0,n[m]) {
                int mid = a[m][i];
                auto it = lower_bound(all(a[l]), mid);
                if(it == a[l].end()) break;
                int rig = *it;
                it = lower_bound(all(a[r]), mid+1);
                if(it == a[r].begin()) continue;
                it--;
                int lef = *it;
                ans = min(ans, ll(mid-lef)*(mid-lef) + ll(mid-rig)*(mid-rig) + ll(rig-lef)*(rig-lef));
            }
        } while(next_permutation(all(perm)));
        
        printf("%lld\n", ans);
        
    }
    
    
}