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
    vi d2(1,1);
    forn(i,0,31) d2.pb(d2.back() * 2);
    int t;
    read(t);
    forn(ifa,0,t) {
        int n;
        scanf("%d", &n);
        if(n%4 != 0) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        vi a;
        vi b;
        int l = 4*n;
        int r = 4*n+4;
        forn(i,0,n/4) {
            a.pb(l);
            a.pb(r);
            b.pb(l+1);
            b.pb(r-1);
            l-=2;
            r+=2;
        }
        for(auto x : a) printf("%d ", x);
        for(auto x : b) printf("%d ", x);
        printf("\n");
    }
    
    
}