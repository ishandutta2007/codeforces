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

int add = 0;
const int INF = 1e7;
struct sega {
    sega(int l = INF, int r1 = -1, int r2 = -1) : l(l), r1(r1), r2(r2) {};
    int l;
    int r1, r2;
    
    void ul(int nl) {
        l = min(l, nl);
    }
    
    void ur(int n) {
        if(n > r2) {
            r1 = r2;
            r2 = n;
        }
        else if(n>r1 && n!=r2) r1 = n;
    }
    
    void up(int n) {
        ul(n);
        ur(n);
    }
    
    void update(sega & x) {
        l = min(l, x.l);
        ur(x.r1);
        ur(x.r2);
    }
};
const int nbit = 21;
sega bm[1<<nbit];

bool test(int m) {
    for (int s=m; ; s=(s-1)&m) {
        int s2 = m^s;
        if(bm[s].l < bm[s2].r1) return true;
        if(s==0) break;
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    int neg = (1<<nbit) - 1;
    forn(i,0,n) {
        bm[a[i]].up(i);
    }
    for(int mask = neg; mask>=0; mask--) {
        forn(bit,0,nbit) {
            if(mask&(1<<bit)) bm[mask^(1<<bit)].update(bm[mask]);
        }
    }
    int pref = 0;
    for(int bit = nbit-1; bit>=0; bit--) {
        if(test(pref + (1<<bit))) pref+=1<<bit;
    }
    cout<<pref;
    
}