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
int d[1<<15][11][16];
int p[1<<15][11][16];
const int INF = 1e9;
vi bits[1<<15];
int cost[1<<15];
int sum[1<<15];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(mask,0,1<<15) forn(bit,0,15) if(mask&(1<<bit)) bits[mask].pb(bit);
    forn(mask,0,1<<15) cost[mask] = __builtin_popcount(mask) - 1;
    int ta;
    read(ta);
    bits[0].pb(-1);
    cost[0] = 0;
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        
        forn(mask,1,1<<n) {
            sum[mask] = a[bits[mask][0]] + sum[mask^(1<<bits[mask][0])];
        }
        forn(mask,0,1<<n) forn(op,0,11) forn(i,0,n+1) d[mask][op][i] = INF;
        int fm = (1<<n) - 1;
        d[0][0][0] = 0;
        forn(mask,0,1<<n) {
            int mask2 = fm^mask;
            for (int s=mask2; s; s=(s-1)&mask2) {
                int cursum = sum[s];
                int pt = 0;
                for(auto e : bits[mask]) {
                    while(pt < bits[s].size() && bits[s][pt] <= e) pt++;
                    if(pt == bits[s].size()) break;
                    int now = bits[s][pt]+1;
                    int op2 = cost[s];
                    for(int op = min(10-op2, cost[mask]); op >= 0; op--) {
                        if(cursum > d[mask][op][e+1]) {
                            if(d[mask|s][op+op2][now] > cursum) {
                                d[mask|s][op+op2][now] = cursum;
                                p[mask|s][op+op2][now] = ((e+1)<<15) + s;
                            }
                        }
                    }
                }
            }
        }
        int done = 0;
        forn(op,0,11) {
            forn(e,1,n+1) {
                if(d[fm][op][e] < INF) {
                    printf("%d\n", op);
                    int m = fm;
                    vpi q;
                    while(m != 0) {
                        int to = p[m][op][e];
                        int mu = to&fm;
                        for(auto x : bits[mu]) if(x!=e-1) {
                            q.pb(mp(x+1,e));
                        }
                        op -= cost[mu];
                        m ^= mu;
                        e = to>>15;
                    }
                    vi tr;
                    forn(i,0,n+1) tr.pb(i);
                    for(auto x : q) {
                        printf("%d %d\n", tr[x.first], tr[x.second]);
                        forn(i,x.first,n+1) tr[i]--;
                    }
                    done = 1;
                    break;
                }
            }
            if(done) break;
        }
    }
    
    
}