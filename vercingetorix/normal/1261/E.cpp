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
    int n;
    read(n);
    readv(a,n);
    vi p[1001];
    forn(i,0,n) p[a[i]].pb(i);
    vpi q;
    forn(i,0,n) q.pb(mp(a[i], i));
    vs ans(n+1, string(n, '0'));
    int pt = 0;
    srtrev(q);
//    forn(i,0,n) {
    for(auto x : q) {
        int i = x.second;
        forn(j,0,a[i]) {
            ans[(pt + j)%(n+1)][i] = '1';
        }
        pt++;
    }
//    forn(k,1,n+1) {
//        if(p[k].size() == 0) continue;
//        else if(p[k].size() == 1) {
//            int ind = p[k][0];
//            forn(i,pt,pt+k) ans[i][ind] = '1';
//            pt++;
//        }
//        else {
//            forn(i,0,p[k].size()) {
//                int ind = p[k][i];
//            }
//        }
//    }
    while(ans.back() == string(n, '0')) ans.pop_back();
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%s\n", x.c_str());
    
    
}