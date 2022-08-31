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
        vll a(n);
        forn(i,0,n) scanf("%lld", &a[i]);
        int bad = 0;
        if(a[n-2] > a[n-1]) bad = 1;
        vi x,y,z;
        for(int i = n-3; i>=0; i--) {
            if(a[i] > a[i+1]) {
                x.pb(i);
                y.pb(i+1);
                z.pb(n-1);
                a[i] = a[i+1] - a[n-1];
                if(a[i] > a[i+1]) bad = 1;
            }
        }
        if(bad) printf("-1\n");
        else {
            printf("%d\n", x.size());
            forn(i,0,x.size()) {
                printf("%d %d %d\n", x[i]+1,y[i]+1,z[i]+1);
            }
        }
    }
    
    
}