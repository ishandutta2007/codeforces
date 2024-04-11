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

bool pless(const pll & a, const pll & b) {
    return a.first*b.second < b.first*a.second;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vi x[200500];
    forn(i,0,n) {
        int m,k;
        scanf("%d %d", &m, &k);
        x[m].pb(k);
    }
    pll best = mp(0,1);
    vi ans;
    forn(t,1,21) {
        vpi cur;
        forn(i,1,200500) {
            ll mes = 0;
            if(x[i].empty()) continue;
            for(auto k : x[i]) {
                mes += min(k,t);
            }
            cur.pb(mp(mes,i));
        }
        srtrev(cur);
        ll p = 0;
        forn(i,0,min((int)cur.size(), t)) p += cur[i].first;
        if(pless(best, mp(p,t))) {
            best  = mp(p,t);
            ans.clear();
            forn(i,0,min((int)cur.size(), t)) ans.pb(cur[i].second);
        }
    }
    vpi a;
    forn(i,1,200500) {
        ll mes = 0;
        if(x[i].empty()) continue;
        for(auto k : x[i]) mes += k;
        a.pb(mp(mes,i));
    }
    srtrev(a);
    int bi = -1;
    if(a.size() >= 20) {
        vi ind;
        ll sum = 0;
        int pt = 20;
        forn(i,0,20) {
            sum += a[i].first;
            ind.pb(a[i].second);
        }
        while(pt<a.size()) {
            sum += a[pt++].first;
            if(pless(best, mp(sum,pt))) {
                best  = mp(sum,pt);
                bi = pt;
            }
        }
        if(bi != -1) {
            ans.clear();
            forn(i,0,bi) ans.pb(ind[i]);
        }
    }
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d ", x);
    
    
    
}