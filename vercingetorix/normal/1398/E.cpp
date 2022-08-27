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
const int INF = 2e9;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int nn;
    read(nn);
    set<int> f, a;
    int nl = 0;
    int ns = 0;
    int mn = INF;
    ll sum2 = 0;
    ll sum = 0;
    while(nn--) {
        int tp;
        int d;
        scanf("%d %d", &tp, &d);
        sum += d;
        if(d > 0) {
            a.insert(d);
            if(tp == 0) f.insert(d);
            if(d > mn) {
                ns++;
                sum2 += d;
            }
            if(tp) nl++;
        }
        else {
            a.erase(-d);
            if(tp == 0) f.erase(-d);
            if(-d >= mn) {
                ns--;
                sum2 += d;
                if(-d == mn && ns > 0) {
                    auto it = a.lower_bound(-d);
                    mn = *it;
                }
                else if(ns == 0) mn = INF;
            }
            if(tp) nl--;
        }
        while(nl > ns) {
            auto it = a.lower_bound(mn);
            it--;
            sum2 += *it;
            mn = *it;
            ns++;
        }
        while(nl < ns) {
            if(nl == 0) {
                sum2 = 0;
                mn = INF;
                ns = 0;
            }
            else {
                auto it = a.find(mn);
                it++;
                sum2 -= mn;
                ns--;
                mn = *it;
            }
        }
        ll ans = sum + sum2;
        if(nl > 0) if(f.empty() || *f.rbegin() < mn) {
            ans -= mn;
            if(!f.empty()) ans += *f.rbegin();
        }
        printf("%lld\n", ans);
    }
}