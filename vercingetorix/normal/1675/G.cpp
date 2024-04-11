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

const int A =255;
int d[A][A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(a,n);
    reverse(all(a));
    const int INF = 1e9;
    forn(i,0,A) forn(j,0,A) forn(k,0,A) d[i][j][k] = INF;
    d[0][0][0] = 0;
    int sum = 0;
    forn(pos,0,n) {
        sum += a[pos];
        forn(sumwas,0,m+1) {
            if(sumwas * n > m*pos) break;
            forn(last,0,sumwas+1) {
                if(last * pos < sumwas) continue;
                forn(nxt,last,m+1) {
                    if(nxt + sumwas > m) break;
                    d[pos+1][nxt][sumwas+nxt] = min(d[pos+1][nxt][sumwas+nxt], d[pos][last][sumwas] + abs(sumwas+nxt-sum));
                }
            }
        }
    }
    int ans = INF;
    forn(last,0,m+1) ans =min(ans,d[n][last][m]);
    cout<<ans;
    
    
}