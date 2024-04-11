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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair
//const int A = 10001;
//ll d[A][A];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,b,x;
    ll w;
    scanf("%d %lld %d %d", &n, &w, &b, &x);
    vll bird(1,x);
    int num = 0;
    vi cnum;
    forn(i,0,n) {
        int c;
        scanf("%d", &c);
        cnum.pb(c);
        num += c;
        forn(j,0,c) bird.pb(0);
        bird.back()+=ll(x);
    }
    readv(cost, n);
    vll pay;
    forn(i,0,n) {
        forn(j,0,cnum[i]) pay.pb(cost[i]);
    }
    vll d(num+1,w);
//    forn(i,0,num+1) d[i][0] = w;
    int ans = 0;
    forn(l,1,num+1) {
        ll mm = w + ll(b)*(l-1);
        ll best = -1;
        vll nd(num+1,-1);
        forn(i,l-1,num+1) {
            nd[i] = best;
            if(best != -1) best = min(mm+ll(b), best+bird[i]);
            if(d[i] != -1) {
                ll cand = min(d[i]+bird[i], mm);
                if(cand >= pay[i]) {
                    best = max(best, cand-pay[i]);
                }
            }
        }
        if(nd[num] != -1) ans = l;
        d = std::move(nd);
        nd.clear();
    }
    cout<<ans;
    
}