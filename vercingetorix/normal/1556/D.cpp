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

int askor(int i, int j) {
    printf("or %d %d\n", i+1, j+1);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int askand(int i, int j) {
    printf("and %d %d\n", i+1, j+1);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vi a(n);
    vi b(n);
    vi d2(1,1);
    forn(i,0,30) d2.pb(d2.back() * 2);
    vi bits(30, -1);
    forn(i,1,n) {
        a[i] = askor(i, 0);
        b[i] = askand(i, 0);
        forn(bit,0,30) {
            if(b[i]&d2[bit]) bits[bit] = 1;
            if((a[i]&d2[bit])==0) bits[bit] = 0;
        }
    }
    int rnd = askor(1, 2);
    forn(bit,0,30) if(bits[bit] == -1) {
        if(rnd&d2[bit]) bits[bit] = 0;
        else bits[bit] = 1;
    }
    int a0 = 0;
    forn(i,0,30) if(bits[i]) a0 |= d2[i];
    vi x(n);
    x[0] = a0;
    forn(i,1,n) x[i] = a[i] + b[i] - x[0];
    srt(x);
    printf("finish %d\n", x[k-1]);
    
    
}