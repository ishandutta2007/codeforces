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

const int A = 82;
int d[A][A][A*A/2+A];
const int INF = 1e9;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    a.pb(1);
    vi pos;
    n++;
    int n1 = 0;
    forn(i,0,n) n1 += a[i];
    forn(i,0,n) if(a[i] == 1) pos.pb(i);
    forn(i,0,n+1) forn(j,0,n+1) forn(k,0,A*A/2) d[i][j][k] = -INF;
    d[0][0][0] = 0;
    forn(i,0,n+1) forn(j,0,min(i+1, n1)) forn(k,0,n*(n-1)/2+1) {
        if(d[i][j][k] == -INF) continue;
        int z = i - j;
        int nw = -1;
        forn(nx,i+1,n+1) {
            nw++;
            d[nx][j+1][k + abs(nx - 1 - pos[j])] = max(d[nx][j+1][k + abs(nx-1 - pos[j])], d[i][j][k] + nw*z);
        }
    }
    n--;
    vi ans(n*(n-1)/2+1);

    forn(i,0,n*(n-1)/2+1) {
        if(i>0) d[n+1][n1][i] = max(d[n+1][n1][i], d[n+1][n1][i-1]);
        printf("%d ", d[n+1][n1][i]);
    }
    
    
}