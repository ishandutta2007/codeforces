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
vi b;
int n;
pll ccur[1001001];
//pll ccur[100];
int ncur = 0;

ll scount(ll p) {
    int pt = 0;
    ll sum = 0;
    while(1) {
        sum += ccur[pt].first;
        if(sum <= p/2) pt++;
        else break;
    }
    ll res = 0;
    forn(i,0,ncur) {
        auto x = ccur[i];
        res += ll(x.first) * abs(x.second - ccur[pt].second);
    }
    return res;
}

ll to(ll p) {
    ll cand = 0;
    ll cursum = 0;
    forn(i,0,n) {
        if(b[i]%p + cursum >= p) {
            ll tk = p - cursum;;
            ccur[ncur++] = mp(tk, i);
            cand += scount(p);
            ncur = 0;
            if(b[i]%p > tk) ccur[ncur++] = (mp(b[i]%p-tk, i));
            cursum = b[i]%p-tk;
        }
        else if(b[i]%p!=0){
            ccur[ncur++] = (mp(b[i]%p, i));
            cursum += b[i]%p;
        }
    }
    return cand;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    readv(a,n);
    b = a;
    ll sum = 0;
    forn(i,0,n) sum+=a[i];
    if(sum == 1) {
        printf("-1");
        exit(0);
    }
    int pt = 2;
    while(sum%pt!=0) pt++;
    ll ans = to(sum);
    vll pr;
    for(ll pt = 2; pt*pt<=sum; pt++) {
        if(sum%pt == 0) {
            pr.pb(pt);
            while(sum%pt==0) sum/=pt;
        }
    }
    if(sum!=1) pr.pb(sum);
//    for(ll pt = 2; pt*pt<=sum; pt++) if(sum%pt == 0) {
    for(auto pt:pr) {
        ans = min(ans, to(pt));
//        ans = min(ans, to(sum/pt));
    }
    cout<<ans;
    
    
}