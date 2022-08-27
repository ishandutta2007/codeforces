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

const int A = 2010;
ll d[2*A][A];
ll s[2*A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[A];
    forn(ifa,0,ta) {
        int n;
        scanf("%d\n", &n);
        scanf("%s", c);
        string a(c);
        scanf("%s", c);
        string b(c);
        forn(j,0,2*n+1) forn(i,0,n+1) d[j][i] = 0;
        forn(j,0,2*n+1) forn(i,0,n+1) s[j][i] = 0;
        d[n][0] = 1;
        forn(i,0,n) {
            forn(k,0,2*n+1) {
                d[k][i] %= mod;
                s[k][i] %= mod;
                forn(as,0,2) forn(bs,0,2) {
                    if(a[i]!='?' && a[i]-'0'!=as) continue;
                    if(b[i]!='?' && b[i]-'0'!=bs) continue;
                    int dif = k - n + as - bs;
                    if(abs(dif)>n) continue;
                    d[n-dif][i+1] += d[k][i];
                    s[n-dif][i+1] += s[k][i];
                    s[n-dif][i+1] += d[k][i]*abs(dif);
                }
            }
        }
        printf("%lld\n", s[n][n]%mod);
    }
    
    
}