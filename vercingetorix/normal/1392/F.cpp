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
vpll q;

void add(ll x) {
    if(x == q.back().second + 1) {
        q.back().second++;
    }
    else if(x == q.back().second) {
        q.pb(mp(x,x));
    }
    else {
        ll let = (x - q.back().second - 1);
        ll l = q.back().first;
        ll r = q.back().second;
//        while(x > q.back().second + 1) {
//
//        }
        if(q.size() == 1) {
            ll fall = let/(r-l+2);
            q.back().first += fall;
            q.back().second += fall;
            l+=fall;
            r+=fall;
            let -= fall*(r-l+2);
            x -= fall*(r-l+1);
            if(let == 0) {
                q.back().second++;
            }
            else {
//                q.back().first ++;
//                l++;
                q.back().first = l+1;
                q.back().second = (l+let);
                q.pb(mp(l+let, r+1));
            }
        }
        else {
            if(let >= r-l+1) {
                q.pop_back();
                q.back().second = r+1;
                add(x-(r-l+1));
            }
            else {
                int k = q.size();
                q[k-2].second += let;
                q[k-1].first += let;
                q[k-1].second++;
            }
        }
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
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    
    q.pb(mp(a[0],a[0]));
    forn(i,1,n) {
        add(a[i]);
    }
    vll ans;
    for(auto x : q) {
        for(ll u = x.first; u <= x.second; u++) ans.pb(u);
    }
    for(auto x : ans) printf("%lld ", x);
    
}