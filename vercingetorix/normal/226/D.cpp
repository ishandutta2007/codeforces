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
const int A = 100;
int a[A][A];
int r[A];
int c[A];
int fr[A];
int fc[A];

bitset<A> br, bc;
int n,m;
void fliprow(int i) {
    br[i] = 0;
    fr[i]^=1;
    r[i] = -r[i];
    forn(j,0,m) {
        a[i][j] = -a[i][j];
        c[j] += 2*a[i][j];
        bc[j] = (c[j]<0);
    }
}

void flipcol(int j) {
    bc[j] = 0;
    fc[j]^=1;
    c[j] = -c[j];
    forn(i,0,n) {
        a[i][j] = -a[i][j];
        r[i] += 2*a[i][j];
        br[i] = (r[i]<0);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    forn(i,0,n) forn(j,0,m) {
        scanf("%d", &a[i][j]);
        r[i] += a[i][j];
        c[j] += a[i][j];
    }
    forn(i,0,n) if(r[i] < 0) br[i] = 1;
    forn(i,0,m) if(c[i] < 0) bc[i] = 1;
    while(1) {
        if(br.count()) {
            int i = br._Find_first();
            fliprow(i);
        }
        else if(bc.count()) {
            int j = bc._Find_first();
            flipcol(j);
        }
        else break;
    }
    int sr = 0, sc = 0;
    forn(i,0,n) sr+=fr[i];
    forn(j,0,m) sc+=fc[j];
    printf("%d", sr);
    forn(i,0,n) if(fr[i]) printf(" %d", i+1);
    printf("\n");
    printf("%d", sc);
    forn(i,0,m) if(fc[i]) printf(" %d", i+1);
    printf("\n");
}