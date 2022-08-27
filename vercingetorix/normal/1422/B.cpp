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
    scanf("%d",&t);
    forn(af,0,t) {
        ll ans = 0;
        int n,m;
        scanf("%d %d",&n,&m);
        vvi a(n, vi(m));
        forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
        forn(i,0,(n+1)/2) forn(j,0,(m+1)/2) {
            vi su;
            su.pb(a[i][j]);
            if(i*2+1 != n) {
                su.pb(a[n-1-i][j]);
                if(j*2+1 != m) su.pb(a[n-1-i][m-1-j]);
            }
            if(j*2+1 != m) su.pb(a[i][m-1-j]);
            sort(all(su));
            if(su.size() > 1) {
                for(auto x : su) ans += abs((ll) (x-su[1]));
            }
        }
        cout<<ans<<endl;
        
    }
}