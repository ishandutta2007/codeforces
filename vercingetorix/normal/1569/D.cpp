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
    read(t);
    forn(ifa,0,t) {
        int n,m,k;
        scanf("%d %d %d", &n,&m,&k);
        readv(x,n);
        readv(y,m);
        vi badx(n,0);
        vi bady(m,0);
        vector<map<int, int>> bx(n);
        vector<map<int, int>> by(m);
        ll ans = 0;
        forn(i,0,k) {
            int a,b;
            scanf("%d %d", &a, &b);
            auto it1 = lower_bound(all(x), a);
            auto it2 = lower_bound(all(y), b);
            int posx = it1-x.begin();
            int posy = it2-y.begin();
            if(*it1 != a) {
                ans += badx[posx]++;
                ans -= bx[posx][posy] ++;
            }
            if(*it2 != b) {
                ans += bady[posy]++;
                ans -= by[posy][posx] ++;
            }
        }
        printf("%lld\n", ans);
        
    }
    
    
}