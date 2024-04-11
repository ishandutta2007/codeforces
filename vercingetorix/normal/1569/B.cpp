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
    char c[100500];
    forn(ifa,0,t) {
        int n;
        scanf("%d\n", &n);
        scanf("%s", c);
        vi w;
        forn(i,0,n) if(c[i] == '2') w.pb(i);
        if(w.size() == 1 || w.size() == 2) {
            printf("NO\n");
            continue;
        }
        vs ans(n, string(n, '='));
        forn(i,0,n) ans[i][i] = 'X';
        if(w.size() >= 3) {
            forn(i,0,w.size()) {
                int j = (i+1)%w.size();
                ans[w[i]][w[j]] = '+';
                ans[w[j]][w[i]] = '-';
            }
        }
        printf("YES\n");
        forn(i,0,n) printf("%s\n", ans[i].c_str());
//        int bad = 1;
//        forn(i,0,n-1) {
//            if(c[i] != c[i+1]) {
//                printf("%d %d\n", i+1, i+2);
//                bad = 0;
//                break;
//            }
//        }
//        if(bad) printf("-1 -1\n");
    }
    
    
}