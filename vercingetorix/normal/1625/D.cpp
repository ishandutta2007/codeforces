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
vi a;
vi cur;

pi test(int mask) {
    set<int> found;
    forn(i,0,cur.size()) {
        int cand = a[cur[i]] & mask;
        if(found.find(cand^mask) != found.end()) {
            int pt = 0;
            while((a[cur[pt]] & mask) != (cand^mask)) pt++;
            return mp(cur[i],cur[pt]);
        }
        else found.insert(cand);
    }
    return mp(-1,-1);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    if(k == 0) {
        printf("%d\n", n);
        forn(i,1,n+1) printf("%d ", i);
        exit(0);
    }
    int h = 30;
    while(((1<<h)&k) == 0) h--;
    h++;
    map<int, vi> g;
    forn(i,0,n) g[a[i]>>h].pb(i);
    vi ans;
    for(auto pr : g) {
        cur = pr.second;
        int mask = 0;
        int done = 0;
        for(int bit = h-1; bit>=0; bit--) {
            if(k&(1<<bit)) mask |= (1<<bit);
            else {
                mask ^= (1<<bit);
                auto u = test(mask);
                if(u.first != -1) {
                    ans.pb(u.first);
                    ans.pb(u.second);
                    done = 1;
                    break;
                }
                mask ^= (1<<bit);
            }
        }
        if (done == 0) {
            auto u = test(mask);
            if(u.first != -1) {
                ans.pb(u.first);
                ans.pb(u.second);
                done = 1;
            }
        }
        if(done == 0) ans.pb(cur[0]);
    }
    if(ans.size() <= 1) {
        printf("-1");
        
    }
    else {
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d ", x+1);
    }
    
    
}