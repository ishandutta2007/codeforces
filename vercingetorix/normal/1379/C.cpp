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
    int t;
    read(t);
    forn(af,0,t) {
        int n,m;
        scanf("%d %d", &n, &m);
        vi a(m),b(m);
        forn(i,0,m) {
            scanf("%d %d", &a[i], &b[i]);
        }
        vpll abest;
        forn(i,0,m) abest.pb(mp(ll(a[i]), ll(b[i])));
        sort(all(abest));
        ll best = 0;
        vll tail(1,0);
        forn(i,0,m) tail.pb(tail.back() + abest[m-1-i].first);
        forn(t2,0,m) {
            ll val = abest[t2].second;
            ll cur = abest[t2].first + ll(n-1) * abest[t2].second;
            auto it = lower_bound(abest.begin(), abest.end(), mp(ll(val),ll(0)));
            int nummore = abest.end() - it;
            int ntake = min(nummore, n-1);
            cur += tail[ntake] - ll(ntake)*val;
            if(ntake + t2 >= m) cur += val - abest[t2].first;
            best = max(best, cur);
        }
        cout<<best<<endl;
        
    }
}