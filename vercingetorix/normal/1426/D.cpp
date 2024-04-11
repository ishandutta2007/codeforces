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
    int n;
    
    read(n);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    vll s(1,0);
    map<ll, int> lastr;
    vi prev(n,-1);
    set<ll> has;
    has.insert(0);
    lastr[0] = 0;
    forn(i,0,n) {
        ll cur =s.back() + a[i];
        s.pb(cur);
        if(has.find(cur) != has.end()) {
            prev[i] = lastr[cur];
        }
        has.insert(cur);
        lastr[cur] = i+1;
    }
    int br = -1;
    int ans = 0;
    forn(i,0,n) {
        if(prev[i] > br) {
            ans ++;
            br = i-1;
        }
    }
    cout<<ans;
}