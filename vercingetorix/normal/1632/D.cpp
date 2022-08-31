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
int d[18][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    forn(i,0,n) scanf("%d", &d[0][i]);
    forn(l,1,18) {
        forn(i,(1<<l)-1,n) {
            d[l][i] = gcd(d[l-1][i], d[l-1][i-(1<<(l-1))]);
        }
    }
    int last = -1;
    int ans = 0;
    forn(r,0,n) {
        int cur = 0;
        int lf = r;
        while(lf > last) {
            cur = gcd(cur, d[0][lf]);
            lf--;
            int was = lf;
            for(int l = 17; l>=0; l--) {
                if(lf-last >= (1<<l) && cur!= 0 && d[l][lf] % cur == 0) {
                    lf -= (1<<l);
                }
            }
            if(r-was <= cur && r - lf >= cur) {
                last = r;
                ans++;
                break;
            }
        }
        printf("%d ", ans);
    }
    
    
}