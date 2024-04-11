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
const int A = 10000010;
bool v[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 18000;
    vi mindiv(N+1, 0);
    vi pr;
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    int aa,bb,cc,dd;
    int n;
    scanf("%d %d %d %d %d", &n, &aa, &bb, &cc, &dd);
    int s = 0;
    unsigned int a = aa;
    unsigned int b = bb;
    unsigned int c = cc;
    unsigned int d = dd;
    unsigned ans = 0;
    while(s <= n) {
        forn(i,0,A) v[i] = 1;
        if(s == 0) v[0] = 0;
        if(s == 0) v[1] = 0;
        for(auto p : pr) {
            int fr = s/p*p;
            if(fr < s) fr+=p;
            if(fr == 0) fr += p;
            if(fr == p) fr += p;
            fr-=s;
            for(int i = fr; i < A; i+=p) v[i] = 0;
        }
        int mx = min(A-1,n-s);
        forn(i,0,mx+1) {
            if(v[i]) {
//                printf("%d\n", s+i);
                unsigned int p = s+i;
                ll dp = p;
                unsigned int deg = 0;
                while(dp <= n) {
                    deg+=n/dp;
                    dp*=p;
                }
                unsigned int val = a;
                val = val*p+b;
                val = val*p+c;
                val = val*p+d;
                ans += val*deg;
            }
        }
        s+=A;
    }
    cout<<ans;
    
    
}