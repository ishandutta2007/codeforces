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

const int A = 1000500;
ll d2[A];
ll id2[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d2[0] = 1;
    id2[0] = 1;
    forn(i,1,A) {
        d2[i] = d2[i-1]*2%mod;
        id2[i] = id2[i-1]*(mod+1)/2%mod;
    }
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        vll p(n,0);
        vll suf(n+1,0);
        int need = (n+1)/2;
        p[n-1] = id2[need-1];
        suf[n-1] = id2[need-1];
        ll pleft = (mod + 1 - p[n-1])%mod;
        for(int cur = n-2; cur>=0; cur--) {
            int mn = min(2*cur+1, n);
            need = (cur+2)/2;
            ll pf = (mod + 1 - suf[mn])*id2[need]%mod;
            p[cur] = pf;
            suf[cur] = (pf + suf[cur+1])%mod;
        }
        forn(i,0,n) printf("%lld\n", p[i]);
        
    }
    
    
}