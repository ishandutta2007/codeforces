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
ll seed = 0;
ll base = 0;
vi t;
vi a;

int rnd() {
    int ret = seed;
    seed = (seed*base + 233) %mod;
    return ret;
}
vll ans;
int n;

void go() {
    ll res = 1;
    forn(i,0,n) {
        ll r = i+1;
        res = res * ((1 + (ans[i]^(r*r))) % mod) % mod;
    }
    cout<<res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    int lp = 0;
    forn(i,0,m) {
        int p,k,b,w;
        scanf("%d %d %d %d", &p, &k, &b, &w);
        seed = b;
        base = w;
        forn(i,lp,p) {
            t.pb(rnd()%2);
            a.pb(rnd()%k + 1);
        }
        lp = p;
    }
    ans = vll(n,0);
    vll cnt(2,0);
    forn(i,0,n) cnt[t[i]] += a[i];
    int tz = t[0];
    if(cnt[t[0]] > cnt[1-t[0]]) tz = 1 - t[0];
    if(tz != t[0]) {
        a[0] --;
        ans[0]++;
    }
    
    ll mz = 0;
    forn(i,0,3*n) {
        if(t[i%n] == tz) {
            mz += a[i%n];
            ans[i%n] += a[i%n];
            a[i%n] = 0;
        }
        else {
            ll mn = min(mz, (ll)a[i%n]);
            a[i%n] -= mn;
            ans[i%n] += mn;
            mz -= mn;
        }
    }
    go();
    
}