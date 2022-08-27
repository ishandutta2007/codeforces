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
    ll w,h,a;
    cin>>w>>h>>a;
    if(h>w) swap(h,w);
    if(a>90) a = 180-a;
    if(a == 90) {
        cout<<h*h;
        exit(0);
    }
    if(a==0) {
        cout<<w*h;
        exit(0);
    }
    ld ang = acos(ld(-1.))/180*a;
    double ans = ll(w)*h;
    ld h1 = (w*sin(ang)+h*cos(ang)-h)/2;
    ans -= h1*h1/sin(ang)/cos(ang);
    ld h2 = (w*sin(ang)-h*cos(ang)-h)/2;
    if(h2 > 0) ans += h2*h2/sin(ang)/cos(ang);
    else {
        ld w2 = (h*sin(ang)+w*cos(ang)-w)/2;
        ans -= w2*w2/sin(ang)/cos(ang);
    }
    printf("%.10lf", (double) ans);
    
    
    
}