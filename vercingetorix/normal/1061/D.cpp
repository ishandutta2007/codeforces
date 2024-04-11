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
#include <stack>
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
    int n; ll x,y;
    scanf("%d %lld %lld", &n, &x,&y);
    vpi ev;
    ll ans = 0;
    forn(i,0,n) {
        int l,r;
        scanf("%d %d", &l, &r);
        ev.pb(mp(l, -1));
        ev.pb(mp(r, 1));
        ans = (ans+ll(r-l) * y)%mod;
    }
    sort(all(ev));
    vll fr;
    for(auto e : ev) {
        ll t = e.first;
        if(e.second == -1) {
            if(fr.empty() || (t-fr.back())*y >= x) {
                fr.clear();
                ans = (ans + x) % mod;
            }
            else {
                ans = (ans + (t-fr.back())*y) % mod;
                fr.pop_back();
            }
        }
        else {
            fr.pb(t);
        }
    }
    cout<<ans;
}