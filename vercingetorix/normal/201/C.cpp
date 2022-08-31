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
    int n;
    read(n);
    readv(a,n-1);
    vll l1(n,0), l2(n,0), r1(n,0), r2(n,0);
    forn(x,1,n) {
        if(a[x-1] == 1) l2[x] = 0;
        else l2[x] = l2[x-1] + a[x-1]/2*2;
        l1[x] = l2[x];
        ll cand = l1[x-1] + a[x-1];
        if(a[x-1] % 2 == 0) cand--;
        l1[x] = max(l1[x], cand);
    }
    for(int x = n-2; x>=0; x--) {
        if(a[x] == 1) r2[x] = 0;
        else r2[x] = r2[x+1] + a[x]/2*2;
        r1[x] = r2[x];
        ll cand = r1[x+1] + a[x];
        if(a[x] % 2 == 0) cand--;
        r1[x] = max(r1[x], cand);
    }
    ll ans = 0;
    forn(x,0,n) {
        ans = max(ans, l2[x] + r1[x]);
        ans = max(ans, l1[x] + r2[x]);
    }
    cout<<ans;
    
    
}