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
        int n,x;
        scanf("%d %d", &n, &x);
        readv(a,n);
        int sr = 1;
        forn(i,1,n) if(a[i] < a[i-1]) sr = 0;
        if(sr) {
            printf("0\n");
            continue;
        }
        int ans = 2*n;
        forn(skip,0,n) {
            vi b;
            forn(i,0,n) if(i != skip) b.pb(a[i]);
            b.pb(x);
            srt(b);
            vi c;
            c.pb(x);
            forn(i,0,n) {
                if(a[i] != b[i]) c.pb(a[i]);
            }
            sr = 1;
            forn(i,1,c.size()) if(c[i] < c[i-1]) sr = 0;
            if(sr) ans = min(ans, (int)c.size() - 1);
        }
        if(ans == 2*n) ans = -1;
        printf("%d\n", ans);
    }
    
    
}