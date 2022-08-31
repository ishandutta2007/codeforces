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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
int a[64][64];
ld p[6][64];
ld me[6][64];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    int num = 1<<n;
    forn(i,0,num) forn(j,0,num) read(a[i][j]);
    forn(i,0,num) {
        p[0][i] = ld(a[i][i^1])/100;
        me[0][i] = p[0][i];
    }
    forn(l,1,n) {
        forn(i,0,num) {
            int brs = 1<<l;
            int bracket = i - i%(1<<l);
            int br2 = bracket ^ (1<<l);
            me[l][i] = 0;
            forn(j,0,brs) {
                p[l][i] += p[l-1][i]*p[l-1][br2+j]*ld(a[i][br2+j])/100;
                me[l][i] = max(me[l][i], me[l-1][br2+j]);
            }
            me[l][i] += me[l-1][i] + p[l][i]*brs;
        }
    }
    ld ans = 0;
    forn(i,0,num) ans = max(ans, me[n-1][i]);
    printf("%.15lf", (double)ans);
    
}