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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int d[5005][5002];
//int d[51][51];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    const int INF = 1e9;
    forn(i,0,n+1) forn(j,0,n+1) d[i][j] = INF;
    forn(j,0,n+1) d[0][j] = 0;
    int ft = 1;
    forn(i,0,n) {
        if(a[i] == 0) {
            if(i == 0) forn(j,0,n+1) d[i+1][j] = 0;
            else forn(j,0,n+1) d[i+1][j] = d[i][j];
        }
        else {
            forn(to,0,n) {
                if(a[to] == 0) d[i+1][to+1] = min(d[i+1][to+1], d[i][to] + abs(i-to));
                d[i+1][to+1] = min(d[i+1][to+1], d[i+1][to]);
            }
        }
        ft = 0;
    }
    cout<<d[n][n];
    
    
    
}