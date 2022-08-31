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
//#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
//#endif
    int n;
    read(n);
    readv(a,n);
    int m;
    read(m);
    readv(b,m);
    int p1 = n-1;
    int p2 = m-1;
    int cur = 0;
    vi ord;
    vi vals;
    while(p1 >=0 || p2>=0) {
        while(p1>=0 && a[p1] == cur) {
            vals.pb(cur);
            ord.pb((p1--)+1);
        }
        while(p2>=0 && b[p2] == cur) {
            vals.pb(cur);
            ord.pb((p2--)+1+n);
        }
        cur^=1;
    }
    reverse(all(ord));
    reverse(all(vals));
    for(auto x : ord) printf("%d ", x);
    printf("\n");
    vi flip;
    forn(i,1,n+m) if(vals[i] != vals[i-1]) flip.pb(i);
    if(vals.back() != 0) flip.pb(n+m);
    printf("%d\n", flip.size());
    for(auto x : flip) printf("%d ", x );
    
}