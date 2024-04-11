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
    int n;
    scanf("%d\n", &n);
    char c[200500];
    scanf("%s", c);
    string a(c);
    scanf("%s", c);
    string b(c);
    vvll rlen(26, vll(n+1,0));
    for(int i = n-1; i>=0; i--) {
        forn(j,0,26) rlen[j][i] = rlen[j][i+1];
        rlen[b[i]-'A'][i] += n-i;
    }
    vvll llen(26, vll(n+1,0));
    forn(i,0,n) {
        forn(j,0,26) llen[j][i+1] = llen[j][i];
        llen[b[i]-'A'][i+1] += i+1;
    }
    __int128 ans = 0;
    forn(i,0,n) {
        ans += rlen[a[i]-'A'][i] * (i+1);
        ans += llen[a[i]-'A'][i] * (n-i);
    }
    ll tot = 0;
    forn(i,1,n+1) tot += ll(i)*i;
    printf("%.10lf", (double)ans / tot);
}