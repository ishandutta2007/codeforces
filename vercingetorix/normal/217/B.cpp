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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, r;
    cin>>n>>r;
    vi best;
    const int INF = 1e9;
    int num = INF;
    forn(r2,1,r+1) {
        int a = r;
        int b = r2;
        vi ord;
        forn(i,0,n-1) {
            if(a>=b) {
                ord.pb(0);
                a-=b;
            }
            else {
                ord.pb(1);
                b-=a;
            }
            if(a==0) break;
        }
        if(a!=1 || b!=1) continue;
        int cand = 0;
        forn(i,1,n-1) if(ord[i] == ord[i-1]) cand++;
        if(cand >= num) continue;
        if(!ord.empty() && ord.back() == 0) {
            forn(i,0,n-1) ord[i] ^= 1;
        }
        ord.pb(0);
        reverse(all(ord));
        num = cand;
        best = ord;
    }
    if(num == INF) printf("IMPOSSIBLE\n");
    else {
        printf("%d\n", num);
        forn(i,0,n) {
            if(best[i]) printf("B");
            else printf("T");
        }
        printf("\n");
    }
    
    
}