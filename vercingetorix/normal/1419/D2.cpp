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
    int n;
    read(n);
    readv(a,n);
    
    srt(a);
    vi b(n,-1);
    int l = 0;
    int r = (n+1)/2;
    while(r-l>=1) {
        int m = (r+l)/2;
        b = vi(n,-1);
        int pt = m;
        forn(i,0,m) b[1+2*i] = a[m-1-i];
        for(int i = n-1; i>=0; i-- ) if(b[i] == -1) b[i] = a[pt++];
        int can = 1;
        forn(i,0,m) {
            if(b[1+2*i] == b[2*i] || b[1+2*i] == b[2+2*i]) can = 0;
        }
        if(r-l==1) break;
        if(can) l = m;
        else r = m;
    }
    printf("%d\n", l);
    forn(i,0,n) printf("%d ", b[i]);
    
    
}