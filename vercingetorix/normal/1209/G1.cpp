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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    readv(a,n);
    set<int> val;
    map<int, int> f,l;
    map<int, int> cnt;
    forn(i,0,n) {
        if(val.find(a[i]) == val.end()) {
            f[a[i]] = i;
            val.insert(a[i]);
        }
        l[a[i]] = i;
        cnt[a[i]]++;
    }
    vpi ev;
    for(auto x : val) {
        ev.pb(mp(f[x], 1));
        ev.pb(mp(l[x], -1));
    }
    srt(ev);
    int cur = 0;
    int pt = 0;
    int ans = n;
    vi in;
    forn(i,0,n) {
        while(pt<ev.size() && ev[pt].first == i) {
            if(ev[pt].second == 1) in.pb(a[i]);
            cur+=ev[pt++].second;
        }
        if(cur == 0) {
//            ans --;
            int dec = 0;
            for(auto x : in) dec = max(dec, cnt[x]);
            ans -= dec;
            in.clear();
        }
    }
    cout<<ans;
    
}