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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    char c[100000];
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);
        vvi a(2);
        vvi b(2);
        forn(i,0,n) {
            int x;
            scanf("%d", &x);
            if(x > 0) a[0].pb(x);
            else a[1].pb(-x);
        }
        forn(i,0,m) {
            int x;
            scanf("%d", &x);
            if(x > 0) b[0].pb(x);
            else b[1].pb(-x);
        }
        srt(b[1]);
        srt(a[1]);
        int ans = 0;
        forn(k,0,2) {
            int g = 0;
            int add = 0;
            for(int i = int(b[k].size()) - 1; i>=0; i--) {
                auto it = lower_bound(all(a[k]), b[k][i] + 1);
                int l = it - a[k].begin();
                it = lower_bound(all(b[k]), b[k][i] - l + 1);
                int cand = b[k].begin() + i - it + 1 + g;
                add = max(cand, add);
                it = lower_bound(all(a[k]), b[k][i]);
                if(it != a[k].end() && *it == b[k][i]) g++;
            }
            ans += add;
        }
        printf("%d\n", ans);
        
    }
    
    
}