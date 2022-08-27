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
vi nx[2];

int solve(int l, int r, vi & x) {
    if(l == r) return x[0]^l;
    forn(i,0,2) nx[i].clear();
    forn(i,0,r-l+1) nx[x[i]%2].pb(x[i]);
    if((r-l)%2) {
        vi y1,y2;
        for(auto v : nx[l%2]) y1.pb(v/2);
        for(auto v : nx[(l%2)^1]) y2.pb(v/2);
        return 2*(solve(l/2, (r-1)/2, y1)|solve((l+1)/2, r/2, y2));
    }
    else {
        int rem = 0;
        if(nx[1].size() > nx[0].size()) rem = 1;
        vi y1;
        for(auto v : nx[rem]) y1.pb(v/2);
        vi y2;
        for(auto v : nx[rem^1]) y2.pb(v/2);
        return 2* (solve(l/2, r/2, y1)|solve((l+1)/2, (r-1)/2, y2)) + rem^(l%2);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int l,r;
        scanf("%d %d", &l, &r);
        readv(a, r-l+1);
        printf("%d\n", solve(l,r,a));
    }
    
    
}