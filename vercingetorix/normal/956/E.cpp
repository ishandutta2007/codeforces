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
const int A = 10001;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,l,r;
    scanf("%d %d %d", &n, &l, &r);
    readv(a,n);
    readv(b,n);
    vi good, bad;
    forn(i,0,n) {
        if(b[i]) good.pb(a[i]);
        else bad.pb(a[i]);
    }
    bitset<A> canbad;
    canbad[0] = 1;
    for(auto x : bad) canbad |= canbad << x;
    vector<bitset<A>> canpref;
    srtrev(good);
    canpref.pb(bitset<A>());
    canpref[0][0] = 1;
    for(auto x : good) {
        canpref.pb(canpref.back() | (canpref.back() << x));
    }
    int psum = 0;
    forn(i,0,good.size()) {
        psum += good[i];
        canpref[i+1][psum] = 0;
    }
    vi sufsum;
    int sum = 0;
    sufsum.pb(0);
    for(int i = 0; i<good.size(); i++) {
        sum += good[good.size() -1-i];
        sufsum.pb(sum);
    }
    int last = A;
    vi nx(A);
    for(int i = A-1; i>=0; i--) {
        if(canbad[i]) last = i;
        nx[i] = last;
    }
    int ans = 0;
    for(int tk = good.size(); tk >0; tk--) {
        int best = A;
        forn(i,0,A) if(canpref[tk][i]) {
            best = min(best, i + nx[max(0,l-i)]);
        }
        int pt = 0;
        while(pt < good.size() - tk && sufsum[pt] + best <= r) pt++;
        if(pt == good.size()-tk && sufsum[pt] + best <= r) pt++;
        ans = max(ans, pt);
    }
    cout<<ans;
    
    
}