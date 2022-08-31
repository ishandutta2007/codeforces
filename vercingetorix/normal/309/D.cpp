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
const int A =33000;
ll ans[A];
ll tot = 0;
ll k;
int n,m;

void go(ll l1) {
    ll l2 = k - l1;
    if(l1>l2) {
        ans[l1] = ans[l2];
        return;
    }
    ll ret = 0;
//    ll def = m;
    ll def = k-m;
    ll A = 2*k-l2-def;
    ll B = k*k+l1*l1 +l2*l2+l1*def-2*k*def;
    ll badd = l1 - 2*k;
    ll full = n - 2*m;
    int mn = m+1;
    int mx = k-1-m;
    int mb1 = mn;
    for(int a1 = mx; a1 >= mn; a1--) {
//
//    }
//    forn(a1,m+1,k-m) {
//        A --;
//        B += badd;
        A++;
        B-=badd;
        while(mb1 <= mx && mb1 * A <= B) mb1++;
        ret += mx - mb1+1;
//        if(B<=0) ret += full;
//        else {
//            ll mb1 = B/A+1;
//            if(mb1 < mn) mb1 = mn;
//            if(mb1<= mx) ret += mx - mb1+1;
//        }
    }
//    forn(a1,m+1,k-m)
//    forn(b1,m+1,k-m) {
//        if((2*k-l2-a1)*b1 > )
//        if(2*k*(a1+b1) - l1*a1 - l2*b1 - a1*b1>k*k+l1*l1+l2*l2) ret++;
//        if(2*k*(a1+b1) - l1*a1 - l2*b1 - a1*b1>k*k+l1*l1+l2*l2) ret++;
//    }
    ans[l1] = ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    cin>>n>>m;
    k = n+1;
    forn(l1,m+1,n+1-m) {
        go(l1);
        tot += ans[l1];
    }
    cout<<3*tot;
    
    
}