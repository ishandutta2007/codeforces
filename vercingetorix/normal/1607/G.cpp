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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d", &n, &m);
        ll ab = 0;
        vi e;
        vpi ans(n, mp(0,0));
        forn(i,0,n) {
            int a,b;
            scanf("%d %d", &a, &b);
            ab += a;
            ab -= b;
            int l = m;
            if(m>b) {
                l -= (m-b);
                ab -= (m-b);
                ans[i].first += m-b;
            }
            if(m>a) {
                l -= m-a;
                ab += m-a;
                ans[i].second += m-a;
            }
            e.pb(l);
        }
        forn(i,0,n) {
            int l = e[i];
            if(ab >= 0) {
                ll tk = min(ll(l),ab);
                ans[i].first += tk;
                l -= tk;
                ab -= tk;
            }
            if(ab < 0) {
                ll tk = min(ll(l),-ab);
                ans[i].second += tk;
                l -= tk;
                ab += tk;
            }
            ans[i].first += l/2;
            ans[i].second += l/2 + l%2;
            ab+=l%2;
        }
        printf("%lld\n", abs(ab));
        forn(i,0,n) printf("%d %d\n", ans[i].first, ans[i].second);
    }
    
    
}