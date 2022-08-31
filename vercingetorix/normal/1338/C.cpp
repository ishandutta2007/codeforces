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
typedef vector<vvll> vvvll;
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
vll d2(1,1);
vll d4(1,1);
vi res = {1,2,3,4,8,12,5,10,15,6,11,13,7,9,14};
ll get2(ll n) {
    if(n<3) return 0;
    int l = 0;
    while(n >= d2[2*l]*3) l++;
    ll s = d2[2*l-2]*3;
    ll base = get2(n%s);
    int shift = (n/s + n)%3;
    if(shift == 1) base += d2[2*l-2];
    if(shift == 2) base += d2[2*l-1];
    if(shift == 0) base += d2[2*l-2] + d2[2*l-1];
    return base;
}

ll get(ll n) {
    if(n==0) return 0;
    int k = 0;
    while(d2[2*k] - 1 < n) {
        k++;
    }
    ll add = n - (d2[2*k-2]);
    ll ret = d2[2*k-2] + get2(add);
    if(add%3==1) ret += d2[2*k-2];
    else if(add%3==2) ret += d2[2*k-1];
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
//    t = 100;
    forn(i,0,62) d2.pb(d2.back()*2);
    forn(i,0,15) d4.pb(d4.back()*2);
//    int pt = 0;
    while(t--) {
        ll n;
        scanf("%lld", &n);
//        n = ++pt;
        int k = 0;
        printf("%lld\n", get(n));
        
    }
    
}