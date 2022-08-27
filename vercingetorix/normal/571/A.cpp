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

const int A = 300500;
ll d[A];
ll s[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll a,b,c,l;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &l);
    ll tot = (l+2)*(l+1)/2;
    for(ll l = 0; l< A;l++) d[l] = (l+2)*(l+1)/2;
    s[0] = 1;
    forn(l,1,A) s[l] = s[l-1] + d[l];
    ll ans = s[l];
    forn(add,0,l+1) {
        if(a+add>=b+c) ans -= d[min(l-add, a+add-b-c)];
        if(b+add>=a+c) ans -= d[min(l-add, b+add-a-c)];
        if(c+add>=b+a) ans -= d[min(l-add, c+add-a-b)];
    }
    cout<<ans;
    
    
    
}