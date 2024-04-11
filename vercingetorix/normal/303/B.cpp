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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

vector<vll> ans;
ll sq(ll x) {
    return x*x;
}
long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m,x,y,a,b;
    cin>>n>>m>>x>>y>>a>>b;
    ll d = gcd(a,b);
    a/=d; b/=d;
    ll k1 = min(n/a, m/b);
    ll lx = k1*a;
    ll ly = k1*b;
    ll x1 = x - (lx+1)/2;
    ll x2 = x1 + lx;
    ll y1 = y - (ly+1)/2;
    ll y2 = y1 + ly;
    if(x1<0) {
        x2 -= x1;
        x1 = 0;
    }
    else if(x2 > n) {
        x1-=(x2-n);
        x2 = n;
    }
    if(y1<0) {
        y2 -= y1;
        y1 = 0;
    }
    else if(y2 > m) {
        y1-=(y2-m);
        y2 = m;
    }
    ans.pb(vll());
    ans.back().pb(sq(2*x-x1-x2)+sq(2*y-y1-y2));
    ans.back().pb(x1); ans.back().pb(y1);
    ans.back().pb(x2); ans.back().pb(y2);
    
//    int k2 = min(n/b, m/a);
//    lx = k2*b;
//    ly = k2*a;
//    x1 = x - (lx+1)/2;
//    x2 = x1 + lx;
//    y1 = y - (ly+1)/2;
//    y2 = y1 + ly;
//    if(x1<0) {
//        x2 -= x1;
//        x1 = 0;
//    }
//    else if(x2 > n) {
//        x1-=(x2-n);
//        x2 = n;
//    }
//    if(y1<0) {
//        y2 -= y1;
//        y1 = 0;
//    }
//    else if(y2 > m) {
//        y1-=(y2-n);
//        y2 = m;
//    }
//    ans.pb(vll());
//    ans.back().pb(sq(2*x-x1-x2)+sq(2*y-y1-y2));
//    ans.back().pb(x1); ans.back().pb(y1);
//    ans.back().pb(x2); ans.back().pb(y2);
    sort(all(ans));
    printf("%lld %lld %lld %lld", ans[0][1], ans[0][2],ans[0][3],ans[0][4]);
    
    
    
}