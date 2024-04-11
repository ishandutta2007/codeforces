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
#define readv(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair

bool more(pll a, pll b) {
    return a.first*b.second > a.second*b.first;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
//    forn(i,0,n) a[i] = n-i;
    srt(a);
    vll pref;
    ll sum = 0;
    pref.pb(sum);
    for(auto x : a) {
        sum += x;
        pref.pb(sum);
    }
    pll best(0,1);
    int pos = 0;
    int sg = 0;
    int num = 0;
    auto get = [&] ( int l, int r) {
        return pref[r+1]-pref[l];
    };
    forn(md,0,n) {
        int r = min(md, n-1-md);
        int l = -1;
        while(r-l > 1) {
            int m = (r+l)/2;
            ll summ = get(md -m ,md-1) + get(n-m, n-1);
            ll summ1 = get(md -m-1 ,md-1) + get(n-m-1, n-1);
            pll pm = mp(summ - 2*m*a[md], 2*m+1);
            pll pm1 = mp(summ1 - 2*(m+1)*a[md], 2*m+3);
            if(pm1.first < 0 || more(pm, pm1)) r = m;
            else l = m;
            if(pm.first>=0 && more(pm, best)) {
                best = pm;
                pos = md;
                num = m;
                sg = 1;
            }
            if(pm1.first>=0 && more(pm1, best)) {
                best = pm1;
                pos = md;
                num = m+1;
                sg = 1;
            }
        }
//        r = min(md, n-1-md);
//        l = -1;
//        while(r-l > 1) {
//            int m = (r+l)/2;
//            ll summ = get(0, m-1) + get(md+1,md+m);
//            ll summ1 = get(0, m) + get(md+1, md+m+1);
//            pll pm = mp(-summ + 2*m*a[md], 2*m+1);
//            pll pm1 = mp(-summ1 + 2*(m+1)*a[md], 2*m+3);
//            if(pm1.first < 0 || more(pm, pm1)) r = m;
//            else l = m;
//            if(pm.first>=0 && more(pm, best)) {
//                best = pm;
//                pos = md;
//                num = m;
//                sg = -1;
//            }
//            if(pm1.first>=0 && more(pm1, best)) {
//                best = pm1;
//                pos = md;
//                num = m+1;
//                sg = -1;
//            }
//        }
    }
    vi poss;
    if(sg == -1) {
        forn(i,0,num) poss.pb(i+1);
        forn(i,pos,pos+num+1) poss.pb(i+1);
    }
    else {
        
        forn(i,pos-num,pos+1) poss.pb(i+1);
        forn(i,0,num) poss.pb(n-num+i+1);
    }
//    cout<<best.first<<' '<<best.second;
    printf("%d\n", poss.size());
    for(auto x : poss) printf("%lld ", a[x-1] );
    
    
}