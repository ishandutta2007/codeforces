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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll a,b,c;
    cin>>a>>b>>c;
    ll x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
//    ll x,y;
//    ll d = gcd(abs(a), abs(b), x, y);
    if(a == 0 || b == 0) {
        cout<<abs(x1-x2) + abs(y1-y2);
        exit(0);
    }
//    a/=d;
//    b/=d;
//    c/=d;
//    gcd(a,b,x,y);
//    if(a < 0) x= -x;
//    if(b<0) y=-y;
//    x*=-c;
//    y*=-c;
//    cout<<x<<' '<<y;
    ld ans = abs(x1-x2) + abs(y1-y2);
    ld px1[2];
    ld py1[2];
    ld px2[2];
    ld py2[2];
    px1[0] = x1;
    py1[0] = -ld(a*x1+c)/b;
    px1[1] = -ld(b*y1+c)/a;
    py1[1] = y1;
    px2[0] = x2;
    py2[0] = -ld(a*x2+c)/b;
    px2[1] = -ld(b*y2+c)/a;
    py2[1] = y2;
    forn(i,0,2) forn(j,0,2) ans = min(ans, dist(x1,y1,px1[i],py1[i]) + dist(px1[i],py1[i],px2[j],py2[j]) + dist(px2[j],py2[j],x2,y2));
    printf("%.10lf", (double) ans);
    
}