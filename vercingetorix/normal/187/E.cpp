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
#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp> //  .
#include <ext/pb_ds/tree_policy.hpp> //   tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#endif

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

#ifdef LOCAL
 class ordered_set : public set<pi> {
 public:
     auto find_by_order(int k) {
         auto it = this->begin();
         forn(i,0,k) it++;
         return it;
     }

     int order_of_key(pi key) {
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
typedef tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#endif






int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,l,s;
    scanf("%d %d %d", &n, &l, &s);
    s--;
    readv(x,n);
    int r = n-1-l;
    if(l == 0) {
        if(s!=0) printf("-1\n");
        else {
            printf("%d\n", x.back()-x[0]);
            forn(i,1,n) printf("%d ", i+1);
            printf("\n");
        }
        exit(0);
    }
    if(r == 0) {
        if(s!=n-1) printf("-1\n");
        else {
            printf("%d\n", x.back()-x[0]);
            for(int i = n-2; i>=0; i--) printf("%d ", i+1);
            printf("\n");
        }
        exit(0);
    }
    int sw = 0;
    if(s > l) {
        sw = 1;
        reverse(all(x));
        forn(i,0,n) x[i] = -x[i];
        swap(l,r);
        s = n-1-s;
    }
    int best = 2*x.back() - x[s] - x[0];
    vi ans;
    vi done(n,0);
    done[s] = 1;
    forn(i,n-r,n) {
        ans.pb(i);
        done[i] = 1;
    }
    for(int i = n-r; i>=0; i--) if(done[i] == 0) ans.pb(i);
    int need = l-s;
    ordered_set q;
    for(int i = s+1; i+1<n;i++) {
        q.insert(mp(2*(x[i+1]-x[i]), i));
    }
    int bptr = n-1;
    ll pref = 0;
    auto it = q.begin();
    forn(i,0,need) {
        pref += it->first;
        it++;
    }
    ll cand = pref;
    ll bcand = cand;
    int tk = need;
    for(int ptr = n-2; ptr >= n-1-need; ptr-- ) {
        pi cur = mp(2*(x[ptr+1]-x[ptr]), ptr);
        if(q.order_of_key(cur) < tk) cand -= cur.first;
        else cand -= q.find_by_order(tk-1)->first;
        tk--;
        q.erase(cur);
        cand += x[ptr+1]-x[ptr];
        if(cand < bcand) {
            bcand = cand;
            bptr = ptr;
        }
    }
    cand = bcand;
    
    cand += x[s] - x[0];
    cand += x[n-1]-x[0];
    q.clear();
    for(int i = s+1; i+1<n;i++) {
        q.insert(mp(2*(x[i+1]-x[i]), i));
    }
    for(int ptr = n-2; ptr >= bptr; ptr-- ) {
        pi cur = mp(2*(x[ptr+1]-x[ptr]), ptr);
        q.erase(cur);
    }
    it = q.begin();
    vi rev;
    forn(i,0,need + bptr - n + 1) {
        rev.pb(it->second);
        it++;
    }
    srt(rev);
    if(cand < best) {
        best = cand;
        int pt = 0;
        ans.clear();
        for(int i = s-1; i>=0; i--) ans.pb(i);
        int i = s+1;
        while(i < bptr) {
            if(pt < rev.size() && rev[pt] == i) {
                int ri = i;
                while(pt<rev.size() && rev[pt] == ri) {
                    ri++;
                    pt++;
                }
                ans.pb(ri);
                for(int j = ri-1; j>=i; j--) ans.pb(j);
                i = ri+1;
            }
            else ans.pb(i++);
        }
        for(int i = n-1; i>= bptr; i--) ans.pb(i);
    }
    
    
    
    if(sw) {
        forn(i,0,n-1) ans[i] = n-1-ans[i];
    }
    printf("%d\n", best);
    for(auto x : ans) printf("%d ", x+1);
    
    
    
    
}