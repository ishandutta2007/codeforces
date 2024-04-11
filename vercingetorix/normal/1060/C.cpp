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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

vi psum(vi & x) {
    vi pref;
    int sum = 0;
    pref.pb(sum);
    forn(i,0,x.size()) {
        sum+=x[i];
        pref.pb(sum);
    }
    vi ret;
    int n = x.size();
//    forn(i,0,n) forn(j,i,n) ret.pb(pref[j+1] - pref[i]);
    ret.pb(0);
    forn(l,1,n+1) {
        int cur = pref[l]-pref[0];
        forn(s,0,n-l+1) {
            int e = s+l-1;
            cur = min(cur, pref[e+1]-pref[s]);
        }
        ret.pb(cur);
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(a,n);
    readv(b,m);
    int x;
    scanf("%d", &x);
    auto pa = psum(a);
    auto prb = psum(b);
    srt(pa);
    int ans = 0;
    forn(l,1,m+1) {
        int t = prb[l];
        auto it = upper_bound(all(pa), x/t);
        if(it == pa.begin()) continue;
        it--;
        ans = max(ans, int(it-pa.begin()) * l);
    }
//    for(auto t : prb) {
//        auto it = upper_bound(all(pa), x/t);
//        if(it == pa.begin()) continue;
//        it--;
//        ans = max(ans, (*it) * t);
//    }
    cout<<ans;
    
    
}