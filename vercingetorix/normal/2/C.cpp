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
ld sq(ld x) {
    return x*x;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vll x(3), y(3), r(3);
    forn(i,0,3) cin>>x[i]>>y[i]>>r[i];
    if(r[0] == r[1]) {
        swap(r[1],r[2]);
        swap(x[1],x[2]);
        swap(y[1],y[2]);
    }
    vll d2(3);
    forn(i,0,3) d2[i] = x[i]*x[i] + y[i]*y[i];
    ll A = 0;
    ll B = 0;
    ll C = 0;
    int done = 0;
    for(auto i : {1,2,0}) if(r[i] == r[(i+1)%3]) {
        A = 2*x[(i+1)%3]-2*x[i];
        B = 2*y[(i+1)%3]-2*y[i];
        C = d2[i] - d2[(i+1)%3];
        done = 1;
        break;
    }
    if(done == 0) {
        forn(i,0,3) A += 2*x[(i+1)%3]*r[i]*r[i] - 2*x[i]*r[(i+1)%3]*r[(i+1)%3];
        forn(i,0,3) B += 2*y[(i+1)%3]*r[i]*r[i] - 2*y[i]*r[(i+1)%3]*r[(i+1)%3];
        forn(i,0,3) C += d2[i]*r[(i+1)%3]*r[(i+1)%3] - r[i]*r[i]*d2[(i+1)%3];
    }
    // Ax + By + C = 0;
    int sw = 0;
    vector<ld> ay;
    vector<ld> ax;
    if(A== 0 && B == 0) {
        if(C!=0) exit(0);
    }
    else {
        if(A == 0) {
            swap(A,B);
            sw = 1;
            swap(x,y);
        }
        ll cx2 = r[1]*r[1]-r[0]*r[0];
        ll cx = 2*(x[1]*r[0]*r[0]-x[0]*r[1]*r[1]);
        ll cy2 = r[1]*r[1]-r[0]*r[0];
        ll cy = 2*(y[1]*r[0]*r[0]-y[0]*r[1]*r[1]);
        ld c = d2[0]*r[1]*r[1]-d2[1]*r[0]*r[0];
        ld a = ld(A)*A*cy2 + ld(B)*B*cx2;
        ld b = ld(A)*A*cy +2*ld(B)*C*cx2 - ld(A)*B*cx;
        c = c*A*A + ld(C)*C*cx2 - ld(A)*C*cx;
        if(abs(a) < 0.5) {
            ay.pb(-c/b);
        }
        else {
            ld D = b*b-4*a*c;
            if(D < -0.5) exit(0);
            else {
                D= max(D,ld(0));
                ay.pb((-b-sqrt(D))/(2*a));
                ay.pb((-b+sqrt(D))/(2*a));
            }
        }
    }
    for(auto ansy : ay) ax.pb((-ansy*B-C)/A);
    if(sw) {
        swap(ax,ay);
        swap(x,y);
    }
    if(ax.size() > 1 && sq(ax[1]-x[0])+sq(ay[1]-y[0]) < sq(ax[0]-x[0])+sq(ay[0]-y[0])) {
        swap(ax[1],ax[0]);
        swap(ay[1],ay[0]);
    }
    printf("%.5lf %.5lf\n", (double)ax[0], (double)ay[0]);
    
}