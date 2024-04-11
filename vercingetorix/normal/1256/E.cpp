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
    int n;
    read(n);
    readv(a,n);
    vpi q;
    forn(i,0,n) q.pb(mp(a[i], i));
    srt(q);
    const ll INF = 1e18;
    vll d(n+1,INF);
    vi pr(n+1);
    d[0] = 0;
    pr[0] = 0;
    forn(i,3,n+1) {
        forn(p,i-4,i-1) {
            if(p>0) {
                ll add = q[i-1].first - q[p-1].first;
                if(d[i] > d[p-1] + add) {
                    d[i] = d[p-1] + add;
                    pr[i] = p-1;
                }
            }
        }
    }
    int r = n;
    int cnum = 1;
    vi ans(n, 0);
    while(r > 0) {
        int nr = pr[r];
        forn(i,nr, r) {
            ans[q[i].second] = cnum;
        }
        cnum++;
        r = nr;
    }
    printf("%lld %d\n", d[n], cnum-1);
    forn(i,0,n) printf("%d ", ans[i]);
    printf("\n");
    
    
    
}