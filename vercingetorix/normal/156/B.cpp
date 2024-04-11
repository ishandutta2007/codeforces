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
    int n,m;
    scanf("%d %d\n", &n, &m);
    char c;
    int k;
    vi a(n,0);
    vi b(n,0);
    int neg = 0;
    vi ans;
    forn(i,0,n) {
        scanf("%c%d\n", &c, &k);
        --k;
        if(c == '-') {
            neg++;
            b[k]++;
            ans.pb(-k-1);
        }
        else {
            a[k]++;
            ans.pb(k+1);
        }
        
    }
    vi can(n,0);
    int cnum = 0;
    forn(i,0,n) {
        if(a[i] + neg-b[i] == m) {
            can[i] = 1;
            cnum++;
        }
    }
    forn(i,0,n) {
        int k = abs(ans[i]) - 1;
        if(ans[i] > 0) {
            if(can[k]) {
                if(cnum == 1) printf("Truth\n");
                else printf("Not defined\n");
            }
            else printf("Lie\n");
        }
        else {
            if(can[k] == 0) printf("Truth\n");
            else {
                if(cnum == 1) printf("Lie\n");
                else printf("Not defined\n");
            }
        }
    }
    
    
}