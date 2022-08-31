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
const int A = 1005;
const double INF = 1e20;
double d[101][A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    double decay = 0.9;
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        double c,t;
        scanf("%lf %lf", &c, &t);
        forn(j,0,101) forn(i,0,A) d[j][i] = INF;
        d[0][0] = 0;
        vi a(n), p(n);
        vpi ord;
        forn(i,0,n) {
            scanf("%d %d", &a[i], &p[i]);
            ord.pb(mp(a[i], i));
        }
        srt(ord);
        forn(i,0,n) {
            int ind = ord[i].second;
            int add = p[ind];
            int dif = a[ind];
            for(int was = i; was >=0; was--) {
                forn(score,0,was*10+1) {
                    d[was+1][score + add] = min(d[was+1][score+add], d[was][score]/decay + dif);
                }
            }
        }
        int ans = 0;
        forn(num,0,n+1) {
            forn(score,0,num*10+1) {
                double tt = num*10 + 2*sqrt(d[num][score]/(c*decay))-1/c;
                if(sqrt(d[num][score]/(c*decay)) < 1/c) {
                    tt= num*10+d[num][score]/decay;
                }
                if(tt < t) ans = max(ans, score);
            }
        }
        printf("%d\n", ans);
    }
    
    
}