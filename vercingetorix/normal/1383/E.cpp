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
    char c[1000100];
    scanf("%s", c);
    string s(c);
    int n = s.size();
    ll ans = 1;
    if (s==string(n, '0')) {
        cout<<n;
        return 0;
    }
    int l = 0;
    int r = n-1;
    while(s[l]=='0') l++;
    while(s[r] =='0') r--;
    ans = ll(l+1)*ll(n-r)%mod;
    s = s.substr(l, r-l+1);
    n = s.size();
    int pt = 0;
    vi a;
    while(pt<n-1) {
        pt++;
        int cur = 0;
        while(s[pt] != '1') {
            pt++;
            cur++;
        }
        a.pb(cur);
    }
    int k = a.size();
    vpi q;
    ll res = 0;
    ll tot = 1;
    q.pb(mp(1000100, 0));
    for(auto x : a) {
        ll wall = 0;
        int pt = 0;
        while(pt <= x) {
            while(q.back().first >= pt && pt<=x) {
                wall = ((wall + tot)%mod + mod - q.back().second) % mod;
                pt++;
            }
            if(pt > q.back().first) q.pop_back();
        }
        q.pb(mp(x, tot));
        tot =  (tot+wall)%mod;
    }
    cout<<tot*ans%mod;
    return 0;
    
}