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

const long long mod = 998244353;
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    char c;
    vi a;
    forn(i,0,n) {
        scanf("\n%c", &c);
        a.pb(-1);
        if(c=='+') scanf(" %d", &a.back());
    }
    ll ans = 0;
    forn(l,0,n) {
        if(a[l] == -1) continue;
        vll d(n,0);
        d[0] = 1;
        forn(i,0,n) {
            if(i==l) continue;
            vll nd = d;
            if(a[i] == -1) {
                forn(j,0,n-1) nd[j] = (nd[j] + d[j+1]) % mod;
                if(i < l) nd[0] = (nd[0] + d[0]) % mod;
            }
            else {
                int smaller = 0;
                if(a[i] < a[l] or (a[i] == a[l] and i < l)) smaller = 1;
                if(smaller == 0) {
                    forn(j,0,n) nd[j] = (2*nd[j]) % mod;
                }
                else {
                    forn(j,1,n) nd[j] = (nd[j] + d[j-1]) % mod;
                }
            }
            d = nd;
        }
        ll sum = 0;
        forn(i,0,n) sum += d[i];
        sum %= mod;
        ans += ll(a[l]) * sum % mod;
    }
    cout<<ans % mod;
}