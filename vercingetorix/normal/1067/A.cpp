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

const long long mod = 998244353 ;
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
    int n;
    read(n);
    readv(a,n);
    vvll d(2, vll(201,0));
    d[1][0] = 1;
    forn(i,0,n) {
        vvll nd(2, vll(201, 0));
        vvll pref(2, vll(201, 0));
        pref[0][0] = d[0][0];
        pref[1][0] = d[1][0];
        forn(it,0,2) forn(i,1,201) pref[it][i] = pref[it][i-1] + d[it][i];
        if(a[i] > 0) {
            forn(prev,0,201) {
                if(prev < a[i]) nd[0][a[i]] = nd[0][a[i]] + d[0][prev] + d[1][prev];
                else {
                    nd[1][a[i]] = nd[1][a[i]] + d[1][prev];
                    if(prev == a[i]) nd[1][a[i]] += d[0][prev];
                }
            }
        }
        else {
            forn(cur,1,201) {
                nd[0][cur] = pref[0][cur-1] + pref[1][cur-1];
                nd[1][cur] = pref[1][200] - pref[1][cur-1] + d[0][cur];
//                forn(prev,0,201) {
//                    if(prev < cur) nd[0][cur] = nd[0][cur] + d[0][prev] + d[1][prev];
//                    else {
//                        nd[1][cur] = nd[1][cur] + d[1][prev];
//                        if(prev == cur) nd[1][cur] += d[0][prev];
//                    }
//                }
            }
        }
        forn(it,0,2) forn(i,0,201) d[it][i] = nd[it][i] % mod;
    }
    ll ans = 0;
    forn(i,1,201) ans += d[1][i];
    cout<<ans%mod;
    
}