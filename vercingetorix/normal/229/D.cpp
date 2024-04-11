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

const int A = 5001;

int d[A][A];
const int INF = 1e9;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(h,n);
    forn(i,0,n+1) forn(j,0,n+1) d[i][j] = INF;
    d[0][0] = 0;
    forn(l,0,n) {
        vi a;
        for(int i = l; i>=0; i--) {
            d[l][i] = min(d[l][i], d[l][i+1]);
            a.pb(d[l][i]);
        }
        reverse(all(a));
        int sum = 0;
        vi b;
        forn(r,l,n) {
            sum += h[r];
            b.pb(sum);
        }
//        reverse(all(b));
        int was = l;
        for(int r = n-1; r>=l; r--) {
            while(!a.empty() && a.back() > b.back()) {
                a.pop_back();
                was--;
            }
            if(a.empty()) break;
            d[r+1][was + 1] = min(d[r+1][was + 1], b.back());
            b.pop_back();
        }
    }
    int num = n;
    while(d[n][num] == INF) num--;
    cout<<n-num;
    
    
}