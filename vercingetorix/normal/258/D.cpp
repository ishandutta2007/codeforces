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
const int A = 1000;
double d[A][A];
double sump[A];
double pref[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(v,n);
    forn(i,0,n) v[i]--;
    forn(i,0,n) d[i][v[i]] = 1;
    double ans = 0;
    forn(it,0,m) {
        int a,b;
        scanf("%d %d", &a, &b);
        a--; b--;
        double pe = 0;
        forn(i,0,n) {
            pe += d[a][i] * d[b][i];
            d[a][i] = (d[a][i]+d[b][i])/2;
            d[b][i] = d[a][i];
        }
        ans += (1-pe)/2;
        pe = 0;
        forn(i,0,n) pe+=d[a][i]*d[a][i];
        ans -= (1-pe)/2;
    }
    
    const double eps = 1e-12;
//    forn(i,0,n) {
//        forn(j,0,n) cout<<d[i][j]<<' '; cout<<'\n';
//    }
    double sp = 0;
    for(int i = n-1; i>=0; i--) {
        forn(j,1,n) {
//            double badp = pref[j] - pref[j-1];
//            if(badp < sp-eps) {
                ans += d[i][j] * pref[j-1];
//            ans += d[i][j] * (pref[j-1]+pref[j]/2);
//                ans += d[i][j]*pref[j-1]*(sp/(sp-badp));
//            }
        }
        double cur = 0;
        forn(j,0,n) {
            sump[j] += d[i][j];
            cur += d[i][j];
            pref[j] += cur;
            sp += cur;
        }
    }
    printf("%.12lf", ans);
    
}