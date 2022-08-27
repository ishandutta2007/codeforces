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
ll INF = (1e16)*3;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    ll x0, y0, ax,ay,bx,by;
    cin>>x0>>y0>>ax>>ay>>bx>>by;
    ll xs, ys, t;
    cin>>xs>>ys>>t;
    vll x;
    vll y;
    x.pb(x0);
    y.pb(y0);
    while(1) {
        if(x.back()*ax + bx > INF || y.back()*ay+by > INF) break;
        x.pb(x.back()*ax + bx);
        y.pb(y.back()*ay + by);
    }
    int k = x.size();
    int ans = 0;
    forn(l,0,k) forn(r,l,k) {
        ll d1 = abs(x[r]-x[l]) + abs(y[r]-y[l]);
        ll d = min(abs(xs-x[l]) + abs(ys-y[l]), abs(x[r]-xs) + abs(y[r]-ys));
        if(d+d1<=t) ans = max(ans, r-l+1);
    }
    cout<<ans;
    
    
}