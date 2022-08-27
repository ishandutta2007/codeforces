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
    char c[500];
    forn(aff,0,t) {
        int n;
        scanf("%d\n", &n);
        vs a(n);
        forn(i,0,n) {
            scanf("%s\n", c);
            a[i] = string(c);
        }
        vpi ans;
        if(a[0][1] == a[1][0]) {
            if(a[n-1][n-2] == a[0][1]) ans.pb(mp(n, n-1));
            if(a[n-2][n-1] == a[0][1]) ans.pb(mp(n-1, n));
        }
        else if(a[n-1][n-2] == a[n-2][n-1]) {
            if(a[n-1][n-2] == a[0][1]) ans.pb(mp(1, 2));
            if(a[n-2][n-1] == a[1][0]) ans.pb(mp(2, 1));
        }
        else {
            if(a[0][1] == '0') ans.pb(mp(2,1));
            else ans.pb(mp(1,2));
            if(a[n-2][n-1] == '0') ans.pb(mp(n-1,n));
            else ans.pb(mp(n,n-1));
        }
        cout<<ans.size()<<endl;
        for(auto x : ans) cout<<x.first<<' '<<x.second<<endl;
    }
}