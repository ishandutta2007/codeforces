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
const int N = 5000;
int d[N][N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    forn(i,0,n) d[i][i] = a[i];
    forn(len,2,n+1) {
        forn(s,0,n+1-len) {
            int e = s + len-1;
            d[s][e] = d[s][e-1]^d[s+1][e];
        }
    }
    forn(len,2,n+1) {
        forn(s,0,n+1-len) {
            int e = s + len-1;
            d[s][e] = max(d[s][e], max(d[s][e-1],d[s+1][e]));
        }
    }
    int q;
    read(q);
    while(q--) {
        int l,r;
        scanf("%d %d", &l, &r);
        l--; r--;
        printf("%d\n", d[l][r]);
    }
    
    
}