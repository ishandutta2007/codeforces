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
int n;
vi b;

vi a;

void yes() {
    printf("YES\n");
    for(auto x : a) printf("%d ", x);
    exit(0);
}

void no() {
    printf("NO\n");
    exit(0);
}

void fill(int f) {
    forn(i,f,n) {
        a.pb(b[i] - a[0]);
    }
}

int w[15*1000000];

void get(int mask1, int mask2) {
    int sm = mask1&mask2;
    mask1 ^= sm;
    mask2 ^= sm;
    int l = __builtin_popcount(mask1);
    vi a1, a2;
    vi fr;
    forn(i,0,min(30,n)) {
        if((1<<i)&mask1) a1.pb(b[i]);
        else if((1<<i)&mask2) a2.pb(b[i]);
        else fr.pb(b[i]);
    }
    forn(i,2*l,min(30,n)) b[i] = fr[i-2*l];
    vi zp;
    forn(i,0,l) {
        zp.pb(a1[i]);
        zp.pb(a2[i]);
    }
    int last = 0;
    forn(i,0,2*l) {
        a.pb(zp[i]-last);
        last = a.back();
    }
    fill(2*l);
    yes();
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    b.resize(n);
    forn(i,0,n) scanf("%d", &b[i]);
    forn(i,0,n) if(b[i] % 2 == 0) swap(b[0], b[i]);
    if(n == 2) {
        if(b[0] != b[1]) no();
        else {
            a.pb(0);
            a.pb(b[0]);
            yes();
        }
    }
    if(b[0] % 2 == 0) {
        if(n>=4) {
            if(b[1]%2 == b[3]%2) swap(b[2], b[3]);
            if(b[2]%2 == b[3]%2) swap(b[1], b[3]);
        }
        if(b[1]%2 == b[2]%2) {
            int sum = b[0]+b[1]+b[2];
            forn(i,0,3) a.pb((sum-2*b[i])/2);
            fill(3);
            yes();
        }
        if(b[2]==b[1]) swap(b[2],b[0]);
        if(b[2] ==b[0]) swap(b[1],b[2]);
        if(b[0]==b[1]) {
            a.pb(0);
            a.pb(b[0]);
            fill(2);
            yes();
        }
    }

    int tbit = min(n/2, 14);
    const int A = 1000000;
    forn(i,0,tbit*A+1) w[i] = -1;
    forn(mask,0,1<<(min(n,28))) {
        if(__builtin_popcount(mask) == tbit) {
            int cur = 0;
            forn(bit,0,min(n,28)) if(mask&(1<<bit)) cur += b[bit];
            if(w[cur] != -1) get(w[cur], mask);
            else w[cur] = mask;
        }
    }
    no();
    
    
}