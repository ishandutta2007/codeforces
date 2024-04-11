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
ll INF = 1e18;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    ll r1,r2,r3,d;
    scanf("%d %lld %lld %lld %lld", &n, &r1, &r2, &r3, &d);
    readv(a,n);
    vll din(n, INF);
    vll dip(n, INF);
    vll db(n, INF);

    vll t1(n);
    vll t2(n);
    r3 = min(r3, 2*r1+2*d);
    forn(i,0,n) {
        t1[i] = min(r1*a[i] + r3, r2+2*d+r1);
        t2[i] = min(r1*(a[i]+2), r2+r1);
    }
    din[n-1] = t1[n-1];
    db[n-1] = din[n-1] + d;
    dip[n-1] = min(db[n-1], t2[n-1] + 2*d);
    for(int i = n-2; i >= 0; i--) {
        din[i] = t1[i] + d + din[i+1];
        din[i] = min(din[i], t2[i] + d + dip[i+1]);
        din[i] = min(din[i], t2[i] + d + db[i+1]);
        db[i] = t2[i] + 2*d + db[i+1];
        dip[i] = t2[i] + 3*d + din[i+1];
    }
    cout<<din[0];
//    vll pref1(n);
//    ll sum = 0;
//    forn(i,0,n) {
//        sum+=t1[i];
//        pref1[i] = sum;
//        if(i>=1) {
//            ll cand = t2[i] + t2[i-1] + 2*d;
//            if(i>1) cand += pref1[i-1];
//            pref1[i] = min(pref1[i], cand);
//        }
//    }
//    vll post2(n);
//    sum = 0;
//    for(int i = n-2; i>=0; i--) {
//        sum += t2[i];
//        post2[i] = sum;
//    }
//    ll ans = pref1[n-1] + d*(n-1);
//    forn(i,0,n-1) {
//        ll cand = d*(n-1 + n-1-i) + t1[n-1] + post2[i];
//        if(i>0) cand += pref1[i-1];
//        ans = min(ans,cand);
//    }
//    ll cand = t2[n-1] + t2[n-2] + d*(n+1);
//    if(n>2) cand += pref1[n-3];
//    ans = min(ans,cand);
//    cout<<ans;
    
}