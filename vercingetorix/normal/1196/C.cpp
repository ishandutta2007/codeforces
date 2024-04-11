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
        int n;
        scanf("%d", &n);
        vi x(n), y(n);
        vvi f(n, vi(4));
        vpi r,c;
        forn(i,0,n) {
            scanf("%d %d %d %d %d %d", &x[i], &y[i], &f[i][0], &f[i][1], &f[i][2], &f[i][3]);
            r.pb(mp(x[i], i));
            c.pb(mp(y[i], i));
        }
        srt(r);
        srt(c);
        int fr = 100000;
        int fl = -100000;
        int fu = 100000;
        int fd = -100000;
        forn(it,0,n) {
            int i = r[it].second;
            if(f[i][2] == 0) {
                fr = x[i];
                break;
            }
        }
        for(int it = n-1; it>=0; it--) {
            int i = r[it].second;
            if(f[i][0] == 0) {
                fl = x[i];
                break;
            }
        }
        forn(it,0,n) {
            int i = c[it].second;
            if(f[i][1] == 0) {
                fu = y[i];
                break;
            }
        }
        for(int it = n-1; it>=0; it--) {
            int i = c[it].second;
            if(f[i][3] == 0) {
                fd = y[i];
                break;
            }
        }
        if(fr < fl || fu < fd) {
            printf("0\n");
        }
        else printf("1 %d %d\n", fr, fu);
        
    }
    
    
}