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
int n;
ll len;
vi a, b;
vll a4, b2, b3;

bool test(int m) {
    int pt = 0;
    forn(i,0,n) {
        while(pt<b3.size() && b3[pt] < a[i] - m) pt++;
        if(pt == b3.size() || b3[pt] > a[i] + m) return false;
    }
    int ptr = 0;
    int ptl = 0;
    int mn = 10*n;
    forn(i,0,2*n) {
        while(a4[ptl] < b2[i] - m) ptl++;
        while(ptr<a4.size() && a4[ptr] <= b2[i] + m) ptr++;
        mn = min(mn, i-ptl);
        if(i-ptr >= mn) {
            return false;
        }
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %lld", &n, &len);
    a.resize(n);
    b.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) scanf("%d", &b[i]);
    srt(a); srt(b);
    forn(it,-1,3) forn(i,0,n) a4.pb(it*len+a[i]);
    forn(it,0,2) forn(i,0,n) b2.pb(it*len+b[i]);
    forn(it,-1,2) forn(i,0,n) b3.pb(it*len+b[i]);
    int l = -1;
    int r = len;
    while(r-l > 1) {
        int m = (r+l)/2;
        if(test(m)) r = m;
        else l = m;
    }
    cout << r;
}