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
    readv(a,6);
    int n;
    read(n);
    readv(b,n);
    sort(all(a));
    vpi ev;
    forn(i,0,n) forn(j,0,6) {
        ev.pb(mp(b[i]-a[j], i));
    }
    vi cnt(n,0);
    int A = 6*n;
    sort(all(ev));
    int cgood = 0;
    int r = 0;
    int ans = 1e9;
    forn(l,0,A) {
        while(r<A && cgood < n) {
            cnt[ev[r].second] ++;
            if(cnt[ev[r].second]==1) cgood++;
            r++;
        }
        if(cgood == n) ans = min(ans, ev[r-1].first - ev[l].first);
        cnt[ev[l].second] --;
        if(cnt[ev[l].second]==0) cgood--;
    }
    cout<<ans;
}