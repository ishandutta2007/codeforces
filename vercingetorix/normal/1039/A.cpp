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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair
void no() {
    printf("No\n");
    exit(0);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    ll t;
    scanf("%d %lld", &n, &t);
    readv(a,n);
    readv(x,n);
    forn(i,0,n) x[i]--;
    forn(i,0,n) if(x[i] < i) no();
    forn(i,1,n) if(x[i] < x[i-1]) no();
    int can = 1;
    vll b(n);
    forn(i,0,n) {
        if(x[i] > i) b[i] = a[i+1];
        else {
            b[i] = a[i];
        }
        if(i>0 && b[i] <= b[i-1]) {
            b[i] = b[i-1] + 1;
            if(i<n-1 && a[i+1] <= b[i]) no();
        }
    }
    forn(i,1,n) {
        if(x[i] > x[i-1] && b[i-1] >= a[i]) no();
    }
    printf("Yes\n");
    forn(i,0,n) printf("%lld ", b[i]+t);
    
    
}