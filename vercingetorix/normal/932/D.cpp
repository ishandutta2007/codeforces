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
#ifdef LOCAL
const int L = 5;
const int N = 20;
#else
const int L = 19;
const int N = 400500;
#endif
int to[L][N];
ll sum[L][N];
int w[N];
int cnt = 1;
const ll INF = 1e18;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int qn;
    read(qn);
    forn(l,1,L) sum[l][0] = INF;
    forn(l,0,L) to[l][0] = -1;
    ll last = 0;
    while(qn--) {
        int tp;
        ll p,q;
        scanf("%d %lld %lld", &tp, &p, &q);
        p^=last;
        q^=last;
        if(tp == 1) {
            int r = p-1;
            int v = cnt++;
            w[v] = q;
            for(int i = L-1; i>=0; i--) {
                if(to[i][r] != -1 && w[to[i][r]] < w[v]) {
                    r = to[i][r];
                }
            }
            if(w[r] < w[v]) r = to[0][r];
            to[0][v] = r;
            sum[0][v] = w[v];
            forn(l,1,L) {
                if(to[l-1][v] == -1) {
                    sum[l][v] = INF;
                    to[l][v] = -1;
                }
                else {
                    sum[l][v] = sum[l-1][v] + sum[l-1][to[l-1][v]];
                    to[l][v] = to[l-1][to[l-1][v]];
                }
            }
        }
        else {
            ll x = q;
            int v = p-1;
            int ans = 0;
            for(int i = L-1; i>=0; i--) {
                if(sum[i][v] <= x) {
                    x-=sum[i][v];
                    v = to[i][v];
                    ans += 1<<i;
                    if(v == -1) break;
                }
            }
            printf("%d\n", ans);
            last = ans;
        }
    }
    
    
    
}