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

int d[41][41][41][41];
const int C  = 100;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[55];
    forn(ifa,0,ta) {
        int n,a,b;
        scanf("%d %d %d\n", &n, &a, &b);
        forn(k,0,n+1) forn(l,0,n+1) forn(r1,0,a) forn(r2,0,b) d[k][l][r1][r2] = -1;
        d[0][0][0][0] = 0;
        scanf("%s", c);
        forn(p,0,n) {
            int dig = c[p]-'0';
            forn(k,0,p+1) {
                int l = p-k;
                forn(r1,0,a) forn(r2,0,b) if(d[k][l][r1][r2] != -1) {
                    d[k+1][l][(r1*10+dig)%a][r2] = k*C*C*C + l*C*C + r1*C + r2;
                    d[k][l+1][r1][(r2*10+dig)%b] = k*C*C*C + l*C*C + r1*C + r2;
                }
            }
        }
        pi ans = mp(101,0);
        forn(k,1,n) {
            int l = n-k;
            if(d[k][l][0][0] != -1) {
                ans = min(ans, mp(abs(k-l), k));
            }
        }
        if(ans.first == 101) printf("-1\n");
        else {
            string res;
            int k = ans.second;
            int l = n-k;
            int r1 = 0;
            int r2 = 0;
            while(k+l > 0) {
                int wk = k;
                int ment = d[k][l][r1][r2];
                r2 = ment%C;
                ment/=C;
                r1 = ment%C;
                ment/=C;
                l = ment%C;
                ment/=C;
                k = ment;
                if(k < wk) res.pb('R');
                else res.pb('B');
            }
            reverse(all(res));
            printf("%s\n", res.c_str());
        }
    }
    
    
}