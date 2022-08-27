#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
//#include <queue>
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
const ll INF = 1e18;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
#endif
    int n,k,x;
    scanf("%d %d %d", &n, &k, &x);
    readv(a,n);

    a.pb(0);
    vll d(n+2, -INF);
    d[0] = 0;
    forn(itq,1,x+2) {
        vll nd(1, 0);
        deque<pll> q;
        q.pb(mp(0,0));
        forn(l,1,n+2) {
            while(q.back().second + k < l) q.pop_back();
            nd.pb(q.back().first + a[l-1]);
            while(!q.empty() && q[0].first <= d[l]) q.pop_front();
            q.push_front(mp(d[l], l));
        }
        d = nd;
    }
    ll ans = d[n+1];
    if (ans<0) ans = -1;
    cout<<ans;

}