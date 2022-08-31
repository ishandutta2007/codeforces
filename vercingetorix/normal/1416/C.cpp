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
vi d2(1,1);
vll c0(31,0), c1(31, 0);

void go(int l, vi & a) {
    if(a.size() == 0) return;
    int cur0 = 0, cur1 = 0;
    vi a0, a1;
    for(auto x : a) {
        if(x & d2[l]) {
            c1[l] += cur0;
            a1.pb(x);
            cur1++;
        }
        else {
            c0[l] += cur1;
            a0.pb(x);
            cur0++;
        }
    }
    if(l>0) {
        go(l-1,a0);
        go(l-1,a1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    readv(a,n);
    forn(i,0,30) d2.pb(d2.back()*2);
    go(30, a);
    int ans = 0;
    ll res = 0;
    forn(i,0,31) {
        if(c1[i] < c0[i]) ans += d2[i];
        res += min(c1[i], c0[i]);
    }
    cout<<res<<' '<<ans;
}