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

int d[3000][3000];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        vvi col(n);
        forn(i,0,n) a[i]--;
        forn(i,0,n) col[a[i]].pb(i);
        forn(i,0,n) forn(j,i+1,n) d[i][j] = n;
        forn(i,0,n) forn(j,0,i+1) d[i][j] = 0;
        forn(l,2,n+1) {
            forn(s,0,n-l+1) {
                int e = s + l - 1;
                d[s][e] = min(d[s][e], d[s][e-1] + 1);
                for(auto f : col[a[e]]) {
                    if(f > e) break;
                    if(f < s) continue;
                    if(f == s) {
                        d[s][e] = d[s+1][e];
                        break;
                    }
                    int cand = d[s][f-1] + 1 + d[f][e];
                    d[s][e] = min(d[s][e], cand);
                }
            }
        }
        printf("%d\n", d[0][n-1]);
    }
    
    
    
}