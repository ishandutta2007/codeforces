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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,S;
    scanf("%d %d", &n, &S);
    vi a(n), b(n), s(n);
    forn(i,0,n) scanf("%d %d %d", &s[i], &a[i], &b[i]);
    ll ans = 0;
    vpll ap, bp;
    forn(i,0,n) {
        ans += ll(s[i])*ll(max(a[i],b[i]));
        if(a[i] >= b[i]) ap.pb(mp(a[i]-b[i], s[i]));
        else if(a[i] < b[i]) bp.pb(mp(b[i]-a[i], s[i]));
    }
    ll asum=0, bsum=-0;
    for(auto x : ap) asum+=x.second;
    for(auto x : bp) bsum+=x.second;
    vll al, bl;
    sort(all(ap));
    sort(all(bp));
    int ta = asum%S;
    int tb = bsum%S;
    int pt = 0;
    while(ta > 0) {
        int take = min(ta, (int)ap[pt].second);
        forn(i,0,take) al.pb(ap[pt].first);
        ta-=take;
        pt++;
    }
    pt = 0;
    while(tb > 0) {
        int take = min(tb, (int)bp[pt].second);
        forn(i,0,take) bl.pb(bp[pt].first);
        tb-=take;
        pt++;
    }
    if(al.size() + bl.size() > S) {
        cout<<ans;
        return 0;
    }
    ll c1 = 0, c2 = 0;
    for(auto x : al) c1+=x;
    for(auto x : bl) c2+=x;
    ans -= min(c1,c2);
    cout<<ans;
    
    
    
}