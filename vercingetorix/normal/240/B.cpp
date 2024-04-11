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
int d[201][40001];
int main()
{
//#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
//#endif
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    readv(h,n);
    const int INF = 1e9;
    forn(i,0,n+1) forn(j,0,n*200+1) d[i][j] = INF;
    d[0][0] = 0;
    int sum = 0;
    int last = 0;
    forn(i,0,n) {
        forn(was,0,sum+1) {
            d[i+1][was + h[i]] = min(d[i+1][was+h[i]], d[i][was]);
            d[i+1][sum-was+h[i]] = min(d[i+1][sum-was+h[i]], d[i][was] + min(last,h[i]));
        }
        last = h[i];
        sum += last;
    }
    int best = INF;
    forn(i,0,n*200+1) {
        if(i<=a && sum-i<=b) best = min(best, d[n][i]);
        if(i<=b && sum-i<=a) best = min(best, d[n][i]);
    }
    if(best == INF) best = -1;
    cout<<best;
    
}