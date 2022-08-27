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

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#endif
#ifdef LOCAL
class ordered_set : public set<pll> {
public:
    auto find_by_order(int k) {
        auto it = this->begin();
        forn(i,0,k) it++;
        return it;
    }
    
    int order_of_key(pll key) {
        auto it = this->begin();
        int ret = 0;
        while(*it!=key) {
            it++;
            ret++;
        }
        return ret;
    }
};
#else
using namespace __gnu_pbds;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#endif

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    ll k;
    scanf("%d %lld", &n, &k);
    const ll INF = 1e18;
    ll l = -INF;
    ll r = INF;
    readv(a,n);
//    l = 3;
//    r = 5;
    while(r -l > 1) {
        ll m = (r+l)/2;
        ordered_set q;
        ll sum = 0;
        q.insert(mp(0, -1));
        ll cand = 0;
        forn(i,0,n) {
            sum += a[i];
            pll mn = mp(sum + 1 - m, -1);
            auto it = q.lower_bound(mn);
            if(it == q.end()) {
                cand += i+1;
            }
            else {
                int sm = q.order_of_key(*it);
                cand += sm;
            }
            q.insert(mp(sum, i));
        }
        if(cand >= k) l = m;
        else r = m;
    }
    cout<<l;
    
}