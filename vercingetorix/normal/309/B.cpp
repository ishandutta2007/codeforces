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
#ifdef LOCAL
const int A = 20;
#else
const int A = 1000500;
#endif
int d[20][A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r,c;
    scanf("%d %d %d\n", &n, &r, &c);
    string s;
    getline(cin, s);
    int pt = 0;
    vs a;
    forn(it,0,n) {
        int st = pt;
        while(pt < s.size() && s[pt]!=' ') pt++;
        a.pb(s.substr(st,pt-st));
        pt++;
    }
    int to = 0;
    int len = 0;
    forn(l,0,n) {
        if(to < l) to++;
        if(to == l && a[to].size() <= c) {
            len = a[to].size();
            to++;
        }
        while(to<n && a[to].size() + 1 + len <= c) {
            len += a[to++].size() + 1;
        }
        d[0][l] = to;
        if(to != l) {
            len -= a[l].size();
            if(to != l+1) len--;
        }
    }
    d[0][n] = n;
    forn(l,1,20) forn(i,0,n+1) d[l][i] = d[l-1][d[l-1][i]];
    vi bits;
    forn(i,0,20) if(r&(1<<i)) bits.pb(i);
    int best = 0;
    int f = 0;
    forn(i,0,n) {
        int r = i;
        for(auto l : bits) r = d[l][r];
        if(r-i>best) {
            best = r-i;
            f = i;
        }
    }
    forn(it,0,r) {
        if(d[0][f] != f) {
            printf("%s", a[f].c_str());
            forn(i,f+1,d[0][f]) printf(" %s", a[i].c_str());
            printf("\n");
            f = d[0][f];
        }
    }
    
    
}