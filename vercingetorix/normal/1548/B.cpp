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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n,r;
        scanf("%d", &n);
        vll a(n);
        forn(i,0,n) scanf("%lld", &a[i]);
        vll d;
        forn(i,0,n-1) d.pb(abs(a[i]-a[i+1]));
        int can = 0;
        for(auto x : d) if(x>1) can = 1;
        if(can == 0) {
            printf("1\n");
            continue;
        }
        int dstack = 1;
        while(1) {
            vll nd;
            can = 0;
            forn(i,dstack, d.size()) {
                nd.pb(gcd(d[i-dstack], d[i]));
                if(nd.back() > 1) can = 1;
            }
            if(can) {
                dstack *= 2;
                d = nd;
            }
            else break;
        }
        int curimp = 0;
        int m = d.size();
        forn(i,0,m) {
            while(i+curimp+1 < m && gcd(d[i], d[i+curimp+1]) > 1) {
                curimp++;
            }
        }
        printf("%d\n", dstack+curimp+1);
    }
    
}