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

//typedef long long ll;
typedef __int128 ll;
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
int n;
long long b,s;

pll a;

bool pless(pll x, pll y) {
    if(x.first >= y.first && x.second >= y.second) return false;
    if(x.first <= y.first && x.second <= y.second) return true;
    if(x.second > y.second) {
        ll R = x.first*b*b + y.first*b*b - (x.second - y.second)*(x.second - y.second)*s*s;
        if(R < 0) return false;
        R *= R;
        ll L = 4*b*b*b*b*x.first*y.first;
        if(R>L) return true;
        if(R<L) return false;
        if(x.first < y.first) return true;
        return false;
    }
    cout<<"clown fiesta";
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %lld %lld", &n, &b, &s);
    readv(p,n);
//    cout<<p[8]<<' '<<p[15];
    long long xx,yy;
    scanf("%lld %lld", &xx, &yy);
    ll x = xx;
    ll y = yy;
    a = mp((x-p[1])*(x-p[1])+y*y, p[1]);
    forn(i,2,n) {
        pll c = mp((x-p[i])*(x-p[i]) + y*y, p[i]);
        if(pless(c, a)) a = c;
    }
    int pt = 0;
    while(p[pt] != a.second) pt++;
    cout<<pt+1;
    
    
}