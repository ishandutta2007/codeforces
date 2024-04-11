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

bool can[200000001];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(a,n);
    can[0] = true;
    int q;
    read(q);
    readv(b,q);
    vi ans(q,k+1);
    forn(j,0,k+1) {
        forn(it,0,q) {
            forn(tk,1,k+1-j) forn(i,0,n) {
                int lef = b[it] - tk * a[i];
                if(lef >= 0 && can[lef]) ans[it] = min(ans[it], j + tk);
            }
        }
        if(j==k) break;
        forn(i,0,n) can[a[i]*(j+1)] = true;
    }
    forn(i,0,q) if(can[b[i]]) ans[i] = min(ans[i], k);
    forn(i,0,q) {
        if(ans[i] == k+1) ans[i] = -1;
        printf("%d\n", ans[i]);
    }
//    while(q--) {
//        int x;
//        scanf("%d", &x);
//        int ans = k+1;
//        forn(i,0,n) {
//            forn(tk,1,k+1) {
//                int lef = x - tk*a[i];
//                if(lef == 0) ans = min(ans, tk);
//                else if(lef > 0 && can[lef]) {
//                    forn(j,i+1,n) {
//                        if(lef%a[j] == 0) ans = min(ans, lef/a[j] + tk);
//                    }
//                }
//            }
//        }
//
//        if(ans == k+1) ans = -1;
//        printf("%d\n", ans);
//    }
    
}