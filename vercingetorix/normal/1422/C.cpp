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
    string s;
    cin>>s;
    ll n = s.size();
//    cout<<n;
    vll d10(1,1);
    vll sd10(1,1);
    forn(i,0,n) {
        d10.pb(d10.back()*10%mod);
        sd10.pb((sd10.back() + d10.back()) % mod);
    }
    ll ans = 0;
    ll cur = 0;
    forn(i,0,n-1) {
        cur = (cur*10 + ll(s[i]-'0')) % mod;
        ans = (ans + cur*sd10[n-2-i])%mod;
    }
    cur = 0;
    for(int i = n-1; i >= 1; i--) {
        cur = (cur+d10[n-1-i]*ll(s[i]-'0')) % mod;
        ans = (ans + cur * i) % mod;
    }
    cout<<ans;
}