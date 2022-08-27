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
    char c[105015];
    while(t--) {
        int n,m,k;
        scanf("%d %d %d\n", &n, &m, &k);
        vs a;
        forn(i,0,n) {
            scanf("%s", c);
            a.pb(string (c));
        }
        vvi del(n, vi(m,0));
        forn(i,k,n) forn(j,0,m) {
            if(j < k || j+k>=m) continue;
            int can = 1;
            if(a[i][j] == '.') can = 0;
            forn(s,1,k+1) if(a[i-s][j-s] == '.' || a[i-s][j+s] == '.') can = 0;
            if(can == 0) continue;
            del[i][j] = 1;
            forn(s,1,k+1) {
                del[i-s][j-s] = 1;
                del[i-s][j+s] = 1;
            }
            int s = k+1;
            while(i-s >= 0 && j-s>=0 && j+s<m && a[i-s][j-s] =='*' && a[i-s][j+s]=='*') {
                del[i-s][j-s] = 1;
                del[i-s][j+s] = 1;
                s++;
            }
        }
        int can = 1;
        forn(i,0,n) forn(j,0,m) if(a[i][j]=='*' && del[i][j] ==0) can = 0;
        if(can) printf("YES\n");
        else printf("NO\n");
    }
    
    
}