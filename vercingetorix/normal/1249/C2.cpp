#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        ll n;
        scanf("%lld", &n);
        ll wn = n;
        vi d;
        while(n > 0) {
            d.pb(n%3);
            n/=3;
        }
        int pt = d.size() - 1;
        while(pt>=0 && d[pt] < 2) pt--;
        if(pt == -1) {
            printf("%lld\n", wn);
            continue;
        }
        forn(i,0,pt+1) d[i] = 0;
        int carry = 1;
        forn(i,pt+1,d.size()) {
            d[i]+=carry;
            carry = 0;
            if(d[i] > 1) {
                d[i] = 0;
                carry = 1;
            }
        }
        if(carry) d.pb(1);
        ll ans = 0;
        while(!d.empty()) {
            ans = ans*3 + d.back();
            d.pop_back();
        }
        printf("%lld\n", ans);
        
    }
    
    
}