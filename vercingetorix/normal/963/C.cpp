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
void no() {
    cout<<0;
    exit(0);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    map<ll, ll> cw,ch;
    map<pll, ll> c;
    ll wd, hd;
    forn(i,0,n) {
        ll w,h,cnt;
        scanf("%lld %lld %lld", &w, &h, &cnt);
        c[mp(w,h)] += cnt;
        cw[w] += cnt;
        ch[h] += cnt;
        wd = w;
        hd = h;
    }
    
    
//    for(auto x : cw) dw = gcd(dw, x.second);
//    for(auto x : ch) dh = gcd(dh, x.second);
    map<ll, ll> wk, hk;
    for(auto x : cw) {
        wk[x.first] = c[mp(x.first, hd)];
    }
    for(auto x : ch) {
        hk[x.first] = c[mp(wd, x.first)];
    }
//    for(auto x : c) {
//        if(x.first.first == wd) hk[x.first.second] = x.second;
//        if(x.first.second == hd) wk[x.first.first] = x.second;
//    }
    ll dw = 0;
    ll dh = 0;
    for(auto x : wk) dw = gcd(dw, x.second);
    for(auto x : hk) dh = gcd(dh, x.second);
    for(auto & x : wk) x.second /= dw;
    for(auto & x : hk) x.second /= dh;
    vll a;
    for(auto w : wk) for(auto h : hk) {
        ll cnt = c[mp(w.first, h.first)];
        if(cnt == 0) no();
        if(w.second == 0 || cnt%w.second != 0) no();
        cnt/=w.second;
        if(h.second == 0 || cnt%h.second!=0) no();
        cnt/=h.second;
        a.pb(cnt);
    }
    srt(a);
    forn(i,1,a.size()) if(a[i] != a[i-1]) no();
    int ans = 0;
    for(ll k = 1; k*k <= a[0]; k++) {
        if(a[0]%k == 0) {
            ans++;
            if(k*k<a[0]) ans++;
        }
    }
    cout<<ans;
    
    
    
    
}