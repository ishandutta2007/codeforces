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
bitset<700> d[700][700];
int tor[700][700];
int tol[700][700];
bool gc[700][700];

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    forn(i,0,n) forn(j,0,n) if(gcd(a[i], a[j]) > 1) gc[i][j] = true;
    forn(i,0,n) d[i][i][i] = 1;
    forn(len, 1, n+1) {
        forn(l,0,n+1-len) {
            int r = l + len-1;
            forn(h,l,r+1) {
                int canl = 1;
                int canr = 1;
                if(h>l) canl = tor[l][h-1];
                if(h<r) canr = tol[h+1][r];
                if(canl && canr) {
                    d[l][r][h] = 1;
                    if(l>0 && gc[l-1][h]) tol[l][r] = 1;
                    if(r<n-1 && gc[h][r+1]) tor[l][r] = 1;
                }
            }
        }
    }
    forn(h,0,n) if(d[0][n-1][h]) {
        cout<<"Yes";
        exit(0);
    }
    cout<<"No";
    
    
}