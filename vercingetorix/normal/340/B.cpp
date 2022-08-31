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
vi x,y;
ll s32(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

ll s3(int i, int j, int k) {
    return (s32(x[i], y[i], x[j], y[j], x[k], y[k]));
}

bool cw(int i, int j, int k) {
    return s3(i,j,k) < 0;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) scanf("%d %d", &x[i], &y[i]);
    ll ans = 0;
    forn(i,0,n) forn(j,0,n) {
        ll b1 = -1;
        ll b2 = -1;
        forn(k,0,n) {
            if(cw(i,j,k)) {
                b1 = max(b1, abs(s3(i,j,k)));
            }
            else {
                b2 = max(b2, abs(s3(i,j,k)));
            }
        }
        if(b1>0 && b2>0) ans = max(ans, b1+b2);
    }
    printf("%.2lf", double(ans)/2);
    
    
}