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
    // PRIMES
    const int N = 1000000;
    //int mindiv[N+1];
    vi mindiv(N+1, 0);
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        ll ans = 0;
        int n,e;
        scanf("%d %d", &n, &e);
        readv(a,n);
        
        forn(s,0,e) {
            vi b;
            for(int i = s; i < n; i += e) {
                if(a[i] == 1) b.pb(1);
                else if(isp[a[i]]) b.pb(2);
                else b.pb(0);
            }
            vi l1(b.size(), 0);
            int cur = 0;
            forn(i,0,b.size()) {
                l1[i] = cur;
                if(b[i] == 1) cur++;
                else cur = 0;
            }
            cur = 0;
            for(int i = (int)b.size() - 1; i>=0; i--) {
                if(b[i] == 2) {
                    ans += ll(cur+1) * (1+l1[i]) - 1;
                }
                if(b[i] == 1) cur++;
                else cur = 0;
            }
        }
        printf("%lld\n", ans);
    }
    
    
}