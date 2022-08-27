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

const int N = 200500;
int d[26][N];
pi p[26][N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    char c[200500];
    scanf("%s", c);
    string s(c);
    vvi ans;
    forn(i,0,n) {
        int best = -1;
        forn(j,0,ans.size()) if(s[ans[j].back()] <= s[i] && (best == -1 || s[ans[best].back()] < s[ans[j].back()])) best = j;
        if(best == -1) ans.pb(vi(1,i));
        else ans[best].pb(i);
    }
    printf("%d\n", ans.size());
    vi col(n,-1);
    forn(i,0,ans.size()) {
        for(auto j : ans[i]) col[j] = i+1;
    }
        for(auto x : col) printf("%d ", x);
//    vi ind[26];
//    forn(i,0,n) ind[s[i]-'a'].pb(i);
//    int ans = 1;

//    while(1) {
//        int stop = 1;
//        int last = -1;
//        forn(i,0,26) {
//            if(!ind[i].empty()) {
//                if(ind[i][0] > last) {
//                    last = ind[i].back();
//                    for(auto x : ind[i]) col[x] = ans;
//                    ind[i].clear();
//                    stop = 0;
//                }
//            }
//        }
//        if(stop) break;
//        else ans++;
//    }
//    printf("%d\n", ans-1);
//    for(auto x : col) printf("%d ", x);
//    if(ans < 3) {
//        printf("YES\n");
//        for(auto x : col) printf("%d", x-1);
//    }
//    else printf("NO\n");
//    printf("%d\n", ans-1);
    
//    forn(i,0,n) {
//        forn(j,0,26) d[j][i+1] = 26;
//        int cur = s[i]-'a';
//        forn(j,0,26) {
//            int k = d[j][i];
//            if(cur >= j) {
//                if(d[cur][i+1] > k) {
//                    d[cur][i+1] = k;
//                    p[cur][i+1] = mp(1, j);
//                }
//            }
//            if(cur >= k) {
//                if(d[j][i+1] > cur) {
//                    d[j][i+1] = cur;
//                    p[j][i+1] = mp(2, j);
//                }
//            }
//        }
//    }
//    forn(e,0,26) {
//        if(d[e][n] < 26) {
//
//        }
//    }
//    cout<<
    
    
}