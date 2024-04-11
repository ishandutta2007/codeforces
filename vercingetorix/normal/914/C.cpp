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
    vi cnt(1023,0);
    cnt[1] = 0;
    forn(i,2,1001) {
        int k = i;
        int pr = 0;
        while(k > 0) {
            pr+=k%2;
            k/=2;
        }
        cnt[i] = cnt[pr] + 1;
    }
    string s;
    getline(cin, s);
    int n = s.size();
    vll d0(1002,0);
    vll d1(1002,0);
    d0[0] = 1;
    for(auto x : s) {
        vll nd0(1002,0);
        vll nd1(1002,0);
        forn(i,0,1001) {
            if(x == '1') {
                nd1[i] += d0[i] + d1[i];
                nd1[i+1] += d1[i];
                nd0[i+1] += d0[i];
            }
            else {
                nd1[i] += d1[i];
                nd0[i] += d0[i];
                nd1[i+1] += d1[i];
            }
        }
        d0 = nd0;
        d1 = nd1;
        forn(i,0,1002) {
            d0[i] %=mod;d1[i] %=mod;
        }
    }
    int k;
    scanf("%d", &k);
    ll ans = 0;
    forn(i,1,1001) {
        if(cnt[i] == k-1) {
            ans += d0[i] + d1[i];
        }
    }
    if(k==1) ans += mod-1;
    if(k==0) ans = 1;
    cout<<ans%mod;
    
    
    
}