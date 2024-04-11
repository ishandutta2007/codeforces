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
const int A = 200500;

int l[2][A];
int r[2][A];
const int INF = 1e9;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        cin>>n;
        vs a(2);
        forn(i,0,2) cin>>a[i];
        forn(i,0,n) {
            l[0][i] = INF;
            l[1][i] = INF;
            r[0][i] = INF;
            r[1][i] = INF;
        }
        l[0][0] = 0;
        l[1][0] = 0;
        r[0][n-1] = 0;
        r[1][n-1] = 0;
        forn(i,0,n) {
            l[0][i] = min(l[0][i], l[1][i] + 1);
            l[1][i] = min(l[1][i], l[0][i] + 1);
            if(i == n-1) break;
            int op = min(l[0][i], l[1][i]);
            if(a[0][i] == '.' && a[1][i] == '.') {
                if(l[0][i] == 0) {
                    l[0][i+1] = 0;
                    l[1][i+1] = 0;
                }
                else {
                    l[0][i+1] = l[0][i] + 1;
                    l[1][i+1] = l[1][i] + 1;
                }
            }
            else if(a[0][i] == '*' && a[1][i] == '*') {
                l[0][i+1] = op+2;
                l[1][i+1] = op+2;
            }
            else {
                forn(f,0,2) if(a[f][i] == '*') {
                    l[f][i+1] = l[f][i] + 1;
                    l[1-f][i+1] = op + 2;
                }
            }
        }
        for(int i = n-1; i>=0; i--) {
            r[0][i] = min(r[0][i], r[1][i] + 1);
            r[1][i] = min(r[1][i], r[0][i] + 1);
            if(i == 0) break;
            int op = min(r[0][i], r[1][i]);
            if(a[0][i] == '.' && a[1][i] == '.') {
                if(r[0][i] == 0) {
                    r[0][i-1] = 0;
                    r[1][i-1] = 0;
                }
                else {
                    r[0][i-1] = r[0][i] + 1;
                    r[1][i-1] = r[1][i] + 1;
                }
            }
            else if(a[0][i] == '*' && a[1][i] == '*') {
                r[0][i-1] = op+2;
                r[1][i-1] = op+2;
            }
            else {
                forn(f,0,2) if(a[f][i] == '*') {
                    r[f][i-1] = r[f][i] + 1;
                    r[1-f][i-1] = op + 2;
                }
            }
        }
        int ans = 2*n;
        forn(m,0,n) {
            int opl = min(l[0][m], l[1][m]);
            int opr = min(r[0][m], r[1][m]);
            ans = min(ans, opl + opr + 1);
            forn(f,0,2) if(a[1-f][m] == '.') ans = min(ans, l[f][m] + r[f][m]);
        }
        printf("%d\n", ans);
    }
    
    
}