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

const int MAXN = 100000;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    ll nn = n;
    ll ans = (nn*(nn+1))/2;
    readv(a, n);
    vector<vector<int>> hbit(30);
    forn(j,0,30) hbit[j].pb(-1);
    forn(i,0,n) {
        forn(j,0,30) if(a[i] & (1<<j)) hbit[j].pb(i);
    }
    forn(j,0,30) hbit[j].pb(n);
    map<int, int> last;
    for(auto x : a) last[x] = -1;
    forn(i,0,n) {
        int l = last[a[i]];
        int r = n+1;
        forn(j,0,30) if((a[i] & (1<<j)) == 0){
            auto it = lower_bound(all(hbit[j]), i);
            r = min(r, *it);
            --it;
            l = max(l, *it);
        }
//        printf("For %d it's between %d and %d\n", i,l,r);
        last[a[i]] = i;
        ll nl = i-l;
        ll nr = r-i;
        ans-=nl*nr;
    }
    cout<<ans;
}